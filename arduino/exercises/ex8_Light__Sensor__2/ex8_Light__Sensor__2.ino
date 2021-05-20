// 8 Light _Sensor _2
const int  senspin = A0;
int sensread;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
sensread = analogRead(senspin);
Serial.print("sensor reading :");
Serial.println(sensread);
delay(1000);
}
