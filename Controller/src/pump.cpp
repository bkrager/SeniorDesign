#include "pump.h"

pump::pump() {

  // set outputs
  DDRE |= (1 << DDE4);

  // initialize to zero
  PORTE &= ~(1 << PORTE4);

  return;

}

void pump::control(bool onoff) {

  if (onoff) {
    PORTE |= (1 << PORTE4);
  } else {
    PORTE &= ~(1 << PORTE4);
  }
}
