#include "XYtable.h"
#include "timer.h"
#include <math.h>
#include <Arduino.h>
#include <stdlib.h>

#define RAPIDSPEED 4000      //steps per second
#define STEPSPERINCH 989.9

int XYtable::getRelProg() { return relativeProgramming; }

int XYtable::execGLine(char* line) {

  //returns 0 for normal operations
  //returns 1 for in-program stops (compulsory or optional - but only if option stop is set)
  //returns 2 for program end

  char* command = strtok(line, " ");
  int G[10];    //motion command
  double X = 0;    //x-axis control , seconds (G04)
  double Y = 0;    //y-axis control
  int M[10];    //miscellaneous commands
  double F = 0;    //feedrate (G94-in/min)
  int P = 0;    //milliseconds (G04), WCS address (1-6)
  bool Xexplicit = 0;
  bool Yexplicit = 0;
  int Xint = 0;
  int Yint = 0;

  int i = 0;
  int j = 0;

  for(i = 0; i < 10; i++) {
    G[i] = -1;
    M[i] = -1;
  }
  i = 0;

  while (command != NULL) {

    if (command[0] == 'G') { G[i] = strtol(strchr(command, command[1]), NULL, 10); i++; }
    if (command[0] == 'X') { X = strtod(strchr(command, command[1]), NULL); Xexplicit = 1; }
    if (command[0] == 'Y') { Y = strtod(strchr(command, command[1]), NULL); Yexplicit = 1; }
    if (command[0] == 'M') { M[j] = strtol(strchr(command, command[1]), NULL, 10); j++; }
    if (command[0] == 'F') { F = strtod(strchr(command, command[1]), NULL); }
    if (command[0] == 'P') { P = strtol(strchr(command, command[1]), NULL, 10); }

    command = strtok(NULL, " ");
  }

  //if X or Y parameters are ommitted, then these axes should not move ELSE convert to inch/mm
  if (!Xexplicit && !relativeProgramming) {
    Xint = Xmotor->getPosition() - Xoffset(WCS);
  } else {
    if (inchmm) {
      Xint = round(X * STEPSPERINCH);
    } else {
      Xint = round(X * STEPSPERINCH / 25.4);
    }
  }

  if (!Yexplicit && !relativeProgramming) {
    Yint = Ymotor->getPosition() - Yoffset(WCS);
  } else {
    if (inchmm) {
      Yint = round(Y * STEPSPERINCH);
    } else {
      Yint = round(Y * STEPSPERINCH / 25.4);
    }
  }

  int imax = i;
  int jmax = j;

  for (i = 0; i < imax; i++) {

    //if in skipping, ignore all commands except stop, option stop, home, or rapid
    if (skipping) {
      if((G[i] == 0) || (G[i] == 28) || (G[i] == 30)) {
        skipping = 0;
      } else {
        G[i] = -1;
      }
    }

    if (G[i] > -1) {
      // G00 rapid motion
      if (G[i] == 0) {
        rapidMove(Xint, Yint);
      }
      // G01 linear motion
      else if (G[i] == 1) {
        linearMove(Xint, Yint);
      }
      // G02 - G03 circular motion - interpolated as straight line
      else if ((G[i] == 2) || (G[i] == 3)) {
        linearMove(Xint, Yint);
      }
      // G04 dwell
      else if (G[i] == 4) {
        if (P != 0) {
          delayMs(P);
        } else {
          delayMs(X * 1000);
        }
      }
      // G05 - G19 ommitted - no fancy cuts
      // G20 - G21 inches/mm
      else if (G[i] == 20) {
        inchmm = 1;
      }
      else if (G[i] == 21) {
        inchmm = 0;
      }
      // G28 home
      else if (G[i] == 28) {
        home();
      }
      // G30 return to reference point
      else if (G[i] == 30) {
        WCS = P;
        rapidMoveAbs(Xoffset(P), Yoffset(P));
      }
      // G31 skip function ommitted - no probes or measurements
      // G32 - G34 ommitted - no threading
      // G40 - G49 ommitted - no tool offsets
      // G50 ommitted - no scaling function
      // G52 local coordinate system
      else if (G[i] == 52) {
        G52X = Xint;
        G52Y = Yint;
      }
      // G53 Machine Coordinate System
      else if (G[i] == 53) {
        linearMoveAbs(Xint, Yint);
      }
      // G54 - G59 Work Coordinate Systems
      else if ((G[i] >= 54) && (G[i] <= 59)) {
        WCS = G[i] - 53;
        switch(WCS) {
          case 1:
            G54X = Xint; G54Y = Yint;
          case 2:
            G55X = Xint; G55Y = Yint;
          case 3:
            G56X = Xint; G56Y = Yint;
          case 4:
            G57X = Xint; G57Y = Yint;
          case 5:
            G58X = Xint; G58Y = Yint;
          case 6:
            G59X = Xint; G59Y = Yint;
        }
      }
      // G61 - G64 ommitted - no path control for corners
      // G68 - G69 ommitted - no coordinate system rotations
      // G70 - G89 ommitted - no cycles, drilling, boring, or tapping
      // G90 absolute programming
      else if (G[i] == 90) {
        relativeProgramming = 0;
      }
      // G91 relative programming
      else if (G[i] == 91) {
        relativeProgramming = 1;
      }
      // G92 ommitted - like G52 but not recommended
      // G94 feed rate per minute
      else if (G[i] == 94) {
        speed = round(F / 60.0 * STEPSPERINCH);
      }
      // G95 feed rate per revolution - omitted (no flow control)
      // G96 constant surface speed - omitted (lathes)
      // G97 constant spindle speed - omitted (no flow control)
      // G98 - G99 ommitted - no canned cycles
      // G100 ommitted - no tool length measurement required
    }
  }

  for (j = 0; j < jmax; j++) {

    //if in skipping, ignore all commands except stop, option stop, or rapid
    if (skipping) {
      if((M[j] == 0) || (M[j] == 1) || (M[j] == 2) || (M[j] == 30)) {
        skipping = 0;
      } else {
        M[j] = -1;
      }
    }

    if (M[j] > -1) {

      // M00 compulsory Stop
      if (M[j] == 0) {
        controlValve(0);
        turnOffTimer1();
        turnOffTimer3();
        return 1;
      }
      // M01 Optional stop
      else if (M[j] == 1) {
        if (optionStop) {
          controlValve(0);
          turnOffTimer1();
          turnOffTimer3();
          return 1;
        }
      }
      // M02 end of Program
      else if (M[j] == 2) {
        controlValve(0);
        //disableMotors();
        return 2;
      }
      // M03 spindle on clockwise
      else if (M[j] == 3) {
        controlValve(1);
        // S argument conrols spindle speed - irrelevant here
      }
      // M04 spindle on CCW
      else if (M[j] == 4) {
        controlValve(0);
        // valve not reversible - just turn off
      }
      // M05 spindle stop
      else if (M[j] == 5) {
        controlValve(0);
      }
      // M06 ommitted - no automatic tool changing
      // M07 - M09 ommitted - no coolant
      // M10 - M11 ommitted - no pallet clamping
      // M13 spindle on CW w/ coolant (but no coolant)
      else if (M[j] == 13) {
        controlValve(1);
        // S argument conrols spindle speed - irrelevant here
      }
      // M19 ommitted - spindle orientation not adjustable
      // M21 - M24 omitted - no mirroring, tailstock, or threading
      // M30 end of program (same as M02)
      else if (M[j] == 30) {
        controlValve(0);
        //disableMotors();
        return 2;
      }
      // M41 - M60 ommitted - no gear select, feed rate overrides, or tool/pallet changes
      // M98 - M99 ommitted - no subprograms ... for now
    }
  }

  return 0;
}

