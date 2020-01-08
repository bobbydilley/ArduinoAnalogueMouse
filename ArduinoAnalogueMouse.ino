#include <HID.h>
#include <Wire.h>
#include <AbsMouse.h>

// Set which digital pin you've connected the trigger to here
int triggerPin = 5;

// This is the trigger state
int lastTriggerState = 0;

void setup() {
  // Init the abs mouse class and tell it the maximum values
  AbsMouse.init(1024, 1024);

  // Setup the trigger pin as an input
  pinMode(triggerPin, INPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // Read 2 analogue channels
  int xValue = analogRead(A0);
  int yValue = analogRead(A1);

  // Move the mouse to this point
  AbsMouse.move(xValue, yValue);

  // Check to see if we need to do a click
  int triggerState = digitalRead(triggerPin);
  if (triggerState != lastTriggerState) {
    if (triggerState == LOW) {
      AbsMouse.press(MOUSE_LEFT);
    } else {
      AbsMouse.release(MOUSE_LEFT);
    }
    delay(10);  // Unsure what this delay is for, but might need it.
  }

  delay(1);        // delay in between reads for stability
}
