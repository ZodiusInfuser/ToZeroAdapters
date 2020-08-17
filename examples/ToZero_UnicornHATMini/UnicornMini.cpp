#include "UnicornMini.h"

//Mapping going down columns first
/*
const uint16_t UnicornMini::_LUT[] = {
  139, 138, 137,
  223, 222, 221,
  167, 166, 165,
  195, 194, 193,
  111, 110, 109,
  55, 54, 53,
  83, 82, 81,
  
  136, 135, 134,
  220, 219, 218,
  164, 163, 162,
  192, 191, 190,
  108, 107, 106,
  52, 51, 50,
  80, 79, 78,
  
  113, 115, 114,
  197, 199, 198,
  141, 143, 142,
  169, 171, 170,
  85, 87, 86,
  29, 31, 30,
  57, 59, 58,
  
  116, 118, 117,  
  200, 202, 201,
  144, 146, 145,
  172, 174, 173,
  88, 90, 89,
  32, 34, 33,
  60, 62, 61,
  
  119, 121, 120,
  203, 205, 204,
  147, 149, 148,
  175, 177, 176,
  91, 93, 92,
  35, 37, 36,
  63, 65, 64,
  
  122, 124, 123,
  206, 208, 207,
  150, 152, 151,
  178, 180, 179,
  94, 96, 95,
  38, 40, 39,
  66, 68, 67,
  
  125, 127, 126,
  209, 211, 210,
  153, 155, 154,
  181, 183, 182,
  97, 99, 98,
  41, 43, 42,
  69, 71, 70,
  
  128, 130, 129,
  212, 214, 213,
  156, 158, 157,
  184, 186, 185,
  100, 102, 101,
  44, 46, 45,
  72, 74, 73,
  
  131, 133, 132,
  215, 217, 216,
  159, 161, 160,
  187, 189, 188,
  103, 105, 104,
  47, 49, 48,
  75, 77, 76,
  
  363, 362, 361,
  447, 446, 445,
  391, 390, 389,
  419, 418, 417,
  335, 334, 333,
  279, 278, 277,
  307, 306, 305,
  
  360, 359, 358,
  444, 443, 442,
  388, 387, 386,
  416, 415, 414,
  332, 331, 330,
  276, 275, 274,
  304, 303, 302,
  
  337, 339, 338,
  421, 423, 422,
  365, 367, 366,
  393, 395, 394,
  309, 311, 310,
  253, 255, 254,
  281, 283, 282,
  
  340, 342, 341,
  424, 426, 425,
  368, 370, 369,
  396, 398, 397,
  312, 314, 313,
  256, 258, 257,
  284, 286, 285,
  
  343, 345, 344,
  427, 429, 428,
  371, 373, 372,
  399, 401, 400,
  315, 317, 316,
  259, 261, 260,
  287, 289, 288,
  
  346, 348, 347,
  430, 432, 431,
  374, 376, 375,
  402, 404, 403,
  318, 320, 319,
  262, 264, 263,
  290, 292, 291,
  
  349, 351, 350,
  433, 435, 434,
  377, 379, 378,
  405, 407, 406,
  321, 323, 322,
  265, 267, 266,
  293, 295, 294,
  
  352, 354, 353,
  436, 438, 437,
  380, 382, 381,
  408, 410, 409,
  324, 326, 325,
  268, 270, 269,
  296, 298, 297
};*/

