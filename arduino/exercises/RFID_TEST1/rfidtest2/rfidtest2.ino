/* 
Created by Abdallah Ali Abdallah 
Modified to run on Arduino Uno 
based on (Arduino Mega + RDM630 RFID) code - which you can find it in the following link
http://maniacbug.wordpress.com/2011/10/09/125khz-rfid-module-rdm630/
http://arbitraryuser.com/2013/04/16/rdm630-125khz-rfid-reading-with-the-arduino-mega-2560-r3/

connect Tx Pin in RDM630 to DigitalPin (2) in arduino

*/


#include <SoftwareSerial.h>
#include <SPI.h>
#include <MFRC522.h>
#define SS_PIN 10
#define RST_PIN 9
//------------------------------------
//create a Serial object RFID
MFRC522 rfid(SS_PIN, RST_PIN); // Instance of the class

MFRC522::MIFARE_Key key;

uint8_t buffer[14];
uint8_t* buffer_at;
uint8_t* buffer_end = buffer + sizeof(buffer);
 
String checksum;
boolean tagfound = false;
 
void setup()
{
    Serial.begin(9600);
    Serial.println("Serial Ready");
 
    Serial.begin(9600);
    Serial.println("RFID Ready");
}
 
void loop()
{
    if (Serial.available()){
        delay(20);
        buffer_at = buffer;
 
        while ( buffer_at < buffer_end )
        {
            *buffer_at++ = Serial.read();
        }
        tagfound = true;
        Serial.end();
        Serial.begin(9600);
    }
 
    if (tagfound){
        buffer_at = buffer;
        uint32_t result = 0;
 
        // Skip the preamble
        ++buffer_at;
        // Accumulate the checksum, starting with the first value
        uint8_t checksum = rfid_get_next();
        // We are looking for 4 more values
        int i = 4;
        while(i--)
        {
            // Grab the next value
            uint8_t value = rfid_get_next();
            // Add it into the result
            result <<= 8;
            result |= value;
            // Xor it into the checksum
            checksum ^= value;
        }
        // Pull out the checksum from the data
        uint8_t data_checksum = rfid_get_next();
 
        // Print the result
        Serial.print("Tag: ");
        Serial.print(result);
        if ( checksum == data_checksum )
            Serial.println(" OK");
        else
            Serial.println(" CHECKSUM FAILED");
        // We're done processing, so there is no current value
 
        tagfound = false;
    }
 
}
 
uint8_t rfid_get_next(void)
{
    // sscanf needs a 2-byte space to put the result but we
    // only need one byte.
    uint16_t hexresult;
    // Working space to assemble each byte
    static char byte_chars[3];
    // Pull out one byte from this position in the stream
    snprintf(byte_chars,3,"%c%c",buffer_at[0],buffer_at[1]);
    sscanf(byte_chars,"%x",&hexresult);
    buffer_at += 2;
    return static_cast<uint8_t>(hexresult);
}
