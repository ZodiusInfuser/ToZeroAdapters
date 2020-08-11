//////////////////////////////
//////////////////////////////
//    TOZERO UNICORNHATHD
//////////////////////////////
//////////////////////////////

/***** Library Includes *****/
#include <Metro.h>
#include <FastLED.h>
#include <ToZero.h>

/***** Project Includes *****/
#include "UnicornHD.h"

/***** Global Constants *****/
static const unsigned long RAINBOW_TIMER = 25;

/***** Global Variables *****/
Metro timer(RAINBOW_TIMER);
UnicornHD unicorn;

uint16_t inc = 0;
uint16_t mode = 0;
uint16_t startHue = 0;


////////////////////////////////////////////////////////////////////////////////////////////////////
// SETUP
////////////////////////////////////////////////////////////////////////////////////////////////////
void setup()
{
  unicorn.Begin();
  unicorn.SetBrightness(128);
}



////////////////////////////////////////////////////////////////////////////////////////////////////
// LOOP
////////////////////////////////////////////////////////////////////////////////////////////////////
void loop()
{
  if(mode == 5)
  {
    if(timer.check())
    {      
      if(startHue >= 255)
      {
        startHue = 0;
        mode = 0;
        fill_solid(unicorn.Pixels(), UnicornHD::NUM_LEDS, CRGB::Black);
        unicorn.Show();
        delay(15);
      }
      else
      {
        fill_rainbow(unicorn.Pixels(), UnicornHD::NUM_LEDS, startHue % 255, 1);  
        startHue += 1;
        unicorn.Show();
      }
    }
  }
  else
  {
    switch(mode)
    {
      case 0:
        unicorn.Pixels()[inc] = CRGB::Red;
        break;
      case 1:
        unicorn.Pixels()[inc] = CRGB::Green;
        break;
      case 2:
        unicorn.Pixels()[inc] = CRGB::Blue;
        break;
      case 3:
        unicorn.Pixels()[inc] = CRGB::White;
        break;
      case 4:
        unicorn.Pixels()[inc] = CRGB::Black;
        break;
      case 5:
        break;
    }
    inc++;
    if(inc >= UnicornHD::NUM_LEDS)
    {
      inc = 0;
      mode++;
      if(mode == 5)
        timer.reset();
    }
    unicorn.Show();
    delay(15);
  }
}
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
