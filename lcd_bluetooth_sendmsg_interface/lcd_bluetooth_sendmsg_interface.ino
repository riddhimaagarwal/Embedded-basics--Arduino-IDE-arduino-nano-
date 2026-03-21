/*
HC-05 Pin	      Arduino Nano
VCC	                5V
GND	                GND
TX	                D2
RX	                D3

I2C LCD Pin	    Arduino Nano
VCC	                5V
GND	                GND
SDA	                A4
SCL	                A5

Follow these steps:
1) Pair with HC-05 on your phone (PIN: 1234 or 0000)
2) Install a Bluetooth Terminal App:
3) Serial Bluetooth Terminal (Android)

*/
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>

// Initialize LCD: address 0x27, 16 columns, 2 rows
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Bluetooth on pins D2 (RX), D3 (TX)
SoftwareSerial BTSerial(2, 3); // RX, TX

String incomingMessage = "";

void setup() 
{
  lcd.init();           
  lcd.backlight();      

  BTSerial.begin(9600); // HC-05 default baud
  Serial.begin(9600);   // For debugging

  lcd.setCursor(0, 0);
  lcd.print("BT LCD Ready");
  lcd.setCursor(0, 1);
  lcd.print("Send Message");
}

void loop() 
{
  // Read from Bluetooth
  while (BTSerial.available()) 
  {
    char c = BTSerial.read();
    if (c == '\n') 
    {
      displayMessage(incomingMessage);
      incomingMessage = ""; // Clear buffer
    } 
    else 
    {
      incomingMessage += c;
    }
  }

  // Optional: read from Serial Monitor
  while (Serial.available()) 
  {
    char c = Serial.read();
    BTSerial.write(c);  // Send to BT device
  }
}

void displayMessage(String msg) 
{
  lcd.clear();
  lcd.setCursor(0, 0);

  if (msg.length() <= 16) 
  {
    lcd.print(msg);
  } 
  else 
  {
    // Scroll long message
    for (int i = 0; i <= msg.length() - 16; i++) 
    {
      lcd.setCursor(0, 0);
      lcd.print(msg.substring(i, i + 16));
      delay(300);
    }
  }
}
