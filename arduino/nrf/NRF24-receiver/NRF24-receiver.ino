/*
* Arduino Wireless Communication Tutorial
*       Example 1 - Receiver Code
*                
* by Dejan Nedelkovski, www.HowToMechatronics.com
* 
* Library: TMRh20/RF24, https://github.com/tmrh20/RF24/
*/

#include <SPI.h>
//#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8); // CE, CSN

const byte address[6] = "00001";

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}

void loop() {
///  bool result = radio.isChipConnected ();

//Serial.println (result);
  if (radio.available()) {
  //  char text[32] = "";
  int num ;
    radio.read(&num, sizeof(num));
    //if (num ==123){
      Serial.print("data recived " );
      Serial.println(num);//}
  }
}
