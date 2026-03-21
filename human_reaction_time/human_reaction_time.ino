#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

const int btn = 2;
unsigned long startTime;
bool waiting = false;

void setup() {
  pinMode(btn, INPUT_PULLUP);
  lcd.init(); lcd.backlight();
  lcd.print("Wait for 'GO'!");
  delay(random(2000,5000));
  lcd.clear(); lcd.print("GO!");
  waiting = true;
  startTime = millis();
}

void loop() {
  if(waiting && digitalRead(btn)==LOW) {
    unsigned long reaction = millis() - startTime;
    lcd.clear();
    lcd.print("Time: ");
    lcd.print(reaction);
    lcd.print(" ms");
    waiting = false;
  }
}