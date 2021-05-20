/*
* Arduino Wireless Communication Tutorial
*     Example 1 - Transmitter Code
*                
* by Dejan Nedelkovski, www.HowToMechatronics.com
* 
* Library: TMRh20/RF24, https://github.com/tmrh20/RF24/
*/

#include <SPI.h>
//#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8); // CE, CSN
int count =0;
const byte address[6] = "00001";

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}

void loop() {
 // bool result = radio.isChipConnected ();

//Serial.println (result);
//  const char text[] = "Hello World";
const int num = 123;
  radio.write(&num, sizeof(num));
  Serial.print("Data send : ");
   Serial.println(num);
   count++;
   Serial.println(count);
  //delay(1000);
}
