#ifndef _APA_h
#define _APA_h

/***** Includes *****/
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

//Uncomment this if the underside pins of the teensy are not soldered
//#define NO_TEENSY_UNDERSIDE_PINS

//Uncomment this if you have changed the underside solder jumper
//#define SWAP_GPIO16_TO_CE1

#if defined(__IMXRT1062__)
  #include <ToZero_4x_SPI.h>
#else
  #include <ToZero_3x_SPI.h>
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
// Classes
////////////////////////////////////////////////////////////////////////////////////////////////////
class Apa
{
  //--------------------------------------------------
  // Constructors/Destructor
  //--------------------------------------------------
public:
  Apa(uint32_t numLEDs, bool serialDebug = false);
  ~Apa(void);


  //--------------------------------------------------
  // Methods
  //--------------------------------------------------
public:
  void begin(void);
  void createLEDArray(uint32_t numLEDs);
  void flushLEDs(void);
  void writeLEDs(void);
  void resetLEDs(void);
  void zeroLEDs(void);
  void setLED(uint32_t number, byte brightness, byte blue, byte green, byte red);

private:
  void spiBegin(void);
  void spiEnd(void);


  //--------------------------------------------------
  // Variables
  //--------------------------------------------------
private:
  SPISettings _spiSettings;
  uint32_t _numLEDs;
  byte* _ledValues;
  bool _serialDebug;  
};
#endif
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
