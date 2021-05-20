#include <DHT.h>
const int LED = 13;
dht DHT;
int val;
#define DHT11_PIN 7

void setup(){
pinMode(LED,OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  
  int chk = DHT.read11(DHT11_PIN);
  int val=DHT.temperature;
    if(val>100){digitalWrite(LED,HIGH);}else{digitalWrite(LED, LOW);;}

  Serial.print("Temperature = ");
  Serial.println(DHT.temperature);
  Serial.print("Humidity = ");
  Serial.println(DHT.humidity);
  delay(1000);
}
