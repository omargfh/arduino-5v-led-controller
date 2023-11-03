#pragma once
#ifndef LEDSTRIP_HPP
#define LEDSTRIP_HPP

#include <Arduino.h>

#define RED_LED 6
#define BLUE_LED 5
#define GREEN_LED 9


class LEDStrip {
    public:
        static Setup() {}
        static SetColor(Color color) {}
        static Blink(Color color, int delay) {}
}

#endif