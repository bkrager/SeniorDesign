#include "menu.h"


menu::menu(XYtable* table) {

  //INFOSCREEN, ROOTMENU, STARTJOBMENU, FILESMENU, XMENU, YMENU, XSPEED, YSPEED, XJOG, YJOG, OPTIONSTOP, EPOXYOPTIONS

  currentMenu = INFOSCREEN;
  toolpath = table;
  Line = 0;
  Row = 0;

  jogSpeed = 10;

  nameLine = "Epoxy Dispenser";
  progress = 0;
  statusLine = "Ready for Next Job";
  inOptionStop = 0;

  rootMenu[0] = "Back To Info Screen";
  rootMenu[1] = "Select File";
  rootMenu[2] = "Pause Current Job";
  rootMenu[3] = "Stop Current Job";
  rootMenu[4] = "Resume Job";
  rootMenu[5] = "Epoxy Options";
  rootMenu[6] = "Return to Home Position";
  rootMenu[7] = "Unlock Motors";
  rootMenu[8] = "Position X Axis";
  rootMenu[9] = "Position Y Axis";
  rootMenu[10] = "Optional Stop";

  startJobMenu[0] = "Back";
  startJobMenu[1] = "Dry Run (no epoxy)";
  startJobMenu[2] = "Start Job";
  startJobMenu[3] = "";

  Xmenu[0] = "Back";
  Xmenu[1] = "Set Jog Speed";
  Xmenu[2] = "Set Position";
  Xmenu[3] = "Auto Home";

  Ymenu[0] = "Back";
  Ymenu[1] = "Set Jog Speed";
  Ymenu[2] = "Set Position";
  Ymenu[3] = "Auto Home";

  Xspeed[0] = "";
  Xspeed[1] = "Jog Speed = ";
  Xspeed[2] = "";
  Xspeed[3] = "Select to go Back";

  Yspeed[0] = "";
  Yspeed[1] = "Jog Speed = ";
  Yspeed[2] = "";
  Yspeed[3] = "Select to go Back";

  Xjog[0] = "";
  Xjog[1] = "X-Axis Pos = ";
  Xjog[2] = "";
  Xjog[3] = "Select to go Back";

  Yjog[0] = "";
  Yjog[1] = "Y-Axis Pos = ";
  Yjog[2] = "";
  Yjog[3] = "Select to go Back";

  optionStop[0] = "";
  optionStop[1] = "Optional Stop: ";
  optionStop[2] = "";
  optionStop[3] = "Select to go Back";

  epoxyOptions[0] = "Back";
  epoxyOptions[1] = "Run Epoxy";
  epoxyOptions[2] = "Shut Off Epoxy";
  epoxyOptions[3] = "";

  return;
}

void menu::infoscreen() {

  if (currentMenu == INFOSCREEN) {

    //clear Display
    lcd.clearDisplay();

    lcd.writeAt(nameLine, 0, 0);
    lcd.writeAt("Speed:    %", 1, 0);
    lcd.writeAt("Progress:    %", 2, 0);
    lcd.writeAt(statusLine, 3, 0);

    //write speed and progress
    displaySpeedLine();
    displayProgressLine();

    return;

  }

}

//functions for changing lcd characters in infoscreen
void menu::displayNameLine() {
  if (currentMenu == INFOSCREEN) {
    lcd.writeAt("                    ", 0, 0);
    lcd.writeAt(nameLine, 0, 0);
  }
  return;
}
void menu::displaySpeedLine() {
  if (currentMenu == INFOSCREEN) {
    //write new speed on lcd
    int speed = toolpath->getSpeedFactor();
    const char* clearLine = "   ";      //3 spaces to clear previous data
    lcd.writeAt(clearLine, 1, 7);

    char s[10] = "";
    char* dataLine = itoa(speed, s, 10);
    lcd.writeAt(dataLine, 1, 7);
  }
  return;
}
void menu::displayProgressLine() {
  if (currentMenu == INFOSCREEN) {
    //write new percent on lcd
    const char* clearLine = "   ";      //3 spaces to clear previous data
    lcd.writeAt(clearLine, 2, 10);

    char s[10] = "";
    char* dataLine = itoa(progress, s, 10);
    lcd.writeAt(dataLine, 2, 10);
  }
  return;
}
void menu::displayStatusLine() {
  if (currentMenu == INFOSCREEN) {
    lcd.writeAt("                    ", 3, 0);
    lcd.writeAt(statusLine, 3, 0);
  }
}

