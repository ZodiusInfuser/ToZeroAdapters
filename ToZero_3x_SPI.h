/*
ToZero_3x_SPI.h - Library for use with the ToZero 3x adapter board that maps
the pinout of the Teensy family of microcontrollers (3.2, 3.5, 3.6, LC) to
the Raspberry Pi GPIO header

Copyright (c) 2020 Christopher (@ZodiusInfuser) Parrott. All right reserved.
*/

#ifndef _TO_ZERO_3X_SPI_H
#define _TO_ZERO_3X_SPI_H

#include <ToZero_3x_GPIO.h>

#if defined(__MK20DX256__) || defined(__MKL26Z64__) || defined(__MK64FX512__) || defined(__MK66FX1M0__)  //Teensy 3.2, 3.5, 3.6 & LC

	#include <SPI.h>

	static SPIClass& GPIO_SPI = SPI;
#if defined(__MK64FX512__) || defined(__MK66FX1M0__) //Teensy 3.5 & 3.6
	static SPIClass& BreakoutSPI = SPI2;
#endif

	enum ToZero_3x_SPI
	{
		GPIO_SPI_MOSI = GPIO_10,
		GPIO_SPI_MISO = GPIO_9,
		GPIO_SPI_SCK = GPIO_11,
		GPIO_SPI_CE0 = GPIO_8,
	#ifdef GPIO7_ASSIGNED
		GPIO_SPI_CE1 = GPIO_7,
	#endif

	#if defined(__MK64FX512__) || defined(__MK66FX1M0__) //Teensy 3.5 & 3.6
		BREAKOUT_SPI_MOSI = 44,
		BREAKOUT_SPI_MISO = 45,
		BREAKOUT_SPI_SCK = 46,
		BREAKOUT_SPI_CE0 = 43,
	#endif
	};

	#define TO_ZERO_SPI_SETUP
	static inline void ToZero_SPI_Setup(void)
	{
		GPIO_SPI.setSCK(GPIO_SPI_SCK);
		GPIO_SPI.setMOSI(GPIO_SPI_MOSI);
	};

#if !defined(NO_TO_ZERO_WARNINGS) && !defined(_TO_ZERO_3X_H)
	#warning "ToZero 3x SPI loaded. Remember to call ToZero_SPI_Setup(); in you Arduino setup() function."
#endif

#elif !defined(_TO_ZERO_3X_H)
	#error "Incompatible Board Selected. The ToZero 3x adapter only supports the Teensy 3.2, 3.5, 3.6 & LC. If using a Teensy 4.0 or 4.1 then a ToZero 4x adapter will be needed."
#endif

#endif