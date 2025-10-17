#include <Arduino.h>

const int redLed = 23;
const int yellowLed = 21;
const int greenLed = 5;

const int buttonPin = 2;

int lastButtonReading = HIGH; // last raw reading
const unsigned long DEBOUNCE_TIME = 50; // 50 ms
unsigned long lastDebounceTime = 0; // time of last state change

void setup() {
  Serial.begin(9600);
  pinMode(redLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  int reading = digitalRead(buttonPin);

  if (reading != lastButtonReading) {
    lastDebounceTime = millis();
  }

  digitalWrite(greenLed, LOW);
  digitalWrite(redLed, HIGH);
  delay(4000);
  digitalWrite(redLed, LOW);
  digitalWrite(yellowLed, HIGH);
  delay(1000);
  digitalWrite(yellowLed, LOW);
  digitalWrite(greenLed, HIGH);
  delay(2000);
}