//functions for setting the displayed variables in infoscreen
void menu::setNameLine(int name) { if (name) { nameLine = GFileName; } else { nameLine = "Epoxy Dispenser"; } displayNameLine(); return; }
void menu::setSpeedLine(int direction) {

  //In Optionstop, up button resumes, down button skips
  if (inOptionStop) {
    if (direction == -1) {
      inOptionStop = 0;
    } else if (direction == 1) {
      inOptionStop = 0;
      toolpath->setSkipping(1);
    }
    return;
  }

  direction = -direction;

  //change speed by a 4% increment
  toolpath->changeSpeedFactor(4 * direction);
  displaySpeedLine();

  return;

}
void menu::setProgressLine(int percent)  { progress = percent; displayProgressLine(); return; }
void menu::setStatusLine(char* Gline) { statusLine = Gline; displayStatusLine(); return; }

//functions for changing variables and lcd on non-infoscreen menus
void menu::XjogControl(int direction) {

  direction = -direction;

  //wait for last jog to end
  if (!toolpath->isMoving()) {

    //jog
    toolpath->linearMoveRel(direction * jogSpeed, 0);

    //write new position on lcd
    int pos = toolpath->getXposition() + direction * jogSpeed;
    const char* clearLine = "       ";      //7 spaces to clear previous data
    lcd.writeAt(clearLine, 1, 13);

    char s[10] = "";
    char* dataLine = itoa(pos, s, 10);
    lcd.writeAt(dataLine, 1, 13);
  }

  return;

}
void menu::speedControl(int direction) {

  direction = -direction;

  //wait for last jog to end
  if (!toolpath->isMoving()) {

    //change speed (really an increment)
    jogSpeed += direction;
    if (jogSpeed < 1) { jogSpeed = 1; }

    //write new speed on lcd
    const char* clearLine = "        ";      //8 spaces to clear previous data
    lcd.writeAt(clearLine, 1, 12);

    char s[10] = "";
    char* dataLine = itoa(jogSpeed, s, 10);
    lcd.writeAt(dataLine, 1, 12);
  }

  return;

}
void menu::YjogControl(int direction) {

  direction = -direction;

  //wait for last jog to end
  if (!toolpath->isMoving()) {

    //jog
    toolpath->linearMoveRel(0, direction * jogSpeed);

    //write new position on lcd
    int pos = toolpath->getYposition() + direction * jogSpeed;
    const char* clearLine = "       ";      //7 spaces to clear previous data
    lcd.writeAt(clearLine, 1, 13);

    char s[10] = "";
    char* dataLine = itoa(pos, s, 10);
    lcd.writeAt(dataLine, 1, 13);
  }

  return;

}
void menu::optionStopControl(int direction) {

  //change setting
  if (direction) {
    toolpath->setOptionStop(!toolpath->getOptionStop());
  }

  //write new setting on lcd
  const char* data = "   ";
  if (toolpath->getOptionStop()) { data = "ON "; } else { data = "OFF"; }
  lcd.writeAt(data, 1, 15);

  return;

}