//Mapping going across rows first
const uint16_t UnicornMini::_LUT[] = {
  139, 138, 137,
  136, 135, 134,
  113, 115, 114,
  116, 118, 117,
  119, 121, 120,
  122, 124, 123,
  125, 127, 126,
  128, 130, 129,
  131, 133, 132,
  363, 362, 361,
  360, 359, 358,
  337, 339, 338,
  340, 342, 341,
  343, 345, 344,
  346, 348, 347,
  349, 351, 350,
  352, 354, 353,
  
  223, 222, 221,
  220, 219, 218,
  197, 199, 198,
  200, 202, 201,
  203, 205, 204,
  206, 208, 207,
  209, 211, 210,
  212, 214, 213,
  215, 217, 216,
  447, 446, 445,
  444, 443, 442,
  421, 423, 422,
  424, 426, 425,
  427, 429, 428,
  430, 432, 431,
  433, 435, 434,
  436, 438, 437,
  
  167, 166, 165,
  164, 163, 162,
  141, 143, 142,
  144, 146, 145,
  147, 149, 148,
  150, 152, 151,
  153, 155, 154,
  156, 158, 157,
  159, 161, 160,
  391, 390, 389,
  388, 387, 386,
  365, 367, 366,
  368, 370, 369,
  371, 373, 372,
  374, 376, 375,
  377, 379, 378,
  380, 382, 381,
  
  195, 194, 193,
  192, 191, 190,
  169, 171, 170,
  172, 174, 173,
  175, 177, 176,
  178, 180, 179,
  181, 183, 182,
  184, 186, 185,
  187, 189, 188,
  419, 418, 417,
  416, 415, 414,
  393, 395, 394,
  396, 398, 397,
  399, 401, 400,
  402, 404, 403,
  405, 407, 406,
  408, 410, 409,
  
  111, 110, 109,
  108, 107, 106,
  85, 87, 86,
  88, 90, 89,
  91, 93, 92,
  94, 96, 95,
  97, 99, 98,
  100, 102, 101,
  103, 105, 104,
  335, 334, 333,
  332, 331, 330,
  309, 311, 310,
  312, 314, 313,
  315, 317, 316,
  318, 320, 319,
  321, 323, 322,
  324, 326, 325,
  
  55, 54, 53,
  52, 51, 50,
  29, 31, 30,
  32, 34, 33,
  35, 37, 36,
  38, 40, 39,
  41, 43, 42,
  44, 46, 45,
  47, 49, 48,
  279, 278, 277,
  276, 275, 274,
  253, 255, 254,
  256, 258, 257,
  259, 261, 260,
  262, 264, 263,
  265, 267, 266,
  268, 270, 269,
  
  83, 82, 81,  
  80, 79, 78,
  57, 59, 58,
  60, 62, 61,
  63, 65, 64,
  66, 68, 67,
  69, 71, 70,
  72, 74, 73,
  75, 77, 76,
  307, 306, 305,
  304, 303, 302,
  281, 283, 282,
  284, 286, 285,
  287, 289, 288,
  290, 292, 291,
  293, 295, 294,
  296, 298, 297
};

////////////////////////////////////////////////////////////////////////////////////////////////////
// CONSTRUCTORS/DESTRUCTOR
////////////////////////////////////////////////////////////////////////////////////////////////////
UnicornMini::UnicornMini(uint8_t brightness)
: _brightness(brightness)
{
  memset(_buffer, 0, 28*8*2);
}



////////////////////////////////////////////////////////////////////////////////////////////////////
// METHODS
////////////////////////////////////////////////////////////////////////////////////////////////////
void UnicornMini::Begin(void)
{
  pinMode(GPIO_SPI_CE0, OUTPUT);
  pinMode(GPIO_SPI_CE1, OUTPUT);
  
  digitalWrite(GPIO_SPI_CE0, HIGH);  
  digitalWrite(GPIO_SPI_CE1, HIGH);

  ToZero_SPI_Setup();
  GPIO_SPI.begin();

  delayMicroseconds(SPI_DELAY);

  Initialise(GPIO_SPI_CE0);
  Initialise(GPIO_SPI_CE1);
}

