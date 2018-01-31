#ifndef BUTTON_H
#define BUTTON_H

#include <avr/io.h>
#include "timer.h"


class button {
public:
  button(int pin);
  int isPressed(char inPort);
  int isReleased(char inPort);
  int getPrevState();
  bool isWaitingForAction();
  void setWaitingForAction(bool x);

private:
  volatile unsigned char* port;
  int portPin;
  int prevState;    //0 for unpressed, 1 for pressed;
  bool waitingForAction;

};

#endif
