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
  matrix.init(0x71);
  matrix.setBlink(VK16K33_BLINK_OFF);
}

void loop()
{
  for (int j = -8; j <= 8; j++)
  {
    for (int i = 0; i <= 8; i++)
    {
      matrix.showLedMatrix(arrow, i, j);
      delay(100);
    }
  }
}
