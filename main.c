/*
MIT License

Copyright (c) 2023 Kitronik Ltd 

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include "hardware/clocks.h"
#include "hardware/pio.h"

#include "pico/stdlib.h"

#include "servo.pio.h"

#include "KitronikPicoSimplyServos.h"

int main() {
    stdio_init_all();
    initPicoSimplyServos();

    while (true) {
        // Using servos
        for (int16_t d = 0; d <= 180; d++) {
            for (uint8_t s = 0; s < 8; s++) {
                servoGoToPosition(s, d);
            }
        }
        sleep_ms(1000);
        for (int16_t d = 180; d >= 0; d--) {
            for (uint8_t s = 0; s < 8; s++) {
                servoGoToPosition(s, d);
            }
        }
        sleep_ms(1000);
    }

    return 0;
}
