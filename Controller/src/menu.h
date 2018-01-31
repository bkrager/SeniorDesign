#ifndef MENU_H
#define MENU_H

#include <avr/io.h>
#include <Arduino.h>
#include "display.h"
#include "SDcard.h"
#include <SD.h>
#include "timer.h"
#include "XYtable.h"

typedef enum MenuEnum { INFOSCREEN, ROOTMENU, STARTJOBMENU, FILESMENU, XMENU, YMENU, XSPEED, YSPEED, XJOG, YJOG, OPTIONSTOP, EPOXYOPTIONS } MenuType;

class menu {
public:

  menu(XYtable* table);
  void infoscreen();
  int displayMenu(int line1);
  void scroll(int direction);
  int select();

  bool isInOptionStop();
  void setInOptionStop(bool x);

  //functions for changing lcd characters (menu specific)
  void displayNameLine();
  void displaySpeedLine();
  void displayProgressLine();
  void displayStatusLine();

  //functions for setting the displayed variables
  void setNameLine(int name);
  void setSpeedLine(int direction);
  void setProgressLine(int percent);
  void setStatusLine(char* Gline);

  File openGfile();



private:

  MenuType currentMenu;
  const char* rootMenu[11];
  const char* startJobMenu[4];
  const char* Xmenu[4];
  const char* Ymenu[4];
  const char* Xspeed[4];
  const char* Yspeed[4];
  const char* Xjog[4];
  const char* Yjog[4];
  const char* optionStop[4];
  const char* epoxyOptions[4];

  int Line;
  int Row;

  const char* GFileName;
  File GFile;
  File dir;

  XYtable* toolpath;
  display lcd;
  SDcard files;

  void XjogControl(int direction);
  void speedControl(int direction);
  void YjogControl(int direction);
  void optionStopControl(int direction);

  //infoscreen variables
  const char* nameLine;
  int progress;
  const char* statusLine;

  int jogSpeed;
  bool inOptionStop;    //not the option stop setting - this indicates if the program is currently in a stop


};



#endif
