#include <Arduino.h>
#include "ThreePhase.h"
#include "timer.h"
#include "XYtable.h"
#include "display.h"
#include "SDcard.h"
#include "menu.h"
#include "button.h"
#include "pump.h"
#include <avr/io.h>
#include <SD.h>

XYtable toolpath;
button upButton(10);
button downButton(11);
button selectButton(12);
button limitX0(111);
button limitXF(110);
button limitY0(109);
button limitYF(108);
menu systemMenu(&toolpath);
File G;
char line[400];
char buffer;

typedef enum StateEnum { NoJob, DryRun, RealRun } StateType;
volatile StateType state = NoJob;

int Gcode();
void wait();

int main() {

  Serial.begin(9600);

  sei();
  initTimers();
  systemMenu.displayMenu(0);
  char ready[21] = "Ready for Next Job";

  while(1) {

    switch(state) {

      case NoJob:
        wait();
        break;

      case DryRun:
        toolpath.setDry(1);
        if (Gcode() == 0) {
          systemMenu.setStatusLine(ready);
          systemMenu.setNameLine(0);
        }
        toolpath.setDry(0);
        state = NoJob;
        break;

      case RealRun:
        toolpath.setDry(0);
        if (Gcode() == 0) {
          systemMenu.setStatusLine                                                                                                                                                                                                 (ready);
          systemMenu.setNameLine(0);
        }
        state = NoJob;
        break;

    }
  }
  return 0;

}

//execute an entire file of Gcode
int Gcode() {

  //returns 0 for normal execution
  //returns 1 if program was ended prematurely (crash or manual stop);

  systemMenu.setNameLine(1);

  int numLines = 0;
  int currentLine = 0;
  int i = 0;
  int status = 0;
  char reading[21] = "Reading File";
  char warning[21] = "UP=cont / DOWN=skip";
  double percentFactor = 100.0;

  //open file, determine number of lines
  systemMenu.setStatusLine(reading);
  G = systemMenu.openGfile();
  if (G) {
    i = 0;
    while(G.available()) {
      buffer = G.read();
      if (buffer == '\n') {
        ++numLines;
      }
    }
    G.close();
  }

  //prevent overflow from long files
  while (numLines > 320) {
    numLines = numLines / 1.414;
    percentFactor = percentFactor / 1.414;
  }

  //open file, read line, send info to LCD and toolpath
  G = systemMenu.openGfile();
  if (G) {
    i = 0;
    while(G.available() && (state != NoJob)) {
      buffer = G.read();
      if (buffer != '\n') {
        line[i] = buffer;
        ++i;
      } else {
        line[i] = '\0';
        i = 0;
        currentLine++;
        systemMenu.setProgressLine(currentLine * percentFactor / numLines);
        systemMenu.setStatusLine(line);
        status = toolpath.execGLine(line);
        while(toolpath.isMoving()) { wait(); }
        switch (status) {
          case 1: //program stop
            turnOffTimer1();
            turnOffTimer3();
            toolpath.controlValve(0);
            systemMenu.setInOptionStop(1);
            systemMenu.setStatusLine(warning);
            while (systemMenu.isInOptionStop()) { wait(); }
            break;
          case 2: //end of program
            G.close();
            return 0;
            break;
        }
      }
    }

    //close file
    G.close();
  }

  if (state == NoJob) { return 1; }

  return 0;

}

//check user input buttons while motors are running
void wait() {
  if (upButton.isWaitingForAction()) { upButton.setWaitingForAction(0); systemMenu.scroll(-1); }
  else if (downButton.isWaitingForAction()) { downButton.setWaitingForAction(0); systemMenu.scroll(1); }
  else if (selectButton.isWaitingForAction()) {
    selectButton.setWaitingForAction(0);
    int nextState = systemMenu.select();
    if (nextState == 1) { state = DryRun; }
    else if (nextState == 2) { state = RealRun; }
    else if (nextState == 3) { state = NoJob; }
  }
}


ISR(TIMER1_COMPA_vect) {

  //Xmotor needs to update

  if (toolpath.getXposition() != toolpath.getXtarget()) {
    toolpath.Xstep();
    toolpath.setXmoving(1);
  }
  else {
    turnOffTimer1();
    toolpath.setXmoving(0);
  }

  return;

}

ISR(TIMER3_COMPA_vect) {

  //Ymotor needs to update

  if (toolpath.getYposition() != toolpath.getYtarget()) {
    toolpath.Ystep();
    toolpath.setYmoving(1);
  }
  else {
    turnOffTimer3();
    toolpath.setYmoving(0);
  }

  return;

}

//user input buttons
ISR(PCINT0_vect) {

  //snapShot
  char port = PINB;

  if (upButton.isPressed(port)) { upButton.setWaitingForAction(1); }
  else if (downButton.isPressed(port)) { downButton.setWaitingForAction(1); }
  else if (selectButton.isPressed(port)) { selectButton.setWaitingForAction(1); }

  return;
}

//limit switches
ISR(PCINT2_vect) {

  //snapShot
  char port = PINK;

  int prevState = limitX0.getPrevState();
  if (limitX0.isPressed(port) && !prevState) {
    //bounce back a little - until the button is released
    toolpath.setXspeed(200);
    toolpath.moveXrel(100);
  } else if (limitX0.isReleased(port) && prevState) {
    toolpath.zeroXpos();
    toolpath.moveXabs(0);
  }

  prevState = limitY0.getPrevState();
  if (limitY0.isPressed(port) && !prevState) {
    //bounce back a little - until the button is released
    toolpath.setYspeed(200);
    toolpath.moveYrel(100);
  } else if (limitY0.isReleased(port) && prevState) {
    toolpath.zeroYpos();
    toolpath.moveYabs(0);
  }

  prevState = limitXF.getPrevState();
  if (limitXF.isPressed(port)) {
    turnOffTimer1();
    turnOffTimer3();
    toolpath.controlValve(0);
    toolpath.disableMotors();
    toolpath.setXmoving(0);
    toolpath.setYmoving(0);
    state = NoJob;
    char crash[21] = "CRASH - Job Ended";
    systemMenu.setStatusLine(crash);
    return;
  }

  prevState = limitYF.getPrevState();
  if (limitYF.isPressed(port) && !prevState) {
    turnOffTimer1();
    turnOffTimer3();
    toolpath.controlValve(0);
    toolpath.disableMotors();
    toolpath.setXmoving(0);
    toolpath.setYmoving(0);
    state = NoJob;
    char crash[21] = "CRASH - Job Ended";
    systemMenu.setStatusLine(crash);
    return;
  }

  return;

}
