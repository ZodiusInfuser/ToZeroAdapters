#ifndef _UNICORN_MINI_h
#define _UNICORN_MINI_h

/***** Includes *****/
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

//Uncomment this if the underside pins of the teensy are not soldered
//#define NO_TEENSY_UNDERSIDE_PINS

//Uncomment these if you have changed the underside solder jumpers for GPIO5 and GPIO6
//#define MAP_GPIO5_TO_SPECIAL
//#define MAP_GPIO6_TO_SPECIAL

//Uncomment this if you have changed the underside solder jumper
//#define SWAP_GPIO16_TO_CE1

#if defined(__IMXRT1062__)
  #include <ToZero_4x_SPI.h>
#else
  #include <ToZero_3x_SPI.h>
#endif
#include <FastLED.h>


////////////////////////////////////////////////////////////////////////////////////////////////////
// Classes
////////////////////////////////////////////////////////////////////////////////////////////////////
class UnicornMini
{
  //--------------------------------------------------
  // Constants
  //--------------------------------------------------
public:
  static const uint32_t NUM_LEDS = 119;
  static const uint8_t ROWS = 7;
  static const uint8_t COLUMNS = 17;

#ifdef GPIO_5
  static const uint8_t BUTTON_A = GPIO_5;
#else
  #warning "BUTTON_A is not available (needs GPIO_5)."
#endif

#ifdef GPIO_6
  static const uint8_t BUTTON_B = GPIO_6;
#else
  #warning "BUTTON_B is not available (needs GPIO_6)."
#endif

#ifdef GPIO_16
  static const uint8_t BUTTON_X = GPIO_16;
#else
  #warning "BUTTON_X is not available (needs GPIO_16)."
#endif

#ifdef GPIO_20
  static const uint8_t BUTTON_Y = GPIO_20;
#else
  #warning "BUTTON_Y is not available (needs GPIO_20)."
  //Should always be available but included for completeness
#endif

private:
  static const uint8_t DEFAULT_BRIGHTNESS = 255;
  static const uint32_t SPI_DELAY = 1;//1000 / 120;

  static const uint8_t CMD_SOFT_RESET = 0xCC;
  static const uint8_t CMD_GLOBAL_BRIGHTNESS = 0x37;
  static const uint8_t CMD_COM_PIN_CTRL = 0x41;
  static const uint8_t CMD_ROW_PIN_CTRL = 0x42;
  static const uint8_t CMD_WRITE_DISPLAY = 0x80;
  static const uint8_t CMD_READ_DISPLAY = 0x81;
  static const uint8_t CMD_SYSTEM_CTRL = 0x35;
  static const uint8_t CMD_SCROLL_CTRL = 0x20;

  static const uint16_t _LUT[NUM_LEDS *3];


  //--------------------------------------------------
  // Constructors/Destructor
  //--------------------------------------------------
public:
  UnicornMini(uint8_t brightness = DEFAULT_BRIGHTNESS);


  //--------------------------------------------------
  // Methods
  //--------------------------------------------------
public:
  void Begin(void);
  CRGB(&Pixels())[NUM_LEDS];

  void SetBrightness(uint8_t brightness);

  void Show();  

  //--------------------------------------------------
private:
  void Initialise(uint8_t pinCE);


  //--------------------------------------------------
  // Variables
  //--------------------------------------------------
private:
  CRGB _pixels[NUM_LEDS];
  uint8_t _buffer[28*8*2];
  
  uint8_t _brightness;
};
#endif
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
