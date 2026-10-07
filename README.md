
# Arduino LCD Lyrics Display

A simple embedded-systems project that uses an Arduino and character LCD to display song lyrics line-by-line. The lyrics are stored directly in the program and displayed according to a predefined timing sequence.

The project was developed in C and simulated using Proteus.

## Features

* Arduino-based LCD control
* 16×2 character LCD interface
* Lyrics stored in a dedicated header file
* Automated line-by-line lyric display
* Timing control using Arduino delays
* Proteus circuit simulation
* Modular LCD driver implementation


```

## Hardware

* Arduino
* 16×2 LCD
* Potentiometer for LCD contrast
* Connecting wires
* Power supply

## Software

* C
* Microchip Studio IDE / AVR toolchain
* Proteus Design Suite

## How It Works


The basic program flow is:

```text
Initialize Arduino
       ↓
Initialize LCD
       ↓
Load lyrics
       ↓
Display lyric line
       ↓
Wait for specified time
       ↓
Clear/update LCD
       ↓
Display next line
       ↓
Repeat
```

## Simulation

The circuit was designed and tested in Proteus before being deployed to the Arduino environment.

## Learning Objectives

This project demonstrates:

* Embedded C programming
* Microcontroller programming
* LCD interfacing
* Header/source file organization
* Basic timing and control logic
* Hardware simulation using Proteus

## Future Improvements

Possible improvements include:

* User-selectable songs
* External storage using an SD card
* Push-button song selection
* Adjustable lyric timing
* Scrolling text
* I²C LCD interface
* Real-time music synchronization

## Author

Developed as an embedded-systems / Arduino project.

