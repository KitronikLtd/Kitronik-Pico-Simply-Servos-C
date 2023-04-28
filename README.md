# Kitronik-Pico-Simply-Servos-C

A class and sample code to use the Kitronik Simply Servos board for Raspberry Pi Pico. (www.kitronik.co.uk/5339)

This is the C version. 

To use edit the `main.c` file, then build the project, and copy the `pico-simply-servos.uf2` file onto the Pico.

The `pico-simply-servos.uf2` file in the base of this repo is a piece of test code.

## Building main.c
- Edit `main.c` to include your code
- Edit the `CMakeLists.txt` to change the pico-sdk folder location
    - include(/path/to/your/pico-sdk/pico_sdk_init.cmake)
- Create a new folder called `build`
- In your terminal navigate to the `build` folder
- Execute the command ```cmake -DPICO_BOARD=pico .. && make```
- Your project file `pico-simply-servos.uf2` will now be available in the `build` folder

## Import SimplyServos.py and construct an instance:
```
#include "KitronikPicoSimplyServos.h"
initPicoSimplyServos();
```
This will initialise the PIO and set them to drive the servo pins.

## Drive a Servo by degrees:
```
servoGoToPosition(servo, degrees)
```
where:
* servo => 0 to 7
* degrees => 0 - 180

## Drive a Servo by pulse width:
```
servoGoToPeriod(servo, period)
```
where:
* servo => 0 to 7
* period => 500 - 2500 
	period is the pulse width in microseconds
