// Example_9_Computer_Interfacing
const int ledpin =13;
int seread;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(ledpin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  seread=0;

seread= Serial.read();
if(seread=="0"){digitalWrite(ledpin,LOW);}else{
digitalWrite(ledpin,seread);}
delay(1000);
}
