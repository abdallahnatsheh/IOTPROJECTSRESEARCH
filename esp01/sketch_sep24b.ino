/*
Blink
Turns on an LED on for one tenth of a second
then off for one tenth of a second
then on for one tenth of a second
then off for one tenth of a second
then on for half a second
then off for half of a second
repeatedly.

This example code is in the public domain.
*/

// Pin 13 has an LED connected on most Arduino boards.
// Pin 11 has the LED on Teensy 2.0
// Pin 6 has the LED on Teensy++ 2.0
// Pin 13 has the LED on Teensy 3.0
// Pin 2 for the ESP8266-01 and I put the LED on the breadboard
// for this device with a resistor to not burn out the LED.
// give it a name:
int led = 2;

// the setup routine runs once when you press reset:
void setup() {
// initialize the digital pin as an output.
pinMode(led, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
digitalWrite(led, HIGH); // turn the LED on (HIGH is the voltage level)
delay(100); // wait for a 1/4 second
digitalWrite(led, LOW); // turn the LED off by making the voltage LOW
delay(300); // wait for a 1/4 second
digitalWrite(led, HIGH);
delay(100);
digitalWrite(led, LOW);
delay(300);
digitalWrite(led, HIGH);
delay(500);
digitalWrite(led, LOW);
delay(500);
}
