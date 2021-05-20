
int counter1=0;
int counter2=0;
int sensor = 13;  // Digital pin D7
void setup() {
Serial.begin(9600);
  pinMode(sensor, INPUT);   // declare sensor as input

}
void loop() {

  long state = digitalRead(sensor);
    if(state == HIGH) {
     counter2=0;
      Serial.print("Motion detected! :");
      Serial.println(counter1);
      counter1++;
      delay(1000);
      
    }
    else {
    counter1=0;
      Serial.println("Motion absent!");
      Serial.println(counter2);
      counter2++;
      delay(1000);
      }
}
