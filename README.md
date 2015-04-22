## TripWire

An Arduino sketch to count the number of times an IR tripwire is broken and display the count on an LCD screen.

## Wiring Diagram

![schematic](https://raw.githubusercontent.com/elandesign/TripWire/master/doc/schematic.png)

## Hardware

The build will consist of

* [Sparkfun Pro Micro](https://learn.sparkfun.com/tutorials/pro-micro--fio-v3-hookup-guide/hardware-overview-pro-micro) clone
* TEFD4300F [IR Photodiode + Darlington pair](http://www.instructables.com/id/Infrared-IR-tripwire-module/step2/How-it-works/)
* Nokia 5110 type LCD screen (to display the trip count)
* TSUS5202 IR LED (to provide the IR beam)

## Requirements

This sketch requires the following software and libraries:

* Arduino
* [Sparkfun Arduino Addon Files](https://github.com/sparkfun/SF32u4_boards/archive/master.zip)
* [Arduino Makefile](https://github.com/sudar/Arduino-Makefile) (included)
* [Timer](https://github.com/JChristensen/Timer)
* [Adafruit PCD8544 Nokia 5110 LCD Library](https://github.com/adafruit/Adafruit-PCD8544-Nokia-5110-LCD-library)
* [Adafruit GFX Library](https://github.com/adafruit/Adafruit-GFX-Library)
