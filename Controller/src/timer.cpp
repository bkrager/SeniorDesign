#include "timer.h"

void initTimer1() {

  //CTC mode
  TCCR1B |= (1 << WGM12);

  //prescaler of 1024
  TCCR1B |= ((1 << CS12) | (1 << CS10));

}

void initTimer3() {

  //CTC mode
  TCCR3B |= (1 << WGM32);

  //prescaler of 1024
  TCCR3B |= ((1 << CS32) | (1 << CS30));

}

void initTimer4() {

  //Phase and Freq correct PWM (WGM = 8)
  TCCR4B |= (1 << WGM43);

  //no prescalar
  TCCR4B |= (1 << CS40);

  //Set TOP value to 255 (for 62.5 kHz switching frequency)
  ICR4 = 255;



}

void initTimer5() {

  //Phase and Freq correct PWM (WGM = 8)
  TCCR5B |= (1 << WGM53);

  //no prescalar
  TCCR5B |= (1 << CS50);

  //Set TOP value to 255 (for 62.5 kHz switching frequency)
  ICR5 = 255;

}

void initTimers() {

  initTimer0();
  initTimer1();
  initTimer3();
  initTimer4();
  initTimer5();
  return;

}

void changePeriod1(int multiplesOf64us) {

  //set timer TOP value
  OCR1A = multiplesOf64us;

}

void changePeriod3(int multiplesOf64us) {

  //set timer TOP value
  OCR3A = multiplesOf64us;

}

void turnOnTimer1() {

  //enable interrupt
  TIMSK1 |= (1 << OCIE1A);
  //clear flag
  TIFR1 |= (1 << OCF1A);
  //reset timer
  TCNT1 = 0;

  return;

}

void turnOffTimer1() {

  //disable interrupt
  TIMSK1 &= ~(1 << OCIE1A);

}

void turnOnTimer3() {

  //enable interrupt
  TIMSK3 |= (1 << OCIE3A);
  //clear flag
  TIFR3 |= (1 << OCF3A);
  //reset timer
  TCNT3 = 0;

  return;

}
void turnOffTimer3() {

  //disable interrupt
  TIMSK3 &= ~(1 << OCIE3A);

}

void turnOnTimer4() {
  //enable interrupts for A, B, and C output compares
  TIMSK4 |= (1 << OCIE4A) | (1 << OCIE4B) | (1 << OCIE4C);
}
void turnOffTimer4() {
  //disable interrupts for A, B, and C output compares
  TIMSK4 &= ~((1 << OCIE4A) | (1 << OCIE4B) | (1 << OCIE4C));
}
void turnOnTimer5() {
  //enable interrupts for A, B, and C output compares
  TIMSK5 |= (1 << OCIE5A) | (1 << OCIE5B) | (1 << OCIE5C);
}
void turnOffTimer5() {
  //disable interrupts for A, B, and C output compares
  TIMSK5 &= ~((1 << OCIE5A) | (1 << OCIE5B) | (1 << OCIE5C));
}



void initTimer0() {

  TCCR0A |= (1 << WGM01);

}
void delayMs(int ms) {

  //prescaler = 64
  TCCR0B |= (1 << CS01) | (1 << CS00);

  //set comparison value to 250 (1ms)
  OCR0A = 250;

  //reset timer0
  TCNT0 = 0;

  //clear flag
  TIFR0 |= (1 << OCF0A);

  //loop for [delay] cycles
  int i = 0;
  for (i = 0; i < ms; ++i) {

    //reset timer0
    TCNT0 = 0;

    //poll for flag;
    while (!((TIFR0) & (1 << OCF0A))) {}

    //clear flag
    TIFR0 |= (1 << OCF0A);

  }

  return;

}
