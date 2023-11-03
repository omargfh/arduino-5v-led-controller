#pragma once

#ifndef LED_HPP
#define LED_HPP

#include <iostream>
#include <stdint.h>

class Color {
public:
  uint8_t r, g, b;
  uint8_t brightness;
  uint8_t fadeSpeed;
  uint8_t blinkSpeed;
  uint8_t blinkLength;
  uint8_t delay;
  Color() {}

  // @Input: 64-bit integer (8 bytes)
  // R: 8 bits
  // G: 8 bits
  // B: 8 bits
  // Brightness: 8 bits
  // Fade Speed: 8 bits
  // Blink Speed: 4 bits
  // Blink Length: 4 bits
  // Delay: 8 bits
  // Padding: 8 bits

  // @Returns target Color value

  Color(uint64_t call) {}
  void read() {}
  static Color Transition(Color current, Color target) {}
  static bool Blinks(Color current, Color target) {}
  static bool FadeComplete(Color current, Color target) {}
};

#endif