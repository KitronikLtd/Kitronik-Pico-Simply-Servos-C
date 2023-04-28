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

#ifndef KITRONIK_PICO_SIMPLY_SERVOS_H_
#define KITRONIK_PICO_SIMPLY_SERVOS_H_

#define NUM_SERVOS 8

// Servo 0 degrees -> pulse of 0.5ms, 180 degrees 2.5ms
// pulse train freq 50hz - 20mS
// 1uS is freq of 1000000
// servo pulses range from 500 to 2500usec and overall pulse train is 20000usec repeat.
// servo pins on the Simply Servos board are: GP2, GP3, GP4, GP5, GP6, GP7, GP8, GP9 for servos 1-8 in order
#define maxServoPulse 2500
#define minServoPulse 500
#define pulseTrain 20000
#define degreesToUS 2000 / 180

void servoGoToPosition(uint8_t servo, uint8_t degrees);
void servoGoToPeriod(uint8_t servo, uint16_t period);

void initPicoSimplyServos();

#endif // KITRONIK_PICO_SIMPLY_SERVOS_H_
