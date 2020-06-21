#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 9, 8, 7, 6, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);
  lcd.print("Horizon Chaser~");
  Serial.begin(9600);
}

void loop() {
  lcd.setCursor(0, 1);
  if(Serial.available()) {
    lcd.print(Serial.readString());
  }
}
 