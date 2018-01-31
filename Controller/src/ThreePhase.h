#ifndef THREEPHASE_H
#define THREEPHASE_H

#include <avr/io.h>

class ThreePhase {
public:

  ThreePhase(int portNumber);

  void setSpeed(int StepsPerSec);
  void zeroPos();
  void setPort(int portNumber);
  void MoveRel(int stepsRel);
  void MoveAbs(int postionAbs);
  void home();
  void setMoving(int x);
  void disable();

  void step();

  int getPosition() const;
  int getTarget() const;
  int isMoving() const;



private:

  int speed;
  int position;   //absolute
  int target;
  int currentStep;
  int direction;
  volatile unsigned char* port;
  int portNum;
  int moving;





};

#endif
