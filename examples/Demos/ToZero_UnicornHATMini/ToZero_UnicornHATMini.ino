//////////////////////////////
//////////////////////////////
//   TOZERO UNICORNHATMINI
//////////////////////////////
//////////////////////////////

/***** Library Includes *****/
#include <Metro.h>
#include <FastLED.h>
#include <ToZero.h>

/***** Project Includes *****/
#include "UnicornMini.h"

/***** Global Constants *****/
static const unsigned long RAINBOW_TIMER = 25;

/***** Global Variables *****/
Metro timer(RAINBOW_TIMER);
UnicornMini mini;

uint16_t inc = 0;
uint16_t mode = 0;
uint16_t startHue = 0;


////////////////////////////////////////////////////////////////////////////////////////////////////
// SETUP
////////////////////////////////////////////////////////////////////////////////////////////////////
void setup()
{
  mini.Begin();
  mini.SetBrightness(64);
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
        fill_solid(mini.Pixels(), UnicornMini::NUM_LEDS, CRGB::Black);
        mini.Show();
        delay(15);
      }
      else
      {
        fill_rainbow(mini.Pixels(), UnicornMini::NUM_LEDS, startHue % 255, 2);  
        startHue += 1;
        mini.Show();
      }
    }
  }
  else
  {
    switch(mode)
    {
      case 0:
        mini.Pixels()[inc] = CRGB::Red;
        break;
      case 1:
        mini.Pixels()[inc] = CRGB::Green;
        break;
      case 2:
        mini.Pixels()[inc] = CRGB::Blue;
        break;
      case 3:
        mini.Pixels()[inc] = CRGB::White;
        break;
      case 4:
        mini.Pixels()[inc] = CRGB::Black;
        break;
      case 5:
        break;
    }
    inc++;
    if(inc >= UnicornMini::NUM_LEDS)
    {
      inc = 0;
      mode++;
      if(mode == 5)
        timer.reset();
    }
    mini.Show();
    delay(15);
  }
}
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
