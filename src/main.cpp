#include <Arduino.h>
#include <LiquidCrystal.h>
#include <DHT.h>

// put function declarations here:
int myFunction(int, int);

// LiquidCrystal(rs, enable, d4, d5, d6, d7)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#define DHT11_PIN 6
DHT dht(DHT11_PIN, DHT11);

// Global variables for DHT readings
float temperature = 0;
float humidity = 0;

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  dht.begin();
  lcd.print("Temp = " + String(temperature) + " C");
  lcd.setCursor(0, 1);
  lcd.print("Humid= " + String(humidity) + " %");
}

void loop() {
  // put your main code here, to run repeatedly:
  temperature = dht.readTemperature();
  humidity = dht.readHumidity();
  lcd.setCursor(6, 0);
  lcd.print(String(temperature));
  lcd.setCursor(6, 1);
  lcd.print(String(humidity));
  delay(2000);
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}