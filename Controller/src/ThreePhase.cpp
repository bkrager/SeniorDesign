#include "ThreePhase.h"
#include "timer.h"
#include <Arduino.h>

//Constructor
ThreePhase::ThreePhase(int portNumber) {

  position = 0;
  target = 0;
  currentStep = 0;    //0 to 5 inclusive
  direction = 0;
  moving = 0;
  setPort(portNumber);
  setSpeed(100);

}

//Setters
void ThreePhase::setSpeed(int StepsPerSec) {

  speed = StepsPerSec;

  //calculate PWM period
  int periods = 15625 / StepsPerSec;   //each period is 64us (1/15625)

  if (portNum == 1) { changePeriod1(periods); }
  else if (portNum == 3) { changePeriod3(periods); }

  return;

}
void ThreePhase::zeroPos() { position = 0; }
void ThreePhase::setPort(int portNumber) {

  portNum = portNumber;

  if (portNum == 1) {
    port = &PORTA;
    //set pins 5:0 as outputs and pins 7:6 as inputs
    DDRA = 0b00111111;
  }

  else if (portNum == 3) {
    port = &PORTC;
    //set pins 5:0 as outputs and pins 7:6 as inputs
    DDRC = 0b00111111;
  }

  //set internal pullups on pins 7:6
  *port |= (0b11000000);


  return;

}
void ThreePhase::setMoving(int x) { moving = x; }

void ThreePhase::MoveRel(int stepsRel) { MoveAbs(stepsRel + position); return; }

void ThreePhase::MoveAbs(int positionAbs) {

  target = positionAbs;
  direction = target - position;
  if (!direction) { moving = 0; return; }

  moving = 1;

  //initialize the timers and let the ISRs do everything else
  if (portNum == 1) { turnOnTimer1(); }
  else if (portNum == 3) { turnOnTimer3(); }

  return;

}

void ThreePhase::home() { zeroPos(); MoveAbs(-32000); return; }

void ThreePhase::step() {

  //determine direction of rotation
  if (direction > 0) {
    //clockwise
    currentStep++; if (currentStep > 5) { currentStep = 0; }
    position++;
  }
  else if (direction < 0) {
    //counter-clockwise
    currentStep--; if (currentStep < 0) { currentStep = 5; }
    position--;
  }
  else {
    return;
  }

  switch (currentStep) {

    case 0: //ABC = 110
      *port &= ~(0b00010110);    //turn off Ab
      *port |= (0b00101001);     //turn on At
      break;

    case 1: //ABC = 100
      *port &= ~(0b00011010);    //turn off Bt
      *port |= (0b00100101);     //turn on Bb
      break;

    case 2: //ABC = 101
      *port &= ~(0b00011001);    //turn off Cb
      *port |= (0b00100110);     //turn on Ct
      break;

    case 3: //ABC = 001
      *port &= ~(0b00101001);    //turn off At
      *port |= (0b00010110);     //turn on Ab
      break;

    case 4: //ABC = 011
      *port &= ~(0b00100101);    //turn off Bb
      *port |= (0b00011010);     //turn on Bt
      break;

    case 5: //ABC = 010
      *port &= ~(0b00100110);    //turn off Ct
      *port |= (0b00011001);     //turn on Cb
      break;
  }

  return;

}

void ThreePhase::disable() {

  *port = 0x00;

  return;
}

//Accessors
int ThreePhase::getPosition() const { return position; }
int ThreePhase::getTarget() const { return target; }
int ThreePhase::isMoving() const { return moving; };
