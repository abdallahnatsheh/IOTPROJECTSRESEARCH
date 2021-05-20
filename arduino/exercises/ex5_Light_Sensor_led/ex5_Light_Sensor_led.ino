//Example_5_Light_Sensor_led
const int lightPin = A0;
const int ledPin = 9;
int lightLevel;
void setup() {
  // put your setup code here, to run once:
pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
lightLevel = analogRead(lightPin);
lightLevel = map(lightLevel, 0, 900, 0, 255);
lightLevel = constrain(lightLevel, 0, 255);
analogWrite(ledPin, lightLevel);
}
