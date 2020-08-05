/*
ToZero.h - Library for use with the ToZero adapter board that maps
the pinout of the Teensy family of microcontrollers to
the Raspberry Pi GPIO header

Copyright (c) 2020 Christopher (@ZodiusInfuser) Parrott. All right reserved.
*/

#ifndef _TO_ZERO_H
#define _TO_ZERO_H

#if defined(__IMXRT1062__)	//Teensy 4x

	#include <ToZero_4x.h>
#else						//Teensy 3x
	#include <ToZero_3x.h>
#endif

#endif