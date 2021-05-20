#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup()
{
  // initialize the LCD
  lcd.begin(); // Init with pin default ESP8266 or ARDUINO
  // lcd.begin(0, 2); //ESP8266-01 I2C with pin 0-SDA 2-SCL
  // Turn on the blacklight and print a message.
  lcd.backlight();
  lcd.setCursor(0, 0);

#if defined(ESP8266)
  lcd.print("ESP8266");
#else
  lcd.print("ARDUINO");
#endif

  lcd.setCursor(0, 1);
  lcd.print("Hello, world!");
}

void loop()
{
  // Do nothing here...
}
