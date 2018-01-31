#ifndef DISPLAY_H
#define DISPLAY_H

#include <avr/io.h>
#include "timer.h"

class display {
public:

  display();
  void init();
  void sendCommand (unsigned char data, int delay);
  void sendData (unsigned char data, int delay);
  void writeAt(const char* stringToWrite, unsigned int row, unsigned int col);
  void moveCursor(unsigned char x, unsigned char y, int cursor);
  void clearDisplay();


private:

  void setRS();
  void clrRS();
  void setEN();
  void clrEN();

};

#endif
