#include <Arduino.h>
#include <LiquidCrystal.h>
#include <DHT.h>

// put function declarations here:
int myFunction(int, int);

// LiquidCrystal(rs, enable, d4, d5, d6, d7)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// DHT sensor definitions
#define DHT11_PIN 6
DHT dht(DHT11_PIN, DHT11);

// Global variables for DHT readings
float temperature = 0;
float humidity = 0;

// RGB LED pin setup
const int redPin = 9;
const int greenPin = 8;
const int bluePin = 7;

// setColor function header
void setColor(int red, int green, int blue);

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  dht.begin();
  lcd.print("Temp = " + String(temperature) + " C");
  lcd.setCursor(0, 1);
  lcd.print("Humid= " + String(humidity) + " %");

  // Initialize RGB LED pins
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  temperature = dht.readTemperature();
  humidity = dht.readHumidity();
  lcd.setCursor(6, 0);
  lcd.print(String(temperature));
  lcd.setCursor(6, 1);
  lcd.print(String(humidity));

  // Simple RGB LED color cycling
  if (humidity < 30) {
    setColor(255, 15, 15); // Red
  } else if (humidity < 40) {
    setColor(255, 180, 15); // Yellow
  } else if (humidity < 45) {
    setColor(191, 120, 64); // 
  } else if (humidity < 50) {
    setColor(127, 60, 128); // Green
  } else if (humidity < 60) {
    setColor(63, 30, 192); // Blue
  } else {
    setColor(15, 15, 255); // Indigo
  }
  delay(1000);

}


void setColor(int red, int green, int blue) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}