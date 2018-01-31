#include "display.h"

display::display() {

  init();
  return;

}

void display::init() {

  //pin definitions
  DDRE |= (1 << DDE3); //RS; pin 4 of lcd, pin 5 of arduino (PE3)
  DDRE |= (1 << DDE5); //R/W; pin 5 of lcd, pin 3 of arduino (PE5)
  DDRG |= (1 << DDG5); //Enable; pin 6 of lcd, pin 4 of arduino (PG5)
  DDRL = 0xFF; //data bus; pins 7-14 of lcd, pins 35-42 of arduino (port L)

  //R/W is always low (write)
  PORTE &= ~(1 << PORTE5);

  //delay 15 ms for startup
  delayMs(15);

  //Function Set
  sendCommand(0b00111000, 1);
    //DL = 1 (8-bit mode)
    //N = 0 (1-line display)
    //F = 0 (5x8 dot display format)
  delayMs(1);

  //Display OFF
  sendCommand(0b00001000, 1);
    //D = 0 (display off)
    //C = 0 (cursor off)
    //B = 0 (blink is off)
  delayMs(1);

  //Clear Display
  sendCommand(0b00000001, 1);
  delayMs(2);

  //Entry Mode Set
  sendCommand(0b00000110, 1);
    //I/D = 1 (cursor moves right);
    //S = 0 (don't shift the previous letters);
  delayMs(1);

  //Display ON
  sendCommand(0b00001100, 1);
    //D = 1 (display on)
    //C = 1 (cursor off)
    //B = 0 (blink is off)
  delayMs(1);

  return;

}

void display::sendCommand (unsigned char data, int delay) {

  //RS = 0 for instructions, 1 for data
  clrRS();

  //Get the data ready to send
  PORTL = data;

  //set Enable high for specified delay time
  setEN();
  delayMs(delay);           //delay
  clrEN();

  return;

}

void display::sendData (unsigned char data, int delay) {

  //RS = 0 for instructions, 1 for data
  setRS();

  //Get the data ready to send
  PORTL = data;

  //set Enable high for specified delay time
  setEN();
  delayMs(delay);           //delay
  clrEN();

  return;

}


void display::writeAt(const char* stringToWrite, unsigned int row, unsigned int col) {

  if (row > 3) { return; }
  if (col > 19) { return; }

  moveCursor(row, col, 0);

  unsigned int i = 0;

  while ((stringToWrite[i] != '\0') && (i < (20 - col))) {
    sendData(stringToWrite[i], 1);
    ++i;
    delayMs(1);
  }

  return;

}

void display::moveCursor(unsigned char x, unsigned char y, int cursor) {

  //assuming x indicates row (0 to 3) and y indicates column (0 to 19);
  if (x > 3) { x = 3; }
  if (y > 19) { y = 19; }
  if (x < 0) { x = 0; }
  if (y < 0) { y = 0; }

  //determine DDRAM address (AC6:0)
  unsigned char DDaddress = y + ((x % 2) * 0x40);
  if (x > 1) { DDaddress += 20; }

  //send DDRAM address change command
  sendCommand((1 << 7) | DDaddress, 1);
  delayMs(1);

  if (cursor) {
    //display Cursor as '>'
    sendData('>', 1);
    delayMs(1);
  }

  return;

}

void display::clearDisplay() {

  sendCommand(0b00000001, 1);
  delayMs(2);

  return;

}

void display::setRS() { PORTE |= (1 << PORTE3); }
void display::clrRS() { PORTE &= ~(1 << PORTE3); }
void display::setEN() { PORTG |= (1 << PORTG5); }
void display::clrEN() { PORTG &= ~(1 << PORTG5); }
