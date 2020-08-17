//////////////////////////////
//////////////////////////////
//      TOZERO BLINKT!
//////////////////////////////
//////////////////////////////

/***** Library Includes *****/
#include <Metro.h>
#include <FastLED.h>
#include <ToZero.h>

/***** Project Includes *****/
#include "Blinkt.h"

/***** Global Constants *****/
static const unsigned long RAINBOW_TIMER = 25;

/***** Global Variables *****/
Metro timer(RAINBOW_TIMER);
Blinkt blinkt;

uint16_t inc = 0;
uint16_t mode = 0;
uint16_t startHue = 0;


////////////////////////////////////////////////////////////////////////////////////////////////////
// SETUP
////////////////////////////////////////////////////////////////////////////////////////////////////
void setup()
{
  blinkt.SetBrightness(32);
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
      if(startHue >= 511)
      {
        startHue = 0;
        mode = 0;
        fill_solid(blinkt.Pixels(), Blinkt::NUM_LEDS, CRGB::Black);
        blinkt.Show();
        delay(15);
      }
      else
      {
        fill_rainbow(blinkt.Pixels(), Blinkt::NUM_LEDS, startHue % 255, 16);  
        startHue += 1;
        blinkt.Show();
      }
    }
  }
  else
  {
    switch(mode)
    {
      case 0:
        blinkt.Pixels()[inc] = CRGB::Red;
        break;
      case 1:
        blinkt.Pixels()[inc] = CRGB::Green;
        break;
      case 2:
        blinkt.Pixels()[inc] = CRGB::Blue;
        break;
      case 3:
        blinkt.Pixels()[inc] = CRGB::White;
        break;
      case 4:
        blinkt.Pixels()[inc] = CRGB::Black;
        break;
      case 5:
        break;
    }
    inc++;
    if(inc >= Blinkt::NUM_LEDS)
    {
      inc = 0;
      mode++;
      if(mode == 5)
        timer.reset();
    }
    blinkt.Show();
    delay(250);
  }
}
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