//displays currentMenu beginning with line indicated line1
int menu::displayMenu(int line1) {

  //clear Display
  lcd.clearDisplay();

  int i = 0;
  int numLinesLeft = 0;

  switch (currentMenu) {

    case INFOSCREEN:
      infoscreen();
      break;

    case ROOTMENU:
      for (i = 0; i < 11; i++) {
        if (i >= line1) {
          lcd.writeAt(rootMenu[i], i-line1, 1);
          numLinesLeft++;
        }
      }
      break;

    case STARTJOBMENU:
      for (i = 0; i < 4; i++) {
        if (i >= line1) {
          lcd.writeAt(startJobMenu[i], i-line1, 1);
          numLinesLeft++;
        }
      }
      break;

    case FILESMENU:
      numLinesLeft = files.listFiles(lcd, line1);
      break;

    case XMENU:
      for (i = 0; i < 4; i++) {
        if (i >= line1) {
          lcd.writeAt(Xmenu[i], i-line1, 1);
          numLinesLeft++;
        }
      }
      break;

    case YMENU:
      for (i = 0; i < 4; i++) {
        if (i >= line1) {
          lcd.writeAt(Ymenu[i], i-line1, 1);
          numLinesLeft++;
        }
      }
      break;

    case XSPEED:
      for (i = 0; i < 4; i++) {
        if (i >= line1) {
          lcd.writeAt(Xspeed[i], i-line1, 0);
          numLinesLeft++;
        }
      }
      speedControl(0);
      break;

    case YSPEED:
      for (i = 0; i < 4; i++) {
        if (i >= line1) {
          lcd.writeAt(Yspeed[i], i-line1, 0);
          numLinesLeft++;
        }
      }
      speedControl(0);
      break;

    case XJOG:
      for (i = 0; i < 4; i++) {
        if (i >= line1) {
          lcd.writeAt(Xjog[i], i-line1, 0);
          numLinesLeft++;
        }
      }
      XjogControl(0);
      break;

    case YJOG:
      for (i = 0; i < 4; i++) {
        if (i >= line1) {
          lcd.writeAt(Yjog[i], i-line1, 0);
          numLinesLeft++;
        }
      }
      YjogControl(0);
      break;

    case OPTIONSTOP:
      for (i = 0; i < 4; i++) {
        if (i >= line1) {
          lcd.writeAt(optionStop[i], i-line1, 0);
          numLinesLeft++;
        }
      }
      optionStopControl(0);
      break;

    case EPOXYOPTIONS:
      for (i = 0; i < 4; i++) {
        if (i >= line1) {
          lcd.writeAt(epoxyOptions[i], i-line1, 1);
          numLinesLeft++;
        }
      }
      break;

  }

  if ((currentMenu != INFOSCREEN) && (currentMenu != XSPEED) && (currentMenu != YSPEED) && (currentMenu != XJOG) && (currentMenu != YJOG) && (currentMenu != OPTIONSTOP)) {    //no cursor on these menus
    lcd.moveCursor(Row, 0, 1);
  }

  return numLinesLeft;

}
//scroll and select
void menu::scroll(int direction) {

  //different function for these menus
  if (currentMenu == INFOSCREEN) { setSpeedLine(direction); return; }
  if (currentMenu == XSPEED) { speedControl(direction); return; }
  if (currentMenu == YSPEED) { speedControl(direction); return; }
  if (currentMenu == XJOG) { XjogControl(direction); return; }
  if (currentMenu == YJOG) { YjogControl(direction); return; }
  if (currentMenu == OPTIONSTOP) { optionStopControl(direction); return; }

  Line += direction;
  Row += direction;

  if (Line < 0) { Line = 0; }
  if (Row < 0) { Row = 0; }
  if (Row > 3) { Row = 3; }

  int numFilesLeft = displayMenu(Line - Row);
  if (numFilesLeft < 4) {
    Line = Line - 4 + numFilesLeft;
    displayMenu(Line - Row);
  }

  lcd.moveCursor(Row, 0, 1);

  return;

}
int menu::select() {

  char stopped[21] = "Program Stopped";

  switch(currentMenu) {

    case INFOSCREEN:
      currentMenu = ROOTMENU;
      Line = 0; Row = 0;
      displayMenu(0);
      break;

    case ROOTMENU:
      switch(Line) {

        case 0:   //back to info screen
          currentMenu = INFOSCREEN;
          Line = 0; Row = 0;
          displayMenu(0);
          break;

        case 1:   //file menu
          currentMenu = FILESMENU;
          Line = 0; Row = 0;
          displayMenu(0);
          break;

        case 2:   //pause
          turnOffTimer1();
          turnOffTimer3();
          toolpath->controlValve(0);
          break;

        case 3:   //Stop
          turnOffTimer1();
          turnOffTimer3();
          toolpath->controlValve(0);
          toolpath->setXmoving(0);
          toolpath->setYmoving(0);
          currentMenu = INFOSCREEN;
          setStatusLine(stopped);
          Line = 0; Row = 0;
          displayMenu(0);
          return 3; //return to NoJob state
          break;

        case 4:     //Resume
          turnOnTimer1();
          turnOnTimer3();
          currentMenu = INFOSCREEN;
          Line = 0; Row = 0;
          displayMenu(0);
          break;

        case 5:     //epoxy Options Menu
          currentMenu = EPOXYOPTIONS;
          Line = 0; Row = 0;
          displayMenu(0);
          break;

        case 6:     //return to home;
          toolpath->home();
          break;

        case 7:   //disable motors
          toolpath->disableMotors();
          break;

        case 8:   //position X Axis
          currentMenu = XMENU;
          Line = 0; Row = 0;
          displayMenu(0);
          break;

        case 9:   //position Y Axis
          currentMenu = YMENU;
          Line = 0; Row = 0;
          displayMenu(0);
          break;

        case 10:    //option stop
          currentMenu = OPTIONSTOP;
          Line = 0; Row = 0;
          displayMenu(0);
          break;
      }
      break;

    case STARTJOBMENU:
      switch(Line) {

        case 0:     //Back
          currentMenu = FILESMENU;
          Line = 0; Row = 0;
          displayMenu(0);
          break;

        case 1:     //dry run
          currentMenu = INFOSCREEN;
          Line = 0; Row = 0;
          displayMenu(0);
          return 1; //begin dry run
          break;

        case 2:     //real run
          currentMenu = INFOSCREEN;
          Line = 0; Row = 0;
          displayMenu(0);
          return 2; //begin real run
          break;

      }
      break;

    case FILESMENU:
      switch(Line) {

        case 0:     //Back
          currentMenu = ROOTMENU;
          Line = 0; Row = 0;
          displayMenu(0);
          break;

        default:
          dir = SD.open("/");
          dir.rewindDirectory();
          for (int i = 0; i <= Line; ++i) {
            GFile = dir.openNextFile();
            GFile.close();
          }
          dir.close();
          GFileName = GFile.name();
          currentMenu = STARTJOBMENU;
          Line = 0; Row = 0;
          displayMenu(0);
          break;
      }
      break;

    case XMENU:
      switch(Line) {
        case 0:     //back
          currentMenu = ROOTMENU;
          Line = 0; Row = 0;
          displayMenu(0);
          break;

        case 1:     //set jog speed
          currentMenu = XSPEED;
          Line = 0; Row = 0;
          displayMenu(0);
          break;

        case 2:     //set position
          currentMenu = XJOG;
          Line = 0; Row = 0;
          displayMenu(0);
          break;

        case 3:     //Auto home
          toolpath->homeX();
          break;
      }
      break;

    case YMENU:
      switch(Line) {
        case 0:     //back
          currentMenu = ROOTMENU;
          Line = 0; Row = 0;
          displayMenu(0);
          break;

        case 1:     //set jog speed
          currentMenu = YSPEED;
          Line = 0; Row = 0;
          displayMenu(0);
          break;

        case 2:     //set position
          currentMenu = YJOG;
          Line = 0; Row = 0;
          displayMenu(0);
          break;

        case 3:     //Auto home
          toolpath->homeY();
          break;
      }
      break;

    case XSPEED:
      currentMenu = XMENU;
      Line = 0; Row = 0;
      displayMenu(0);
      break;

    case YSPEED:
      currentMenu = YMENU;
      Line = 0; Row = 0;
      displayMenu(0);
      break;

    case XJOG:
      currentMenu = XMENU;
      Line = 0; Row = 0;
      displayMenu(0);
      break;

    case YJOG:
      currentMenu = YMENU;
      Line = 0; Row = 0;
      displayMenu(0);
      break;

    case OPTIONSTOP:
      currentMenu = ROOTMENU;
      Line = 0; Row = 0;
      displayMenu(0);
      break;

    case EPOXYOPTIONS:
      switch (Line) {
        case 0: //Back
          currentMenu = ROOTMENU;
          Line = 0; Row = 0;
          displayMenu(0);
          break;

        case 1: //Run Epoxy
          toolpath->controlValve(1);
          break;

        case 2: //shut off epoxy
          toolpath->controlValve(0);
          break;
      }



    }

    return 0;
}


bool menu::isInOptionStop() { return inOptionStop; }
void menu::setInOptionStop(bool x) { inOptionStop = x; return; }

File menu::openGfile() {

  return SD.open(GFileName, FILE_READ);

}
