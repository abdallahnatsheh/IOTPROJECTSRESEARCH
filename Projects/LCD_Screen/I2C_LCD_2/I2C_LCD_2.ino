#include  <Wire.h>
#include  <LiquidCrystal_I2C.h>
 
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
  // initialize LCD
   lcd.begin();
  Serial.begin(9600);
}

void loop()
{
   lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("abdallah");
  lcd.setCursor(0,1);
  lcd.print("wellcome");
  delay(1000);
  lcd.setBacklight(LOW);
  delay(1000);
}
