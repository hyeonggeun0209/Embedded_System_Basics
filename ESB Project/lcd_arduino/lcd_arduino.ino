#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x3F, 20, 4);

void setup() {
  // put your setup code here, to run once:
  lcd.begin();
  lcd.backlight();
  lcd.print("Hello, Arduino!");
  lcd.setCursor(0, 1);
  lcd.print("Embedded Systems");
  delay(1000); lcd.clear();
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int j = 0; j < 4; j++) {
    for (int i = 0; i < 20; i++) {
      lcd.setCursor(i, j);
      lcd.print("X"); delay(10);
    }
  }

  for (int j = 3; j >= 0; j--) {
    for (int i = 19; i>= 0; i--) {
      lcd.setCursor(i, j);
      lcd.print("O"); delay(10);
    }
  }
}