void UnicornMini::Initialise(uint8_t pinCE)
{
  digitalWriteFast(pinCE, LOW);
  GPIO_SPI.transfer(CMD_SOFT_RESET);
  digitalWriteFast(pinCE, HIGH);
  delayMicroseconds(SPI_DELAY);

  digitalWriteFast(pinCE, LOW);
  GPIO_SPI.transfer(CMD_GLOBAL_BRIGHTNESS);
  GPIO_SPI.transfer(0x08);
  digitalWriteFast(pinCE, HIGH);  
  delayMicroseconds(SPI_DELAY);

  digitalWriteFast(pinCE, LOW);
  GPIO_SPI.transfer(CMD_SCROLL_CTRL);
  GPIO_SPI.transfer(0x00);
  digitalWriteFast(pinCE, HIGH);  
  delayMicroseconds(SPI_DELAY);

  digitalWrite(pinCE, LOW);
  GPIO_SPI.transfer(CMD_SYSTEM_CTRL);
  GPIO_SPI.transfer(0x00);
  digitalWrite(pinCE, HIGH);  
  delayMicroseconds(SPI_DELAY);

  digitalWriteFast(pinCE, LOW);
  GPIO_SPI.transfer(CMD_WRITE_DISPLAY);
  GPIO_SPI.transfer(0x00);
  for(int i = 0; i < 28*8; i++)
    GPIO_SPI.transfer(0x00);
    
  digitalWriteFast(pinCE, HIGH);  
  delayMicroseconds(SPI_DELAY);

  digitalWriteFast(pinCE, LOW);
  GPIO_SPI.transfer(CMD_COM_PIN_CTRL);
  GPIO_SPI.transfer(0xFF);
  digitalWriteFast(pinCE, HIGH);  
  delayMicroseconds(SPI_DELAY);

  digitalWriteFast(pinCE, LOW);
  GPIO_SPI.transfer(CMD_ROW_PIN_CTRL);
  GPIO_SPI.transfer(0xFF);
  GPIO_SPI.transfer(0xFF);
  GPIO_SPI.transfer(0xFF);
  GPIO_SPI.transfer(0xFF);
  digitalWriteFast(pinCE, HIGH);  
  delayMicroseconds(SPI_DELAY);

  digitalWriteFast(pinCE, LOW);
  GPIO_SPI.transfer(CMD_SYSTEM_CTRL);
  GPIO_SPI.transfer(0x03);
  digitalWriteFast(pinCE, HIGH);  
  delayMicroseconds(SPI_DELAY);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
CRGB (&UnicornMini::Pixels())[NUM_LEDS]
{
  return _pixels;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void UnicornMini::SetBrightness(uint8_t brightness)
{
  _brightness = brightness;
  
  digitalWriteFast(GPIO_SPI_CE0, LOW);
  GPIO_SPI.transfer(CMD_GLOBAL_BRIGHTNESS);
  GPIO_SPI.transfer(_brightness >> 2);
  digitalWriteFast(GPIO_SPI_CE0, HIGH);  

  digitalWriteFast(GPIO_SPI_CE1, LOW);
  GPIO_SPI.transfer(CMD_GLOBAL_BRIGHTNESS);
  GPIO_SPI.transfer(_brightness >> 2);
  digitalWriteFast(GPIO_SPI_CE1, HIGH);  
  delayMicroseconds(SPI_DELAY);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void UnicornMini::Show()
{
  for(uint32_t i = 0; i < NUM_LEDS; i++)
  {
    _buffer[_LUT[i*3]] = _pixels[i].r;
    _buffer[_LUT[(i*3)+1]] = _pixels[i].g;
    _buffer[_LUT[(i*3)+2]] = _pixels[i].b;
  }
  
  digitalWriteFast(GPIO_SPI_CE0, LOW);
  GPIO_SPI.transfer(CMD_WRITE_DISPLAY);
  GPIO_SPI.transfer(0x00);
  for(uint32_t i = 0; i < 28*8; i++)
  {
    GPIO_SPI.transfer(_buffer[i] >> 2);
  }
  delayMicroseconds(SPI_DELAY);
  digitalWriteFast(GPIO_SPI_CE0, HIGH);
  delayMicroseconds(SPI_DELAY);
  
  digitalWriteFast(GPIO_SPI_CE1, LOW);
  GPIO_SPI.transfer(CMD_WRITE_DISPLAY);
  GPIO_SPI.transfer(0x00);
  for(uint32_t i = 0; i < 28*8; i++)
  {
    GPIO_SPI.transfer(_buffer[i + 28*8] >> 2);
  }
  delayMicroseconds(SPI_DELAY);
  digitalWriteFast(GPIO_SPI_CE1, HIGH);
  delayMicroseconds(SPI_DELAY);
}
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
