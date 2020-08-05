/*
ToZero_3x_I2C.h - Library for use with the ToZero 3x adapter board that maps
the pinout of the Teensy family of microcontrollers (3.2, 3.5, 3.6, LC) to
the Raspberry Pi GPIO header

Copyright (c) 2020 Christopher (@ZodiusInfuser) Parrott. All right reserved.
*/

#ifndef _TO_ZERO_3X_I2C_H
#define _TO_ZERO_3X_I2C_H

#if defined(__MK20DX256__) || defined(__MKL26Z64__) || defined(__MK64FX512__) || defined(__MK66FX1M0__)  //Teensy 3.2, 3.5, 3.6 & LC
	#include <Wire.h>

	static TwoWire& GPIO_I2C = Wire;
#if defined(__MK20DX256__) || defined(__MK64FX512__) || defined(__MK66FX1M0__) //Teensy 3.2, 3.5 & 3.6
	static TwoWire& GPIO_ID = Wire1;
	static TwoWire& BreakoutI2C = Wire1;
#endif

#if defined(__MK64FX512__) || defined(__MK66FX1M0__) //Teensy 3.5 & 3.6
	static TwoWire& ExtraI2C = Wire2;
#endif

#elif !defined(_TO_ZERO_3X_H)
	#error "Incompatible Board Selected. The ToZero 3x adapter only supports the Teensy 3.2, 3.5, 3.6 & LC. If using a Teensy 4.0 or 4.1 then a ToZero 4x adapter will be needed."
#endif

#endif