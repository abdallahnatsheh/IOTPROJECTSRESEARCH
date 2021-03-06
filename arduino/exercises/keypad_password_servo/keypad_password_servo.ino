/* ==================================================================================
 File:      keypad_password_servo.ino 
 Author:	Camilo Nuñez Fernandez
                camilo.nunez@cnf.cl
 Description: A control access with password, 4x4 keypad and a servo, for Arduino.
 ==================================================================================
 //  Ver | dd mmm yyyy | Author  | Description
 // =====|=============|=========|=====================================================
 // 1.0 | 17 Jul 2012  |   CNF   | First release 
 // ==================================================================================
 // 1.1 | 12 Ago 2014  |   CNF   | Second Version, compatible with Arduino 1.0 
 // ==================================================================================*/

#include <Password.h> //http://playground.arduino.cc/uploads/Code/Password.zip use password library
#include <Keypad.h> //http://www.arduino.cc/playground/uploads/Code/Keypad.zip  //tells to use keypad library
#include <Servo.h> //tells to use servo library


Servo myservo; //declares servo
Password password = Password( "1234" ); //password to unlock box, can be changed

const byte ROWS = 4; // Four rows
const byte COLS = 4; // columns
// Define the Keymap
char keys[ROWS][COLS] = {
{'1','2','3','A'},
{'4','5','6','B'},
{'7','8','9','C'},
{'*','0','#','D'}
};
// Connect keypad ROW0, ROW1, ROW2 and ROW3 to these Arduino pins.
byte rowPins[ROWS] = { 2,3,4,5 };// Connect keypad COL0, COL1 and COL2 to these Arduino pins.
byte colPins[COLS] = { 6,7,8,9 };


// Create the Keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){
  Serial.begin(9600);
  Serial.write(254);
  Serial.write(0x01);
  delay(200); 
 // pinMode(11, OUTPUT);  //green light
  //pinMode(12, OUTPUT);  //red light
  myservo.attach(13); //servo on digital pin 9 //servo
  keypad.addEventListener(keypadEvent); //add an event listener for this keypad
  }

void loop(){
  keypad.getKey();
  myservo.write(0);
  }
  //take care of some special events
  void keypadEvent(KeypadEvent eKey){
  switch (keypad.getState()){
  case PRESSED:
  
  Serial.print("Enter: ");
  Serial.println(eKey);
  delay(10);
  
  Serial.write(254);
  
  switch (eKey){
    case 'A': checkPassword(); delay(1); break;
    
    case 'B': password.reset(); delay(1); break;
    
     default: password.append(eKey); delay(1);
}
}
}
void checkPassword(){
  
if (password.evaluate()){  //if password is right open box
    
    Serial.println("Accepted");
    Serial.write(254);delay(300);
    //Add code to run if it works
    myservo.write(80); //160deg
    
       // digitalWrite(11, HIGH);//turn on
    delay(5000); //wait 5 seconds
   // digitalWrite(11, LOW);// turn off
   password.reset();
    
    
}else{
    Serial.println("Denied"); //if passwords wrong keep box locked
    Serial.write(254);delay(10);
    //add code to run if it did not work
    myservo.write(0);
  //  digitalWrite(12, HIGH); //turn on
    delay(500); //wait 5 seconds
   // digitalWrite(12, LOW);//turn off*/
   password.reset();
    
}
}