void XYtable::setDry(int dry) { dryRun = dry; }

int XYtable::Xoffset(int P) {
  switch(P) {
    case 1:
      return G52X + G54X; break;
    case 2:
      return G52X + G55X; break;
    case 3:
      return G52X + G56X; break;
    case 4:
      return G52X + G57X; break;
    case 5:
      return G52X + G58X; break;
    case 6:
      return G52X + G59X; break;
    default:
      return G52X; break;
  }
}

int XYtable::Yoffset(int P) {
  switch(P) {
    case 1:
      return G52Y + G54Y; break;
    case 2:
      return G52Y + G55Y; break;
    case 3:
      return G52Y + G56Y; break;
    case 4:
      return G52Y + G57Y; break;
    case 5:
      return G52Y + G58Y; break;
    case 6:
      return G52Y + G59Y; break;
    default:
      return G52Y; break;
  }
}

//Constructor
XYtable::XYtable() {

  Xmotor = new ThreePhase(1);
  Ymotor = new ThreePhase(3);
  solenoidValve = new pump();

  speed = RAPIDSPEED;
  speedFactor = 100;

  //all offsets zero
  G52X = 0;
  G52Y = 0;
  G54X = 0;
  G54Y = 0;
  G55X = 0;
  G55Y = 0;
  G56X = 0;
  G56Y = 0;
  G57X = 0;
  G57Y = 0;
  G58X = 0;
  G58Y = 0;
  G59X = 0;
  G59Y = 0;

  WCS = 0;
  relativeProgramming = 0;
  dryRun = 0;
  optionStop = 1;
  inchmm = 1;               //inch
  skipping = 0;

}

void XYtable::linearMove(int X, int Y) {
  if (relativeProgramming) {
    linearMoveRel(X, Y);
  } else {
    linearMoveAbs(X + Xoffset(WCS), Y + Yoffset(WCS));
  }
}

void XYtable::rapidMove(int X, int Y) {
  if (relativeProgramming) {
    rapidMoveRel(X, Y);
  } else {
    rapidMoveAbs(X + Xoffset(WCS), Y + Yoffset(WCS));
  }
}

