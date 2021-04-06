# Freenove VK16K33 Lib

## Description
This is a Arduino library for Freenove VK16K33 Lib.<br />
It can be used to control a VK16K33 driven LED lattice module consisting of two 8*8 LED lattice modules.<br />
It uses I2C or UART to communicate with Arduino. So you can easily control LED lattice module through it.<br />
And you can add it to almost all your Arduino projects without affecting them. Make your work look cool!<br />

## Examples:

Here are some simple examples.

### 01.breathe
In this example, you can change the array to display the LED Matrix. 
Call setBrightness to set the LED Matrix brightness.
```
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
```
### 04.examples
In this example, you can change the array to display the LED Matrix. 
Call setBrightness to set the LED Matrix brightness.
```
#include "Freenove_VK16K33_Lib.h"

Freenove_VK16K33 matrix = Freenove_VK16K33();

byte x_array[][8] = {//Put the data into the left LED matrix
  //////////////////////////////////////////////
  0x00, 0x3C, 0x7E, 0x66, 0x66, 0x7E, 0x3C, 0x00,
  0x00, 0x3C, 0x7E, 0x7E, 0x7E, 0x7E, 0x3C, 0x00,
  //////////////////////////////////////////////
};

byte y_array[][8] = {//Put the data into the right LED matrix
  //////////////////////////////////////////////
  0x00, 0x3C, 0x7E, 0x66, 0x66, 0x7E, 0x3C, 0x00,
  0x00, 0x3C, 0x7E, 0x7E, 0x7E, 0x7E, 0x3C, 0x00,
  /////////////////////////////////////////////////
};

void setup()
{
  matrix.init(0x71);
  matrix.setBlink(VK16K33_BLINK_OFF);
}

void loop()
{
  showArray(500);
}


void showArray(int delay_ms)
{
  int count = sizeof(x_array) / sizeof(x_array[0]);
  for (int i = 0; i < count; i++)
  {
    matrix.showStaticArray(x_array[i], y_array[i]);
    delay(delay_ms);
  }
}
```
## Usage
```
Freenove_VK16K33 matrix = Freenove_VK16K33();
```
* Construction. Create a Controller object. It is driven by IIC.

```
matrix.init(0x71); 
```
* Communicate with the controller and set the IIC address to 0x71.
```
  matrix.showLedMatrix(arrow,4,0);
```
* Sends the array data to the LED matrix and moves 4 Spaces to the right.
	* arrow: It's an 8 by 8 two-dimensional array.
	* x: Moves the two-dimensional array data as a whole x Spaces to the right.
	* y: Moves the two-dimensional array data as a whole y space to the following.
```
  matrix.show();
```
* Immediately display the arrow data that has been sent.
```
  matrix.setBlink(VK16K33_BLINK_OFF);
```
* Sets whether the LED matrix Blink.
	* VK16K33_BLINK_OFF	    
	* VK16K33_BLINK_1HZ	    
	* VK16K33_BLINK_2HZ	    
	* VK16K33_BLINK_0HZ5	    




