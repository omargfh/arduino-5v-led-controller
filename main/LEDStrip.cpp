#include <Arduino.h>
#include "LED.hpp"
#include "LEDSTRIP.hpp"

class LEDStrip {
    public:
        static Setup() {
            pinMode(GREEN_LED, OUTPUT);
            pinMode(RED_LED, OUTPUT);
            pinMode(BLUE_LED, OUTPUT);
        }

        static SetColor(Color color) {
            analogWrite(GREEN_LED, color.green);
            analogWrite(RED_LED, color.red);
            analogWrite(BLUE_LED, color.blue);
        }

        static Blink(Color color, int delay) {
            SetColor(Color(0, 0, 0));
            delay(delay);
            SetColor(color);
        }
}