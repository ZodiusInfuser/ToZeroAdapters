#ifndef _BLINKT_h
#define _BLINKT_h

/***** Includes *****/
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#if defined(__IMXRT1062__)
  #include <ToZero_4x_GPIO.h>
#else
  #include <ToZero_3x_GPIO.h>
#endif
#include <FastLED.h>

////////////////////////////////////////////////////////////////////////////////////////////////////
// Classes
////////////////////////////////////////////////////////////////////////////////////////////////////
class Blinkt
{
  //--------------------------------------------------
  // Constants
  //--------------------------------------------------
public:
  static const uint32_t NUM_LEDS = 8;
private:
  static const uint8_t DEFAULT_BRIGHTNESS = 64;
  static const uint8_t DATA_PIN = GPIO_23;
  static const uint8_t CLOCK_PIN = GPIO_24;


  //--------------------------------------------------
  // Constructors/Destructor
  //--------------------------------------------------
public:
  Blinkt(uint8_t brightness = DEFAULT_BRIGHTNESS);


  //--------------------------------------------------
  // Methods
  //--------------------------------------------------
public:
  CRGB(&Pixels())[NUM_LEDS];

  void SetBrightness(uint8_t brightness);

  void Show();


  //--------------------------------------------------
  // Variables
  //--------------------------------------------------
private:
  CRGB _pixels[NUM_LEDS];
  CLEDController& _controller;
  uint8_t _brightness;
};
#endif
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
