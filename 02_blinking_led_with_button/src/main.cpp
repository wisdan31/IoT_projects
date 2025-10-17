#include <Arduino.h>

const int buttonPin = 21;
const int ledPin = 23;
const unsigned long DEBOUNCE_TIME = 50; // 50 ms

int ledState = LOW;          // current LED state
int buttonState = HIGH;      // stable button state
int lastButtonReading = HIGH; // last raw reading
unsigned long lastDebounceTime = 0; // time of last state change

void changeLedState() {
  ledState = !ledState;             // toggle LED
  digitalWrite(ledPin, ledState);
  Serial.print("LED changed to ");
  Serial.println(ledState);
}

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int reading = digitalRead(buttonPin);

  // If the reading changed from last time, reset the debounce timer
  if (reading != lastButtonReading) {
    lastDebounceTime = millis();
  }

  // Only update the button state if the reading is stable for DEBOUNCE_TIME
  if ((millis() - lastDebounceTime) > DEBOUNCE_TIME) {
    if (reading != buttonState) {
      buttonState = reading;

      // Button pressed (INPUT_PULLUP: LOW = pressed)
      if (buttonState == LOW) {
        changeLedState();
      }
    }
  }

  lastButtonReading = reading;
}
