#include "button.h"

button::button(int pin) {

  prevState = 0;
  waitingForAction = 0;

  switch (pin) {

    case 10:
      DDRB &= ~(1 << DDB4);   //input
      PORTB |= (1 << PORTB4); //pullup enabled
      PCICR |= (1 << PCIE0);    //pin change interrupt
      PCMSK0 |= (1 << PCINT4);
      port = &PINB;
      portPin = 4;
      break;

    case 11:
      DDRB &= ~(1 << DDB5);   //input
      PORTB |= (1 << PORTB5); //pullup enabled
      PCICR |= (1 << PCIE0);    //pin change interrupt
      PCMSK0 |= (1 << PCINT5);
      port = &PINB;
      portPin = 5;
      break;

    case 12:
      DDRB &= ~(1 << DDB6);   //input
      PORTB |= (1 << PORTB6); //pullup enabled
      PCICR |= (1 << PCIE0);    //pin change interrupt
      PCMSK0 |= (1 << PCINT6);
      port = &PINB;
      portPin = 6;
      break;

    case 108: //A8
      DDRK &= ~(1 << DDK0);   //input
      PORTK |= (1 << PORTK0); //pullup enabled
      PCICR |= (1 << PCIE2);    //pin change interrupt
      PCMSK2 |= (1 << PCINT16);
      port = &PINK;
      portPin = 0;
      break;

    case 109: //A9
      DDRK &= ~(1 << DDK1);   //input
      PORTK |= (1 << PORTK1); //pullup enabled
      PCICR |= (1 << PCIE2);    //pin change interrupt
      PCMSK2 |= (1 << PCINT17);
      port = &PINK;
      portPin = 1;
      break;

    case 110: //A10
      DDRK &= ~(1 << DDK2);   //input
      PORTK |= (1 << PORTK2); //pullup enabled
      PCICR |= (1 << PCIE2);    //pin change interrupt
      PCMSK2 |= (1 << PCINT18);
      port = &PINK;
      portPin = 2;
      break;

    case 111: //A11
      DDRK &= ~(1 << DDK3);   //input
      PORTK |= (1 << PORTK3); //pullup enabled
      PCICR |= (1 << PCIE2);    //pin change interrupt
      PCMSK2 |= (1 << PCINT19);
      port = &PINK;
      portPin = 3;
      break;

  }

  return;

}

int button::isPressed(char inPort) {

  if (!(inPort & (1 << portPin))) {
    prevState = 1;
    return 1;
  } else {
    return 0;
  }

}

int button::isReleased(char inPort) {

  if (inPort & (1 << portPin)) {
    prevState = 0;
    return 1;
  } else {
    return 0;
  }

}

int button::getPrevState() { return prevState; }

bool button::isWaitingForAction() { return waitingForAction; }
void button::setWaitingForAction( bool x ) { waitingForAction = x; return; }
