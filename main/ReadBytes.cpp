#include <Arduino.h>
#include "ReadBytes.hpp"

unsigned long long int read8ByteBuffer() {
    uint8_t bytes[8];
    unsigned long long int result;
    Serial.readBytes(bytes, 8);
    for (int i = 0; i < 8; i++) {
        result |= (static_cast<unsigned long long>(bytes[i]) << (8 * i));
    }
    return result;
}