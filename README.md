## TripWire

An Arduino sketch to count the number of times an IR tripwire is broken.

## Wiring Diagram

Coming soon

## Hardware

The build will consist of

* [Sparkfun Pro Micro](https://learn.sparkfun.com/tutorials/pro-micro--fio-v3-hookup-guide/hardware-overview-pro-micro) clone
* TEFD4300F [IR Photodiode + Darlington pair](http://www.instructables.com/id/Infrared-IR-tripwire-module/step2/How-it-works/)
* TSUS5202 IR LED
* Nokia 5110 type LCD screen (to display the trip count)

## Requirements

This sketch requires the following software and libraries:

* Arduino (tested with v1.6.1 OSX)
* [Sparkfun Arduino Addon Files](https://github.com/sparkfun/SF32u4_boards/archive/master.zip)
* [Arduino Makefile](https://github.com/sudar/Arduino-Makefile) (installed via homebrew)
* [Timer](https://github.com/JChristensen/Timer)
* picoterm for make monitor task (installed via homebrew)
