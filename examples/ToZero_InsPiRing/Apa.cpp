/////////////////////////////////////////////////////////////////////
// 15/08/2020 - This is an Arduino port of the RasPiO Inspiring 
// python Apa.py script from https://github.com/raspitv/raspio-inspiring
// and is intended to be used on a ToZero Raspberry Pi Hat to 
// Arduino adapter board.
// 
// Please see http://rasp.io/inspiring for more details on 
// the Inspiring and the original code.
/////////////////////////////////////////////////////////////////////

#include "Apa.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
// CONSTRUCTORS/DESTRUCTOR
////////////////////////////////////////////////////////////////////////////////////////////////////
Apa::Apa(uint32_t numLEDs, bool serialDebug)
: _spiSettings(30000000, MSBFIRST, SPI_MODE0)
, _numLEDs(0)
, _ledValues(nullptr)
, _serialDebug(serialDebug)
{
  //Safe to create/update LED values array
  createLEDArray(numLEDs);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
Apa::~Apa(void)
{
  delete[] _ledValues;
}



////////////////////////////////////////////////////////////////////////////////////////////////////
// METHODS
////////////////////////////////////////////////////////////////////////////////////////////////////
void Apa::begin(void)
{
  /////////////////////////////////////
  // Called in the SETUP method of the
  // arduino to configure SPI.
  /////////////////////////////////////
  pinMode(GPIO_SPI_CE1, OUTPUT);
  digitalWrite(GPIO_SPI_CE1, HIGH);

  if(_serialDebug)
    Serial.println("Initialising SPI bus");

  ToZero_SPI_Setup();  
  GPIO_SPI.begin();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void Apa::createLEDArray(uint32_t numLEDs)
{
  /////////////////////////////////////////
  // Create/Recreate the LED values array.
  /////////////////////////////////////////

  //First, destroy any previous array.
  delete[] _ledValues;

  //Create a blank array 4x larger than number of
  //LEDs so we can store 4 bytes per LED (brightness, blue, green, red).
  _numLEDs = numLEDs;
  _ledValues = new byte[_numLEDs * 4];

  //Initialise LED value array with default values
  zeroLEDs();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void Apa::flushLEDs(void)
{
  ////////////////////////////////////////////////////
  // Sends 4 null bytes to wake/initiate the APA102s
  // also used to terminate the frame.
  ////////////////////////////////////////////////////
  if(_serialDebug)
    Serial.println("Flush LEDs SPI call");

  spiBegin();
  
  GPIO_SPI.transfer(0x00);
  GPIO_SPI.transfer(0x00);
  GPIO_SPI.transfer(0x00);
  GPIO_SPI.transfer(0x00);
  
  spiEnd();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void Apa::writeLEDs(void)
{
  //////////////////////////////////////////////////////
  // writeLEDs() writes all stored led_values to LEDs.
  //////////////////////////////////////////////////////
  if(_serialDebug)
    Serial.println("Writing LED array values to hat via SPI");
    
  flushLEDs();

  spiBegin();
  
  //Send LED values to the SPI bus
  for(uint32_t i = 0; i < _numLEDs; i++)
  {
    GPIO_SPI.transfer(_ledValues[(i * 4)]);
    GPIO_SPI.transfer(_ledValues[(i * 4) + 1]);
    GPIO_SPI.transfer(_ledValues[(i * 4) + 2]);
    GPIO_SPI.transfer(_ledValues[(i * 4) + 3]);
  }

  spiEnd();

  uint32_t flushCount = (_numLEDs / 32) + 2;
  for(uint32_t i = 0; i < flushCount; i++)
  {
    flushLEDs();
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void Apa::resetLEDs(void)
{
  ////////////////////////////////////////////////
  // resetLEDs() switches all leds off manually 
  // without changing stored led_values.
  ////////////////////////////////////////////////
  if(_serialDebug)
    Serial.println("Turning off all LEDs");
    
  flushLEDs();

  spiBegin();

  //Set all APA102c LEDs to zero brightness 0xE0, zero colour.
  for(uint32_t i = 0; i < _numLEDs; i++)
  {
    GPIO_SPI.transfer(0xE0);
    GPIO_SPI.transfer(0x00);
    GPIO_SPI.transfer(0x00);
    GPIO_SPI.transfer(0x00);
  }

  spiEnd();
  
  uint32_t flushCount = (_numLEDs / 32) + 2;
  for(uint32_t i = 0; i < flushCount; i++)
    flushLEDs();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void Apa::zeroLEDs(void)
{
  //////////////////////////////////////////////
  // zero_leds() zeroes stored led_values 
  // without writing their values to the LEDs. 
  // i.e. total reset but don't display yet.
  //////////////////////////////////////////////
  if(_serialDebug)
    Serial.println("Clearing LED array values");
    
  for(uint32_t i = 0; i < _numLEDs; i++)
  {
    _ledValues[(i * 4)] =     0xE0;
    _ledValues[(i * 4) + 1] = 0x00;
    _ledValues[(i * 4) + 2] = 0x00;
    _ledValues[(i * 4) + 3] = 0x00;
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void Apa::setLED(uint32_t number, byte brightness, byte blue, byte green, byte red)
{
  ///////////////////////////////////////////////////////////////////////////
  // setLED() is used to set the values for a specific LED.
  // number is the list index of the LED
  // e.g. first LED is 0 and eighth is 7.
  //
  // Brightness values are 0-31 for simplicity
  // But you can also use  224-255 or 0xE0-0xFF
  //
  // Colour values are 0-255 in decimal or hex 0x00-0xFF.
  // Values such as 255, 0, 0, 0 sometimes cause errors.
  //
  // If you want "black" or "off", better to use brightness of 224 or 0xE0
  // then the LED will be off regardless of what colour values you give it.
  ///////////////////////////////////////////////////////////////////////////
  if(_serialDebug)
    Serial.println("Setting single LED value into array");
    
  if(brightness < 32)   //so you can use 0-31 for brightness too
      brightness += 224;

  _ledValues[(number * 4)] = brightness;
  _ledValues[(number * 4) + 1] = blue;
  _ledValues[(number * 4) + 2] = green;
  _ledValues[(number * 4) + 3] = red;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void Apa::spiBegin(void)
{
  ////////////////////////////////
  // Set SPI settings and select 
  // device to write too.
  ////////////////////////////////
  GPIO_SPI.beginTransaction(_spiSettings);
  digitalWrite(GPIO_SPI_CE1, LOW);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void Apa::spiEnd(void)
{
  ////////////////////////////
  // Deselect SPI device and 
  // reset for next call.
  ////////////////////////////
  digitalWrite(GPIO_SPI_CE1, HIGH);
  GPIO_SPI.endTransaction();
}
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
