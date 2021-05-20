//Example_ Variable_Resistor_sensor
const int sensorPin=A0;
const int ledPin=13;
int sensorVal;
void setup() {
  // put your setup code here, to run once:
pinMode(ledPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
sensorVal=analogRead(sensorPin);
digitalWrite(ledPin,HIGH);
delay(sensorVal);
digitalWrite(ledPin,LOW);
delay(sensorVal);
}