void XYtable::linearMoveAbs(int Xabs, int Yabs) {

  int Xdist = abs(Xabs - Xmotor->getPosition());
  int Ydist = abs(Yabs - Ymotor->getPosition());

  //determine speed for each Axis
  //prevent overflow by scaling both distances down (highest number is 2^15)
  while (abs(Xdist + Ydist) > 180) {
    Xdist = Xdist / 2;
    Ydist = Ydist / 2;
  }
  double totalDist = sqrt(Xdist*Xdist + Ydist*Ydist); if (totalDist == 0) { totalDist = 1; }
  double Xspeed = (Xdist / totalDist) * speed * (speedFactor / 100.0);
  double Yspeed = (Ydist / totalDist) * speed * (speedFactor / 100.0);

  Xmotor->setSpeed(round(Xspeed));
  Ymotor->setSpeed(round(Yspeed));

  Xmotor->MoveAbs(Xabs);
  Ymotor->MoveAbs(Yabs);

}

void XYtable::linearMoveRel(int Xdist, int Ydist) {

  int Xdists = abs(Xdist);
  int Ydists = abs(Ydist);

  //determine speed for each Axis
  //prevent overflow by scaling both distances down (highest number is 2^15)
  while (abs(Xdists + Ydists) > 180) {
    Xdists = Xdists / 2;
    Ydists = Ydists / 2;
  }
  double totalDist = sqrt(Xdists*Xdists + Ydists*Ydists);
  double Xspeed = (Xdists / totalDist) * speed * (speedFactor / 100.0);
  double Yspeed = (Ydists / totalDist) * speed * (speedFactor / 100.0);

  Xmotor->setSpeed(round(Xspeed));
  Ymotor->setSpeed(round(Yspeed));

  Xmotor->MoveRel(Xdist);
  Ymotor->MoveRel(Ydist);

}

void XYtable::rapidMoveAbs(int Xabs, int Yabs) {

  Xmotor->setSpeed(RAPIDSPEED);
  Ymotor->setSpeed(RAPIDSPEED);

  Xmotor->MoveAbs(Xabs);
  Ymotor->MoveAbs(Yabs);

}

void XYtable::rapidMoveRel(int Xdist, int Ydist) {

  Xmotor->setSpeed(RAPIDSPEED);
  Ymotor->setSpeed(RAPIDSPEED);

  Xmotor->MoveRel(Xdist);
  Ymotor->MoveRel(Ydist);

}

void XYtable::controlValve(bool onoff) {
  if (dryRun) {
    solenoidValve->control(0);
  } else {
    solenoidValve->control(onoff);
  }
  return;
}

void XYtable::setSpeed(int StepsPerSec) {

  speed = StepsPerSec;

  //change speed immediately.
  linearMoveAbs(Xmotor->getTarget(), Ymotor->getTarget());

}

int XYtable::getSpeedFactor() { return speedFactor; }

void XYtable::changeSpeedFactor(int change) { speedFactor += change; setSpeed(speed); }

int XYtable::isMoving() const {
  if (Xmotor->isMoving()) { return 1; }
  if (Ymotor->isMoving()) { return 1; }
  return 0;
}

void XYtable::home() {

  Xmotor->setSpeed(RAPIDSPEED);
  Ymotor->setSpeed(RAPIDSPEED);
  Xmotor->home();
  Ymotor->home();

  return;

}

void XYtable::disableMotors() {
  Xmotor->disable();
  Ymotor->disable();
  return;
}

bool XYtable::getOptionStop() { return optionStop; }
void XYtable::setOptionStop(bool x) { optionStop = x; return; }

bool XYtable::isSkipping() { return skipping; }
void XYtable::setSkipping(bool x) { skipping = x; }

int XYtable::getXposition() const { return Xmotor->getPosition(); }
int XYtable::getXtarget() const { return Xmotor->getTarget(); }
void XYtable::setXmoving(int x) { Xmotor->setMoving(x); return; }
void XYtable::setXspeed(int StepsPerSec) { Xmotor->setSpeed(StepsPerSec); return; }
void XYtable::zeroXpos() { Xmotor->zeroPos(); return; }
void XYtable::homeX() { Xmotor->setSpeed(RAPIDSPEED); Xmotor->home(); return; }
void XYtable::Xstep() { Xmotor->step(); return; }
void XYtable::moveXabs(int positionAbs) { Xmotor->MoveAbs(positionAbs); return; }
void XYtable::moveXrel(int stepsRel) { Xmotor->MoveRel(stepsRel); return; }

int XYtable::getYposition() const { return Ymotor->getPosition(); }
int XYtable::getYtarget() const { return Ymotor->getTarget(); }
void XYtable::setYmoving(int x) { Ymotor->setMoving(x); return; }
void XYtable::setYspeed(int StepsPerSec) { Ymotor->setSpeed(StepsPerSec); return; }
void XYtable::zeroYpos() { Ymotor->zeroPos(); return; }
void XYtable::homeY() { Ymotor->setSpeed(RAPIDSPEED); Ymotor->home(); return; }
void XYtable::Ystep() { Ymotor->step(); return; }
void XYtable::moveYabs(int positionAbs) { Ymotor->MoveAbs(positionAbs); return; }
void XYtable::moveYrel(int stepsRel) { Ymotor->MoveRel(stepsRel); return; }
