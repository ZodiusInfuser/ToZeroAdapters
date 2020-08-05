/*
ToZero_3x_GPIO.h - Library for use with the ToZero 3x adapter board that maps
the pinout of the Teensy family of microcontrollers (3.2, 3.5, 3.6, LC) to
the Raspberry Pi GPIO header

Copyright (c) 2020 Christopher (@ZodiusInfuser) Parrott. All right reserved.
*/

#ifndef _TO_ZERO_3X_GPIO_H
#define _TO_ZERO_3X_GPIO_H

//#ifdef MAP_GPIO5_TO_SPECIAL
//#ifdef MAP_GPIO6_TO_SPECIAL

//#ifdef SWAP_GPIO16_TO_CE1
//#ifdef SWAP_GPIO27_TO_GPIO26

#if defined(__MK20DX256__) || defined(__MKL26Z64__) || defined(__MK64FX512__) || defined(__MK66FX1M0__)	//Teensy 3.2, 3.5, 3.6 & LC

enum ToZero_3x_GPIO
	{
		//----- INNER ROW -----
		//3V3
		GPIO_2 = 18,	//PI SDA1
		GPIO_3 = 19,	//PI SCL1
		GPIO_4 = 2,		//PI 1-Wire
		//GND
		GPIO_17 = 8,

	#ifndef SWAP_GPIO27_TO_GPIO26
		GPIO_27 = 5,	//On solder selector with GPIO27
	#endif
		GPIO_22 = 16,           //Was 7
		//3V3
		GPIO_10 = 7,	//PI SPI0 MOSI //Was 11
		GPIO_9 = 12,	//PI SPI0 MISO
		GPIO_11 = 14,	//PI SPI0 SCK
		//GND

	#if defined(__MK20DX256__)	//Teensy 3.2
		GPIO_0 = 30,	//PI ID SD
	#elif defined(__MK64FX512__) || defined(__MK66FX1M0__)	//Teensy 3.5 & 3.6
		GPIO_0 = 38,	//PI ID SD
	#endif  

		//--------------------------------------------------
	#if defined(MAP_GPIO5_TO_SPECIAL)
		GPIO_5 = 3,
	#else
		#if defined(__MK20DX256__) && !defined(NO_TEENSY_UNDERSIDE_PINS)	//Teensy 3.2
			GPIO_5 = 24,
		#elif defined(__MK64FX512__) || defined(__MK66FX1M0__)	//Teensy 3.5 & 3.6
			GPIO_5 = 24,
		#else
			#if !defined(NO_TO_ZERO_WARNINGS)
				#warning "GPIO5 is not assigned to any Teensy pin."
			#endif
		#endif  
	#endif
		//--------------------------------------------------
	#if defined(MAP_GPIO6_TO_SPECIAL)
		GPIO_6 = 4,
	#else
		#if defined(__MK20DX256__) && !defined(NO_TEENSY_UNDERSIDE_PINS)	//Teensy 3.2
			GPIO_6 = 25,
		#elif defined(__MK64FX512__) || defined(__MK66FX1M0__)	//Teensy 3.5 & 3.6
			GPIO_6 = 25,
		#else
			#if !defined(NO_TO_ZERO_WARNINGS)
				#warning "GPIO5 is not assigned to any Teensy pin."
			#endif
		#endif
	#endif
		//--------------------------------------------------

		GPIO_13 = 6,	//PI PWM1      
		GPIO_19 = 23,	//PI PCM_LRCLK     

		//--------------------------------------------------
	#ifdef SWAP_GPIO27_TO_GPIO26
		GPIO_26 = 5,

		#if defined(__MK20DX256__) && !defined(NO_TEENSY_UNDERSIDE_PINS)	//Teensy 3.2
			#error "GPIO27 is swapped with GPIO26, but an underside pin of the Teensy 3.2 may already be connected to GPIO26. If the underside pins are not connected, add #define NO_TEENSY_UNDERSIDE_PINS to the top of your main Arduino code file to remove this error. Otherwise, reset the relevant solder jumper on the ToZero board and remove #define SWAP_GPIO27_TO_GPIO26 from your code"
		
		#elif defined(__MK64FX512__) || defined(__MK66FX1M0__)	//Teensy 3.5 & 3.6
			#error "GPIO27 is swapped with GPIO26, but a side pin of the Teensy 3.5/.6 is already connected to GPIO26. Reset the relevant solder jumper on the ToZero board and remove #define SWAP_GPIO27_TO_GPIO26 from your code"
		#endif
	#else
		#if defined(__MK20DX256__) && !defined(NO_TEENSY_UNDERSIDE_PINS)	//Teensy 3.2
			GPIO_26 = 33,
		#elif defined(__MK64FX512__) || defined(__MK66FX1M0__)	//Teensy 3.5 & 3.6
			GPIO_26 = 27,
		#endif
	#endif
		//--------------------------------------------------

		//GND

		//----- OUTER ROW -----
		//5V
		//5V
		//GND
		GPIO_14 = 1,	//PI UART0 TX         
		GPIO_15 = 0,	//PI UART0 RX         
		GPIO_18 = 9,	//PI PCM_BCLK          
		//GND
		GPIO_23 = 21,         
		GPIO_24 = 17,         
		//GND
		GPIO_25 = 11,         //Was 16
		GPIO_8 = 10,	//PI SPI CE0 

		//--------------------------------------------------
	#ifdef SWAP_GPIO16_TO_CE1
		GPIO_7 = 15,	//PI SPI CE1
		#define GPIO7_ASSIGNED

		#if defined(__MK20DX256__) && !defined(NO_TEENSY_UNDERSIDE_PINS)	//Teensy 3.2
			#warning "GPIO16 is swapped with CE1 (GPIO7), but an underside pin of the Teensy 3.2 may already be connected to CE1.	If the underside pins are not connected, add #define NO_TEENSY_UNDERSIDE_PINS to the top of your main Arduino code file to remove this error. Otherwise, reset the relevant solder jumper on the ToZero board and remove #define SWAP_GPIO16_TO_CE1 from your code"

		#elif defined(__MK64FX512__) || defined(__MK66FX1M0__)	//Teensy 3.5 & 3.6
			#warning "GPIO16 is swapped with CE1 (GPIO7), but a side pin of the Teensy 3.5/.6 is already connected to CE1. Reset the relevant solder jumper on the ToZero board and remove the #define SWAP_GPIO16_TO_CE1 from your code"
		#endif
	#else
		#if defined(__MK20DX256__) && !defined(NO_TEENSY_UNDERSIDE_PINS)	//Teensy 3.2
			GPIO_7 = 32,	//PI SPI CE1
			#define GPIO7_ASSIGNED
		#elif defined(__MK64FX512__) || defined(__MK66FX1M0__)	//Teensy 3.5 & 3.6
			GPIO_7 = 26,	//PI SPI CE1
			#define GPIO7_ASSIGNED
		#endif
	#endif
		//--------------------------------------------------

	#if defined(__MK20DX256__)      //Teensy 3.2
		GPIO_1 = 29,	//PI ID SC                  
	#elif defined(__MK64FX512__) || defined(__MK66FX1M0__)//Teensy 3.5 & 3.6
		GPIO_1 = 37,	//PI ID SC                   
	#endif
		//GND
		GPIO_12 = 20,	//PI PWM0    
		//GND
	#ifndef SWAP_GPIO16_TO_CE1
		GPIO_16 = 15,	//On solder selector with CE1
	#endif
		GPIO_20 = 13,	//PI PCM_DIN
		GPIO_21 = 22,	//PI PCM_DOUT
	};

#elif defined(__IMXRT1062__)

#if defined(ARDUINO_TEENSY40)
#elif defined(ARDUINO_TEENSY41)
#endif

#elif !defined(_TO_ZERO_3X_H)
	#error "Incompatible Board Selected. The ToZero 3x adapter only supports the Teensy 3.2, 3.5, 3.6 & LC. If using a Teensy 4.0 or 4.1 then a ToZero 4x adapter will be needed."
#endif

#endif