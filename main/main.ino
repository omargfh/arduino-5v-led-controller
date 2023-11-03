#include <Arduino.h>
#include <stdint.h>

#include "ReadBytes.hpp"
#include "LED.hpp"
#include "LEDStrip.hpp"

Color current = Color();
Color target = Color();
void setup() {
  Serial.begin(115200);
  LEDStrip::Setup();
}

// We receive input as a series of little-endian
// bytes over the Serial port
void loop() {

  // Wait until we have 8 bytes to read
  if (Serial.available() != 8)
    return;

  // Read the 8 bytes into a uint64_t
  uint64_t call = read8ByteBuffer();

  // Get the color intended by the call
  target = Color(call);

  // Compute the next color according to the fade speed
  if (!Color::FadeCompleted(current, target)) {
    current = Color::Transition(current, target);
  }

  // Set the color of the LED strip
  // Blink if Blink condition is met
  if (Color::Blinks(current, target)) {
    LEDStrip::Blink(current, 50);
  } else {
    LEDStrip::SetColor(current);
  }

  // Wait 25ms before checking again
  delay(25);
}
