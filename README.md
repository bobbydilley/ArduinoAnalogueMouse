# ArduinoAnalogueMouse

Takes in 2 analogue signals and a digital signal to emulate a mouse.

## Setup

You'll need to add the 'AbsMouse' library in the arduino interface.

To do this goto Tools -> Manage Libraries, then search for AbsMouse and click install.

## Devices

This will only work on devices that support HID such as Arduino Due, Zero or Teensys.

## Connection

This can be changed in the code but connect:

Analogue pin 0 - X Axis
Analogue pin 1 - Y Axis
Digital  pin 5 - Trigger
