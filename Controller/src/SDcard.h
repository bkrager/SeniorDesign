#ifndef SDCARD_H
#define SDCARD_H

#include <avr/io.h>
#include <SD.h>
#include "display.h"




class SDcard {
public:
  int listFiles(display lcd, int line1);
  SDcard();

private:

};

#endif
