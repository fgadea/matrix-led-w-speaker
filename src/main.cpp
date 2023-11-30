#include "LedControl.h"

LedControl lc = LedControl(10, 8, 7, 4); // Pin and # of Displays

unsigned long delayTime = 200; // Delay between Frames

// Put values in arrays
byte invader1a[] =
    {
        B00011000, // First frame of invader #1
        B00111100,
        B01111110,
        B11011011,
        B11111111,
        B00100100,
        B01011010,
        B10100101};

byte invader1b[] =
    {
        B00011000, // Second frame of invader #1
        B00111100,
        B01111110,
        B11011011,
        B11111111,
        B00100100,
        B01011010,
        B01000010};

byte invader2a[] =
    {
        B00100100, // First frame of invader #1
        B00100100,
        B01111110,
        B11011011,
        B11111111,
        B11111111,
        B10100101,
        B00100100};

byte invader2b[] =
    {
        B00100100, // Second frame of invader #3
        B10100101,
        B11111111,
        B11011011,
        B11111111,
        B01111110,
        B00100100,
        B01000010};

void setup()
{
  for (int i = 0; i < 4; i++)
  {
    lc.shutdown(i, false);
    lc.setIntensity(i, 1);
    lc.clearDisplay(i);
  }
}

//  Take values in Arrays and Display them
void sinvader1a(int device)
{
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(device, i, invader1a[i]);
  }
}

void sinvader1b(int device)
{
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(device, i, invader1b[i]);
  }
}

void sinvader2a(int device)
{
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(device, i, invader2a[i]);
  }
}

void sinvader2b(int device)
{
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(device, i, invader2b[i]);
  }
}

void loop()
{
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(i, 0, B00000000);
    lc.setRow(i, 1, B01111110);
    lc.setRow(i, 2, B01000010);
    lc.setRow(i, 3, B01011010);
    lc.setRow(i, 4, B01011010);
    lc.setRow(i, 5, B01000010);
    lc.setRow(i, 6, B01111110);
    lc.setRow(i, 7, B00000000);
  }

  delay(120);

  for (int i = 0; i < 8; i++)
  {
    lc.setRow(i, 0, B11111111);
    lc.setRow(i, 1, B10000001);
    lc.setRow(i, 2, B10111101);
    lc.setRow(i, 3, B10100101);
    lc.setRow(i, 4, B10100101);
    lc.setRow(i, 5, B10111101);
    lc.setRow(i, 6, B10000001);
    lc.setRow(i, 7, B11111111);
  }
  delay(120);
}