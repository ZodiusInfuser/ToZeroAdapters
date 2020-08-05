/*
ToZero_3x_Serial.h - Library for use with the ToZero 3x adapter board that maps
the pinout of the Teensy family of microcontrollers (3.2, 3.5, 3.6, LC) to
the Raspberry Pi GPIO header

Copyright (c) 2020 Christopher (@ZodiusInfuser) Parrott. All right reserved.
*/

#ifndef _TO_ZERO_3X_SERIAL_H
#define _TO_ZERO_3X_SERIAL_H

#if defined(__MK20DX256__) || defined(__MKL26Z64__) || defined(__MK64FX512__) || defined(__MK66FX1M0__)  //Teensy 3.2, 3.5, 3.6 & LC
	
	#include <HardwareSerial.h>

	static HardwareSerial& GPIO_Serial = Serial1;

#if defined(__MK20DX256__) //Teensy 3.2
	enum ToZero_3x_Serial
	{
		EXTRA_SERIAL_TX = 31,
		EXTRA_SERIAL_RX = 26,
	};

	static HardwareSerial& ExtraSerial = Serial2;

	#define TO_ZERO_SERIAL_SETUP
	static inline void ToZero_Serial_Setup(void)
	{
		ExtraSerial.setTX(EXTRA_SERIAL_TX);
		ExtraSerial.setRX(EXTRA_SERIAL_RX);
	};

#if !defined(NO_TO_ZERO_WARNINGS) && !defined(_TO_ZERO_3X_H)
	#warning "ToZero 3x Serial loaded. Remember to call ToZero_Serial_Setup(); in you Arduino setup() function."
#endif

#elif defined(__MK64FX512__) || defined(__MK66FX1M0__) //Teensy 3.5 & 3.6
	static HardwareSerial& ExtraSerial = Serial4;
	static HardwareSerial& ExtraSerial1 = Serial5;
	static HardwareSerial& ExtraSerial2 = Serial6;
#endif

#elif !defined(_TO_ZERO_3X_H)
	#error "Incompatible Board Selected. The ToZero 3x adapter only supports the Teensy 3.2, 3.5, 3.6 & LC. If using a Teensy 4.0 or 4.1 then a ToZero 4x adapter will be needed."
#endif

#endif