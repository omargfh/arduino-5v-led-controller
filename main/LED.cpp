#include <stdint.h>
#include <iostream>

#include "Util.hpp" // clamp, delta, step
#include "LED.hpp" // Color

class Color {
public:
  uint8_t r, g, b;
  uint8_t brightness;
  uint8_t fadeSpeed;
  uint8_t blinkSpeed;
  uint8_t blinkLength;
  uint8_t delay;
  Color() {
    this->r = 0;
    this->g = 0;
    this->b = 0;
    this->brightness = 0;
    this->fadeSpeed = 0;
    this->blinkSpeed = 0;
    this->blinkLength = 0;
  }

  Color(uint64_t call) {
    this->r = (call & 0xFF00000000000000) >> 56;
    this->g = (call & 0x00FF000000000000) >> 48;
    this->b = (call & 0x0000FF0000000000) >> 40;
    this->brightness = (call & 0x000000FF00000000) >> 32;
    this->fadeSpeed = (call & 0x00000000FF000000) >> 24;
    this->blinkSpeed = (call & 0x0000000000F00000) >> 20;
    this->blinkLength = (call & 0x00000000000F0000) >> 16;
    this->delay = (call & 0x000000000000FF00) >> 8;
  }
  
  void read() {
    printf("\n::Read Color::\nrgb(%d,%d,%d)\nbrightness: %f\nfade speed:%d "
           "cycles\n",
           this->r, this->g, this->b, (double)this->brightness / 255,
           this->fadeSpeed);
    printf("blinkSpeed: %d\nblinkLength: %d cycles\n", this->blinkSpeed,
           this->blinkLength);
  }

  static Color Transition(Color current, Color target) {
    Color result = Color();
    result.r = step(current.r, target.r, target.fadeSpeed);
    result.g = step(current.g, target.g, target.fadeSpeed);
    result.b = step(current.b, target.b, target.fadeSpeed);
    result.brightness =
        step(current.brightness, target.brightness, target.fadeSpeed);
    result.fadeSpeed = target.fadeSpeed;
    result.blinkSpeed = target.blinkSpeed;
    result.blinkLength = clamp(current.blinkLength - 1, 0, 255); // Cycles
    result.delay = clamp(target.delay - 1, 0, 255);              // Cycles
    return result;
  }

  static bool Blinks(Color current, Color target) {
    // Blink on % BlinkLength === 0 if BlinkSpeed is higher than 0
    return target.blinkSpeed > 0 && target.blinkLength > 0 &&
           target.blinkLength % (255 - target.blinkSpeed) == 0;
  }

  static bool FadeComplete(Color current, Color target) {
    return current.r == target.r && current.g == target.g &&
           current.b == target.b && current.brightness == target.brightness;
  }
};