/*
ToZero_4x_Serial.h - Library for use with the ToZero 4x adapter board that maps
the pinout of the Teensy family of microcontrollers (3.2, 3.5, 3.6, LC) to
the Raspberry Pi GPIO header

Copyright (c) 2020 Christopher (@ZodiusInfuser) Parrott. All right reserved.
*/

#ifndef _TO_ZERO_4X_PWM_H
#define _TO_ZERO_4X_PWM_H

#include <ToZero_4x_GPIO.h>

#if defined(__IMXRT1062__)	//Teensy 4.0 & 4.1

	enum ToZero_4x_PWM
	{
		GPIO_PWM0 = GPIO_12,
		GPIO_PWM1 = GPIO_13,
		GPIO_WS2812_PWM = GPIO_18,
	};

	#define TO_ZERO_PWM_SETUP
	static inline void ToZero_PWM0_Setup(void)
	{
		pinMode(GPIO_PWM0, OUTPUT);
		digitalWriteFast(GPIO_PWM0, LOW);
	};

	static inline void ToZero_PWM1_Setup(void)
	{
		pinMode(GPIO_PWM1, OUTPUT);
		digitalWriteFast(GPIO_PWM1, LOW);
	};

#if !defined(NO_TO_ZERO_WARNINGS)
	#pragma message "ToZero 4x PWM loaded. Remember to call ToZero_PWM0_Setup(); and/or ToZero_PWM1_Setup(); in you Arduino setup() function."
#endif

#elif !defined(_TO_ZERO_4X_H) && !defined(TOZERO_BOARD_ERROR)
	#define TOZERO_BOARD_ERROR
	#error "Incompatible Board Selected. The ToZero 4x adapter only supports the Teensy 4.0 & 4.1. If using a Teensy 3.2, 3.5, 3.6 or LC then a ToZero 3x adapter will be needed."
#endif

#endif