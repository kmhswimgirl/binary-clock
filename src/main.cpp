#include <Arduino.h>
#include <clock-display.h>

int pin = 2;

void setup() {
  // analog pin
  pinMode(pin, OUTPUT);

  //setting the other pins
  
}

void loop() {
  digitalWrite(pin, HIGH);
  delay(500);
  digitalWrite(pin, LOW);
  delay(500);
}
