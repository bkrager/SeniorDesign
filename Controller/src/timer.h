#ifndef TIMER_H
#define TIMER_H

#include <avr/io.h>

// X-axis is run on timer 1
// Y-Axis is run on timer 3
// Pump is run on timer 4

void initTimer0();
void delayMs(int ms);
void initTimer1();
void initTimer3();
void initTimers();

void changePeriod1(int multiplesOf64us);
void changePeriod3(int multiplesOf64us);

void turnOnTimer1();
void turnOffTimer1();
void turnOnTimer3();
void turnOffTimer3();

#endif
