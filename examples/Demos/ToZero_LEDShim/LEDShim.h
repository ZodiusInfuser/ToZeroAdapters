#ifndef _LEDSHIM_h
#define _LEDSHIM_h

/***** Includes *****/
#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif
#include <FastLED.h>
#include <IS31FL3731.h>

////////////////////////////////////////////////////////////////////////////////////////////////////
// Classes
////////////////////////////////////////////////////////////////////////////////////////////////////
class LEDShim
{
  //--------------------------------------------------
  // Constants
  //--------------------------------------------------
public:
  static const uint32_t NUM_LEDS = 28;
private:
  static const uint8_t DEFAULT_BRIGHTNESS = 64;
  static const uint8_t I2C_ADDRESS = 0x75;


  //--------------------------------------------------
  // Constructors/Destructor
  //--------------------------------------------------
public:
  LEDShim(uint8_t brightness = DEFAULT_BRIGHTNESS);


  //--------------------------------------------------
  // Methods
  //--------------------------------------------------
public:
  void Begin();

  CRGB(&Pixels())[NUM_LEDS];

  void SetBrightness(uint8_t brightness);

  void Show();


  //--------------------------------------------------
  // Variables
  //--------------------------------------------------
private:
  IS31FL3731 _ledDriver;
  CRGB _pixels[NUM_LEDS];
  uint8_t _brightness;
};
#endif
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
