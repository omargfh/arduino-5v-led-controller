#include <iostream>
#include <stdint.h>

#include "Util.hpp"

uint8_t clamp(uint8_t value, uint8_t min, uint8_t max) {
  if (value < min)
    return min;
  if (value > max)
    return max;
  return value;
}

uint8_t delta(uint8_t x, uint8_t y) { return (x > y) ? x - y : y - x; }

uint8_t step(uint8_t current, uint8_t target, uint8_t speed) {
  uint8_t result = current;
  if (delta(current, target) < speed)
    result = clamp(target, 0, 255);
  else if (current == target) {
  } else if (current < target)
    result = current + speed;
  else if (current > target)
    result = current - speed;

  return clamp(result, 0, 255);
}