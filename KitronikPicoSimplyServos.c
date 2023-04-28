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

/*
*
Library for the Kitronik Simply Servos Board for Raspberry Pi Pico.
*
*/

uint8_t servoPins[NUM_SERVOS] = { 2, 3, 4, 5, 6, 7, 8, 9 };
PIO pios[NUM_SERVOS];
uint sms[NUM_SERVOS];
uint32_t pulse;

void servoGoToPosition(uint8_t servo, uint8_t degrees) {
    uint16_t period = (uint16_t) (degrees * degreesToUS) + 500;
    servoGoToPeriod(servo, period);
}

void servoGoToPeriod(uint8_t servo, uint16_t period) {
    if (period < minServoPulse) {
        period = minServoPulse;
    }
    if (period > maxServoPulse) {
        period = maxServoPulse;
    }
    pio_sm_put_blocking(pios[servo], sms[servo], period);
}

// Initialise all of the Kitronik Robotics Board components.
void initPicoSimplyServos() {
    for (uint8_t i = 0; i < NUM_SERVOS; i++) {
        pios[i] = pio0;
        sms[i] = pio_claim_unused_sm(pios[i], false);
        if (sms[i] == -1) {
            pios[i] = pio1;
            sms[i] = pio_claim_unused_sm(pios[i], false);
        }
        uint offset = pio_add_program(pios[i], &servo_program);
        servo_program_init(pios[i], sms[i], offset, servoPins[i], 64);

        pio_sm_set_enabled(pios[i], sms[i], false);
        pio_sm_put_blocking(pios[i], sms[i], pulseTrain);
        pio_sm_exec(pios[i], sms[i], pio_encode_pull(false, false));
        pio_sm_exec(pios[i], sms[i], pio_encode_mov(pio_isr, pio_osr));
        servoGoToPeriod(i, 1500);
        pio_sm_set_enabled(pios[i], sms[i], true);
    }
}
