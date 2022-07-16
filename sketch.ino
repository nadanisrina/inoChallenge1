/*
  Photoresistor (LDR) Analog Demo

  Copyright (C) 2021 Uri Shaked.

  example : https://wokwi.com/arduino/projects/305193627138654786
*/

#include <LiquidCrystal_I2C.h>

#define LDR_PIN 2

// LDR Characteristics
const float GAMMA = 0.7;
const float RL10 = 50;

LiquidCrystal_I2C lcd(0x27, 20, 4);

void setup() {
  pinMode(LDR_PIN, INPUT);

  lcd.init();
  lcd.backlight();
}

void loop() {
  int analogValue = analogRead(A0);
  float voltage = analogValue / 1024. * 5;
  float resistance = 2000 * voltage / (1 - voltage / 5);
  float lux = pow(RL10 * 1e3 * pow(10, GAMMA) / resistance, (1 / GAMMA));

  lcd.setCursor(2, 0);
  lcd.println(lux);


  delay(100);
}
