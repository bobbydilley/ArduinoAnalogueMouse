#include <HID.h>
#include <Wire.h>
#include <AbsMouse.h>

// Set which digital pin you've connected the trigger to here
int triggerPinLeft = 5;
int triggerPinMiddle = 6;
int triggerPinRight = 7;

// This is the trigger state
int lastTriggerStateLeft = 0;
int lastTriggerStateMiddle = 0;
int lastTriggerStateRight = 0;

void setup() {
  // Init the abs mouse class and tell it the maximum values
  AbsMouse.init(1024, 1024);

  // Setup the trigger pin as an input
  pinMode(triggerPinLeft, INPUT);
  pinMode(triggerPinMiddle, INPUT);
  pinMode(triggerPinRight, INPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // Read 2 analogue channels
  int xValue = analogRead(A0);
  int yValue = analogRead(A1);

  // Move the mouse to this point
  AbsMouse.move(xValue, yValue);

  // Check to see if we need to do a left click
  int triggerStateLeft = digitalRead(triggerPinLeft);
  if (triggerStateLeft != lastTriggerStateLeft) {
    if (triggerStateLeft == LOW) {
      AbsMouse.press(MOUSE_LEFT);
    } else {
      AbsMouse.release(MOUSE_LEFT);
    }
    delay(10);  // Unsure what this delay is for, but might need it.
  }
  lastTriggerStateLeft = triggerStateLeft;
  
  // Check to see if we need to do a middle click
  int triggerStateMiddle = digitalRead(triggerPinMiddle);
  if (triggerStateMiddle != lastTriggerStateMiddle) {
    if (triggerStateMiddle == LOW) {
      AbsMouse.press(MOUSE_MIDDLE);
    } else {
      AbsMouse.release(MOUSE_MIDDLE);
    }
    delay(10);  // Unsure what this delay is for, but might need it.
  }
  lastTriggerStateMiddle = triggerStateMiddle;
  
  // Check to see if we need to do a right click
  int triggerStateRight = digitalRead(triggerPinRight);
  if (triggerStateRight != lastTriggerStateRight) {
    if (triggerStateRight == LOW) {
      AbsMouse.press(MOUSE_RIGHT);
    } else {
      AbsMouse.release(MOUSE_RIGHT);
    }
    delay(10);  // Unsure what this delay is for, but might need it.
  }
  lastTriggerStateRight = triggerStateRight;

  delay(1);        // delay in between reads for stability
}
