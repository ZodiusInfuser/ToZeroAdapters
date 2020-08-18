//////////////////////////////
//////////////////////////////
//      TOZERO INSPIRING
//
// Port of the RasPiO python 
// script so you can use the 
// Raspio InsPiRing HAT on
// the ToZero adapter.
//////////////////////////////
//////////////////////////////

/***** Project Includes *****/
#include "Apa.h"
#include "HSVtoRGB.h"

/***** Global Constants *****/
static const uint32_t NUM_LEDS = 24;
static const byte BRIGHTNESS = 2;

/***** Global Variables *****/
float currentHue = 0.0f;
uint32_t currentLED = 0;
Apa ledStrip(NUM_LEDS); //Set up 24 LEDs


////////////////////////////////////////////////////////////////////////////////////////////////////
// SETUP
////////////////////////////////////////////////////////////////////////////////////////////////////
void setup()
{
  //Opens serial port, sets data rate to 9600 bps
  Serial.begin(9600);

  //Wait for serial to become available
  delay(2000);

  //Initialise the LED SPI calls.
  ledStrip.begin();
  ledStrip.flushLEDs();

  //Set LED values to black at low brightness
  for(uint32_t i = 0; i < NUM_LEDS; i++)
    ledStrip.setLED(i, BRIGHTNESS, 0, 0, 0); 

  //Send values to all LEDs
  ledStrip.writeLEDs();
}



////////////////////////////////////////////////////////////////////////////////////////////////////
// LOOP
////////////////////////////////////////////////////////////////////////////////////////////////////
void loop()
{
  /////////////////////////////////////////////////////
  // Convert current Hue angle to Red, Green and Blue 
  // components and send to the current (looped) LED.
  /////////////////////////////////////////////////////
  byte r, g, b;
  HSVtoRGB(currentHue, 100.0f, 100.0f, r, g, b);
  ledStrip.setLED(currentLED++, BRIGHTNESS, b, g, r); // BGR, NOT RGB

  //Increment Hue angle
  currentHue += 1.0f;

  //Cap Hue to 360 degrees
  if(currentHue > 360.0f)
    currentHue = 0.0f;

  //Cap led index to max number of LED's
  if(currentLED >= NUM_LEDS)
    currentLED = 0;

  //Send values to all LEDs
  ledStrip.writeLEDs();
  
  //Wait a short time between "frames"
  delay(10);
}
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
