//simplyfie arduino ex1 : BLINKING LED
const int LED = 13;
void setup() {
  // put your setup code here, to run once:
pinMode(LED,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(LED,HIGH);//turnon
delay(100);//wait10sec
digitalWrite(LED, LOW);//turnoff
delay(100);
}
