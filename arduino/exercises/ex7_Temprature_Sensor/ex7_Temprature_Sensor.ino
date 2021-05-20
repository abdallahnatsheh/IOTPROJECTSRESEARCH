//// 7 Temprature_Sensor
int sensorPin=A0;
int reading;
float voltage;
float tempC;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
reading = analogRead(sensorPin);
voltage = reading * 5.0;
Serial.print(voltage);
Serial.println("volts ");
tempC=(voltage - 0.5)*100;
Serial.print(tempC);
Serial.println("degrees C");
delay(1000);
}
