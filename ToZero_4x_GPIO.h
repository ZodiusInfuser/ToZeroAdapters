/*
ToZero_4x_GPIO.h - Library for use with the ToZero 4x adapter board that maps
the pinout of the Teensy family of microcontrollers (3.2, 3.5, 3.6, LC) to
the Raspberry Pi GPIO header

Copyright (c) 2020 Christopher (@ZodiusInfuser) Parrott. All right reserved.
*/

#ifndef _TO_ZERO_4X_GPIO_H
#define _TO_ZERO_4X_GPIO_H

//#define MAP_GPIO5_TO_SPECIAL
//#define MAP_GPIO6_TO_SPECIAL

//#define SWAP_GPIO16_TO_CE1
//#define SWAP_GPIO27_TO_GPIO26

#if defined(__IMXRT1062__)	//Teensy 4.0 & 4.1

	//----- INNER ROW -----
	//3V3
	#define GPIO_2		18	//PI SDA1
	#define GPIO_3		19	//PI SCL1
	#define GPIO_4		2		//PI 1-Wire
	//GND
	#define GPIO_17		17

#ifndef SWAP_GPIO27_TO_GPIO26
	#define GPIO_27		5	//On solder selector with GPIO27
#endif
	#define GPIO_22		16           
	//3V3
	#define GPIO_10		11	//PI SPI0 MOSI
	#define GPIO_9		12	//PI SPI0 MISO
	#define GPIO_11		13	//PI SPI0 SCK
	//GND

#if (defined(ARDUINO_TEENSY40) && !defined(NO_TEENSY_UNDERSIDE_PINS)) || defined(ARDUINO_TEENSY41)
	#define GPIO_0		25	//PI ID SD
#endif  

	//--------------------------------------------------
#if defined(MAP_GPIO5_TO_SPECIAL)
	#define GPIO_5		15
#else
	#if (defined(ARDUINO_TEENSY40) && !defined(NO_TEENSY_UNDERSIDE_PINS)) || defined(ARDUINO_TEENSY41)
		#define GPIO_5		36
	#else
		#if !defined(NO_TO_ZERO_WARNINGS)
			#warning "GPIO5 is not assigned to any Teensy pin."
		#endif
	#endif  
#endif
	//--------------------------------------------------
#if defined(MAP_GPIO6_TO_SPECIAL)
	#define GPIO_6		14
#else
	#if (defined(ARDUINO_TEENSY40) && !defined(NO_TEENSY_UNDERSIDE_PINS)) || defined(ARDUINO_TEENSY41)
		#define GPIO_6		37
	#else
		#if !defined(NO_TO_ZERO_WARNINGS)
			#warning "GPIO5 is not assigned to any Teensy pin."
		#endif
	#endif
#endif
	//--------------------------------------------------

	#define GPIO_13		22	//PI PWM1      
	#define GPIO_19		20	//PI PCM_LRCLK     

	//--------------------------------------------------
#ifdef SWAP_GPIO27_TO_GPIO26
	#define GPIO_26		5

	#if defined(ARDUINO_TEENSY40) && !defined(NO_TEENSY_UNDERSIDE_PINS)	//Teensy 4.0
		#error "GPIO27 is swapped with GPIO26, but an underside pin of the Teensy 4.0 may already be connected to GPIO26. If the underside pins are not connected, add #define NO_TEENSY_UNDERSIDE_PINS to the top of your main Arduino code file to remove this error. Otherwise, reset the relevant solder jumper on the ToZero board and remove #define SWAP_GPIO27_TO_GPIO26 from your code"
	
	#elif defined(ARDUINO_TEENSY41)	//Teensy 4.1
		#error "GPIO27 is swapped with GPIO26, but a side pin of the Teensy 4.1 is already connected to GPIO26. Reset the relevant solder jumper on the ToZero board and remove #define SWAP_GPIO27_TO_GPIO26 from your code"
	#endif
#else
	#if (defined(ARDUINO_TEENSY40) && !defined(NO_TEENSY_UNDERSIDE_PINS)) || defined(ARDUINO_TEENSY41)
		#define GPIO_26		33
	#endif
#endif
	//--------------------------------------------------

	//GND

	//----- OUTER ROW -----
	//5V
	//5V
	//GND
	#define GPIO_14		1	//PI UART0 TX         
	#define GPIO_15		0	//PI UART0 RX         
	#define GPIO_18		21	//PI PCM_BCLK          
	//GND
	#define GPIO_23		3         
	#define GPIO_24		4         
	//GND
	#define GPIO_25		23 //Was 6         
	#define GPIO_8		10	//PI SPI CE0 

	//--------------------------------------------------
#ifdef SWAP_GPIO16_TO_CE1
	#define GPIO_7		9	//PI SPI CE1

	#if defined(ARDUINO_TEENSY40) && !defined(NO_TEENSY_UNDERSIDE_PINS)	//Teensy 4.0
		#warning "GPIO16 is swapped with CE1 (GPIO7), but an underside pin of the Teensy 4.0 may already be connected to CE1.	If the underside pins are not connected, add #define NO_TEENSY_UNDERSIDE_PINS to the top of your main Arduino code file to remove this error. Otherwise, reset the relevant solder jumper on the ToZero board and remove #define SWAP_GPIO16_TO_CE1 from your code"

	#elif defined(ARDUINO_TEENSY41)	//Teensy 4.1
		#warning "GPIO16 is swapped with CE1 (GPIO7), but a side pin of the Teensy 4.1 is already connected to CE1. Reset the relevant solder jumper on the ToZero board and remove the #define SWAP_GPIO16_TO_CE1 from your code"
	#endif
#else
	#if (defined(ARDUINO_TEENSY40) && !defined(NO_TEENSY_UNDERSIDE_PINS)) || defined(ARDUINO_TEENSY41)
		#define GPIO_7		32	//PI SPI CE1
	#endif
#endif
	//--------------------------------------------------

#if (defined(ARDUINO_TEENSY40) && !defined(NO_TEENSY_UNDERSIDE_PINS)) || defined(ARDUINO_TEENSY41)
	#define GPIO_1		24	//PI ID SC                                
#endif
	//GND
	#define GPIO_12		6	//PI PWM0   //Was 23  
	//GND
#ifndef SWAP_GPIO16_TO_CE1
	#define GPIO_16		9	//On solder selector with CE1
#endif
	#define GPIO_20		8	//PI PCM_DIN
	#define GPIO_21		7	//PI PCM_DOUT


#elif !defined(_TO_ZERO_4X_H) && !defined(TOZERO_BOARD_ERROR)
	#define TOZERO_BOARD_ERROR
	#error "Incompatible Board Selected. The ToZero 4x adapter only supports the Teensy 4.0 & 4.1. If using a Teensy 3.2, 3.5, 3.6 or LC then a ToZero 3x adapter will be needed."
#endif

#endif