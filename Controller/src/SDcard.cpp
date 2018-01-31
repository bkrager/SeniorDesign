#include "SDcard.h"


int SDcard::listFiles(display lcd, int line1) {
  //returns number of files below (and including) the line selected as line1

  //clear Display
  lcd.clearDisplay();

  int i = 0;
  int numFilesLeft = 0;

  File dir = SD.open("/");
  dir.rewindDirectory();

  while (1) {

    File entry = dir.openNextFile();
    if (!entry) { break; }

    if (i >= line1) {
      if (i == 0) {
        lcd.writeAt("Back", i-line1, 1);
      } else {
        lcd.writeAt(entry.name(), i-line1, 1);
      }
      numFilesLeft++;
    }
    ++i;
    entry.close();

  }

  dir.close();

  return numFilesLeft;
}


SDcard::SDcard() {

  if (!SD.begin(53)) { return; }

  return;

}
