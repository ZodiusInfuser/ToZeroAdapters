//////////////////////////////
//////////////////////////////
//     TOZERO BLINK
//////////////////////////////
//////////////////////////////

/***** Defines *****/

//Uncomment this if the underside pins of the teensy are not soldered
//#define NO_TEENSY_UNDERSIDE_PINS

//Uncomment these if you have changed the underside solder jumpers for GPIO5 and GPIO6
//#ifdef MAP_GPIO5_TO_SPECIAL
//#ifdef MAP_GPIO6_TO_SPECIAL

//Uncomment these if you have changed the underside solder jumpers
//#ifdef SWAP_GPIO16_TO_CE1
//#ifdef SWAP_GPIO27_TO_GPIO26

/***** Library Includes *****/
//#include <Wire.h>
//#include <SPI.h>
#include <ToZero.h>

/***** Global Constants *****/
static const unsigned int DELAY_MS = 1000;


////////////////////////////////////////////////////////////////////////////////////////////////////
// SETUP
////////////////////////////////////////////////////////////////////////////////////////////////////
void setup()
{
  ToZero_Setup();

  pinMode(LED_BUILTIN, OUTPUT);
}



////////////////////////////////////////////////////////////////////////////////////////////////////
// LOOP
////////////////////////////////////////////////////////////////////////////////////////////////////
void loop()
{
  digitalWrite(LED_BUILTIN, HIGH);
  delay(DELAY_MS);
  digitalWrite(LED_BUILTIN, LOW);
  delay(DELAY_MS);
}
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
