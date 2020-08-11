//////////////////////////////
//////////////////////////////
//      TOZERO LEDSHIM
//////////////////////////////
//////////////////////////////

/***** Library Includes *****/
#include <Metro.h>
#include <FastLED.h>
#include <ToZero.h>

/***** Project Includes *****/
#include "LEDShim.h"

/***** Global Constants *****/
static const unsigned long RAINBOW_TIMER = 25;

/***** Global Variables *****/
Metro timer(RAINBOW_TIMER);
LEDShim shim;

uint16_t inc = 0;
uint16_t mode = 0;
uint16_t startHue = 0;


////////////////////////////////////////////////////////////////////////////////////////////////////
// SETUP
////////////////////////////////////////////////////////////////////////////////////////////////////
void setup()
{
  shim.Begin();
  shim.SetBrightness(64);
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
        fill_solid(shim.Pixels(), LEDShim::NUM_LEDS, CRGB::Black);
        shim.Show();
        delay(15);
      }
      else
      {
        fill_rainbow(shim.Pixels(), LEDShim::NUM_LEDS, startHue % 255, 4);  
        startHue += 1;
        shim.Show();
      }
    }
  }
  else
  {
    switch(mode)
    {
      case 0:
        shim.Pixels()[inc] = CRGB::Red;
        break;
      case 1:
        shim.Pixels()[inc] = CRGB::Green;
        break;
      case 2:
        shim.Pixels()[inc] = CRGB::Blue;
        break;
      case 3:
        shim.Pixels()[inc] = CRGB::White;
        break;
      case 4:
        shim.Pixels()[inc] = CRGB::Black;
        break;
      case 5:
        break;
    }
    inc++;
    if(inc >= LEDShim::NUM_LEDS)
    {
      inc = 0;
      mode++;
      if(mode == 5)
        timer.reset();
    }
    shim.Show();
    delay(30);
  }
}
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
