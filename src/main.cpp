#include <Arduino.h>
#include <LiquidCrystal.h>


// put function declarations here:
int myFunction(int, int);

// LiquidCrystal(rs, enable, d4, d5, d6, d7)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // put your setup code here, to run once:
  int result = myFunction(2, 3);
  lcd.begin(16, 2);
  lcd.print("Temp : " + String(result) + " C");
  lcd.setCursor(0, 1);
  lcd.print("Humid: " + String(result + 10) + " %");
}

void loop() {
  // put your main code here, to run repeatedly:
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}