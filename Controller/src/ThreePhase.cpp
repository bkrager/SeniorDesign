#include "ThreePhase.h"
#include "timer.h"
#include <Arduino.h>

//Constructor
ThreePhase::ThreePhase(int portNumber) {

  position = 0;
  target = 0;
  currentStep = 0;    //0 to 127 inclusive
  direction = 0;
  moving = 0;
  setPort(portNumber);
  setSpeed(100);

  for (int i = 0; i < 128; ++i) {
    sinA[i] = round(128.0 + 120.0 * sin(2*M_PI*(i/128.0 - 0.0/3.0)));
    sinB[i] = round(128.0 + 120.0 * sin(2*M_PI*(i/128.0 - 1.0/3.0)));
    sinC[i] = round(128.0 + 120.0 * sin(2*M_PI*(i/128.0 - 2.0/3.0)));
  }


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
  //disable();

  //initialize the timers and let the ISRs do everything else
  if (portNum == 1) { turnOnTimer1(); turnOnTimer4(); }
  else if (portNum == 3) { turnOnTimer3(); turnOnTimer5(); }

  return;

}

void ThreePhase::home() { zeroPos(); MoveAbs(-32000); return; }

void ThreePhase::step() {

  //determine direction of rotation
  if (direction > 0) {
    //clockwise
    currentStep++; if (currentStep > 127) { currentStep = 0; }
    position++;
  }
  else if (direction < 0) {
    //counter-clockwise
    currentStep--; if (currentStep < 0) { currentStep = 127; }
    position--;
  }
  else {
    return;
  }

  if (portNum == 1) {
    OCR4A = sinA[currentStep];
    OCR4B = sinB[currentStep];
    OCR4C = sinC[currentStep];
  } else if (portNum == 3) {
    OCR5A = sinA[currentStep];
    OCR5B = sinB[currentStep];
    OCR5C = sinC[currentStep];
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
