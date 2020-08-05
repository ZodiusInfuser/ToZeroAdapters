/*
ToZero_4x_I2C.h - Library for use with the ToZero 4x adapter board that maps
the pinout of the Teensy family of microcontrollers (3.2, 3.5, 3.6, LC) to
the Raspberry Pi GPIO header

Copyright (c) 2020 Christopher (@ZodiusInfuser) Parrott. All right reserved.
*/

#ifndef _TO_ZERO_4X_I2C_H
#define _TO_ZERO_4X_I2C_H

#if defined(__IMXRT1062__)	//Teensy 4.0 & 4.1
	#include <Wire.h>

	static TwoWire& GPIO_I2C = Wire;
	static TwoWire& GPIO_ID = Wire2;
	static TwoWire& BreakoutI2C = Wire2;

#elif !defined(TOZERO_BOARD_ERROR)
	#define TOZERO_BOARD_ERROR
	#error "Incompatible Board Selected. The ToZero 4x adapter only supports the Teensy 4.0 & 4.1. If using a Teensy 3.2, 3.5, 3.6 or LC then a ToZero 3x adapter will be needed."
#endif

#endif