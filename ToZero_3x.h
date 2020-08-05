/*
ToZero_3x.h - Library for use with the ToZero 3x adapter board that maps
the pinout of the Teensy family of microcontrollers (3.2, 3.5, 3.6, LC) to
the Raspberry Pi GPIO header

Copyright (c) 2020 Christopher (@ZodiusInfuser) Parrott. All right reserved.
*/

#ifndef _TO_ZERO_3X_H
#define _TO_ZERO_3X_H

#if defined(__MK20DX256__) || defined(__MKL26Z64__) || defined(__MK64FX512__) || defined(__MK66FX1M0__) //Teensy 3.2, 3.5, 3.6 & LC

	#include <ToZero_3x_GPIO.h>
	#include <ToZero_3x_Serial.h>
	#include <ToZero_3x_SPI.h>
	#include <ToZero_3x_I2C.h>
	#include <ToZero_3x_PWM.h>

	static inline void ToZero_Setup(void)
	{
		#ifdef TO_ZERO_SERIAL_SETUP
		ToZero_Serial_Setup();
		#endif	

		#ifdef TO_ZERO_SPI_SETUP
		ToZero_SPI_Setup();
		#endif	
	}

#if !defined(NO_TO_ZERO_WARNINGS)
	#warning "ToZero 3x loaded. Remember to call ToZero_Setup(); in you Arduino setup() function. (To remove this and all other ToZero warnings, add #define NO_TO_ZERO_WARNINGS to the top of your main Arduino code file)"
#endif

#else
	#error "Incompatible Board Selected. The ToZero 3x adapter only supports the Teensy 3.2, 3.5, 3.6 & LC. If using a Teensy 4.0 or 4.1 then a ToZero 4x adapter will be needed."
#endif

#endif