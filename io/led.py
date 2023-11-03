def trimHex(hex):
    if hex[0] == '#':
        return hex[1:]
    return hex

def hexToRGB(hex):
    hex = "#" + trimHex(hex)
    r, g, b = int(hex[1:3], 16), int(hex[3:5], 16), int(hex[5:7], 16)
    return r, g, b

def mask(value, bits = 8):
    return value & (2**bits - 1)

class LEDCommandBuilder():
    internal = 0
    def __init__(self):
        self.internal = 0

    def _set(self, value, pos, size):
        value = mask(value, size)
        self.internal = self.internal | (value << (64 - size - pos))
        return self

    def red(self, value):
        return self._set(value, 0, 8)

    def green(self, value):
        return self._set(value, 8, 8)

    def blue(self, value):
        return self._set(value, 16, 8)

    def brightness(self, value):
        return self._set(value, 24, 8)

    def fadeSpeed(self, value):
        return self._set(value, 32, 8)

    def blinkSpeed(self, value):
        return self._set(value, 40, 4)

    def blinkLength(self, value):
        return self._set(value, 44, 4)

    def delay(self, value):
        return self._set(value, 48, 8)

    def get(self):
        return self.internal

    def __str__(self):
        hex = f"{self.internal:0>10X}"
        return str(f"0x{hex}")

def hexToCommand(hex):
    r, g, b = hexToRGB(hex)
    return LEDCommandBuilder().red(r).green(g).blue(b).brightness(255).get()