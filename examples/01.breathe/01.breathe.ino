#include "Freenove_VK16K33_Lib.h"

Freenove_VK16K33 matrix = Freenove_VK16K33();

//The brightness values can be set from 1 to 15, with 1 darkest and 15 brightest
#define  A  15

byte arrow[8][8] =
{
  {0, 0, 0, A, A, 0, 0, 0},
  {0, 0, A, A, A, A, 0, 0},
  {0, A, 0, A, A, 0, A, 0},
  {0, 0, 0, A, A, 0, 0, 0},
  {0, 0, 0, A, A, 0, 0, 0},
  {0, 0, 0, A, A, 0, 0, 0},
  {0, 0, 0, A, A, 0, 0, 0},
  {0, 0, 0, A, A, 0, 0, 0},
};

void setup()
{
  matrix.init(0x71);               //Initialize matrix
  matrix.showLedMatrix(arrow,4,0);
  matrix.show();
}

void loop()
{
  for (int i = 0; i <= 15; i++)
  {
    matrix.setBrightness(i);
    delay(100);
  }
  for (int i = 15; i > 0; i--)
  {
    matrix.setBrightness(i);
    delay(100);
  }
}
