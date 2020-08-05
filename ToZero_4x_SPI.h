/*	
ToZero_4x_SPI.h - Library for use with the ToZero 4x adapter board that maps
the pinout of the Teensy family of microcontrollers (3.2, 3.5, 3.6, LC) to
the Raspberry Pi GPIO header

Copyright (c) 2020 Christopher (@ZodiusInfuser) Parrott. All right reserved.
*/

#ifndef _TO_ZERO_4X_SPI_H
#define _TO_ZERO_4X_SPI_H

#include <ToZero_4x_GPIO.h>

#if defined(__IMXRT1062__)	//Teensy 4.0 & 4.1

	#include <SPI.h>

	static SPIClass& GPIO_SPI = SPI;
#if (defined(ARDUINO_TEENSY40) && !defined(NO_TEENSY_UNDERSIDE_PINS)) || defined(ARDUINO_TEENSY41)
	static SPIClass& BreakoutSPI = SPI1;
#endif

	enum ToZero_4x_SPI
	{
		GPIO_SPI_MOSI = GPIO_10,
		GPIO_SPI_MISO = GPIO_9,
		GPIO_SPI_SCK = GPIO_11,
		GPIO_SPI_CE0 = GPIO_8,
	#ifdef GPIO7_ASSIGNED
		GPIO_SPI_CE1 = GPIO_7,
	#endif

	#if (defined(ARDUINO_TEENSY40) && !defined(NO_TEENSY_UNDERSIDE_PINS)) || defined(ARDUINO_TEENSY41)
		BREAKOUT_SPI_MOSI = 26,
		BREAKOUT_SPI_SCK = 27,
	#endif

	#if defined(ARDUINO_TEENSY40)
		BREAKOUT_SPI_MISO = 1,		
		BREAKOUT_SPI_CE0 = 0,
	#elif defined(ARDUINO_TEENSY41)
		BREAKOUT_SPI_MISO = 39,
		BREAKOUT_SPI_CE0 = 38,
	#endif
	};

	#define TO_ZERO_SPI_SETUP
	static inline void ToZero_SPI_Setup(void)
	{
	#if (defined(ARDUINO_TEENSY40) && !defined(NO_TEENSY_UNDERSIDE_PINS)) || defined(ARDUINO_TEENSY41)
		BreakoutSPI.setMISO(BREAKOUT_SPI_MISO);
		BreakoutSPI.setCS(BREAKOUT_SPI_CE0);
	#endif
	};

#if !defined(NO_TO_ZERO_WARNINGS)
	#pragma message "ToZero 4x SPI loaded. Remember to call ToZero_SPI_Setup(); in you Arduino setup() function."
#endif

#elif !defined(_TO_ZERO_4X_H) && !defined(TOZERO_BOARD_ERROR)
	#define TOZERO_BOARD_ERROR
	#error "Incompatible Board Selected. The ToZero 4x adapter only supports the Teensy 4.0 & 4.1. If using a Teensy 3.2, 3.5, 3.6 or LC then a ToZero 3x adapter will be needed."
#endif

#endif