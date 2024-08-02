#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define Mois A0 // Moisture sensor analog pin
#define RELAY_PIN 13 // Relay control pin

LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address 0x27, 16 columns, 2 rows

void setup() {
  Serial.begin(9600); // Initialize serial communication

  // Initialize LCD
  lcd.init();
  lcd.backlight();
  lcd.clear();

  // Initialize relay pin as output
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH); // Ensure the relay is initially off
}

void loop() {
  // Read moisture value
  int moistureValue = analogRead(Mois);

  // Calculate moisture percentage
  float moi