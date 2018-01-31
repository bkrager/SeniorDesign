#ifndef XYTABLE_H
#define XYTABLE_H

#include <avr/io.h>
#include "ThreePhase.h"
#include "pump.h"

class XYtable {
public:

  XYtable();

  void linearMove(int X, int Y);
  void linearMoveAbs(int Xabs, int Yabs);
  void linearMoveRel(int Xdist, int Ydist);

  void rapidMove(int X, int Y);
  void rapidMoveAbs(int Xabs, int Yabs);
  void rapidMoveRel(int Xdist, int Ydist);

  void controlValve(bool onoff);

  void setSpeed(int StepsPerSec);
  int getSpeedFactor();
  void changeSpeedFactor(int change);
  int isMoving() const;
  void home();
  void disableMotors();

  int execGLine(char* line);
  void setDry(int dry);
  int Xoffset(int P);
  int Yoffset(int P);

  int getXposition() const;
  int getXtarget() const;
  void setXmoving(int x);
  void setXspeed(int StepsPerSec);
  void zeroXpos();
  void homeX();
  void Xstep();
  void moveXabs(int positionAbs);
  void moveXrel(int stepsRel);

  int getYposition() const;
  int getYtarget() const;
  void setYmoving(int x);
  void setYspeed(int StepsPerSec);
  void zeroYpos();
  void homeY();
  void Ystep();
  void moveYabs(int positionAbs);
  void moveYrel(int stepsRel);

  ThreePhase* Xmotor;
  ThreePhase* Ymotor;

  int getRelProg();
  bool getOptionStop();
  void setOptionStop(bool x);
  bool isSkipping();
  void setSkipping(bool x);


private:

  pump* solenoidValve;

  int speed;
  int speedFactor;

  int G52X;
  int G52Y;
  int G54X;
  int G54Y;
  int G55X;
  int G55Y;
  int G56X;
  int G56Y;
  int G57X;
  int G57Y;
  int G58X;
  int G58Y;
  int G59X;
  int G59Y;

  int WCS;
  int relativeProgramming;
  int dryRun;
  bool optionStop;
  bool inchmm;
  bool skipping;

};

#endif
