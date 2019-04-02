#ifndef HEADER_HPP
#define HEADER_HPP

#include "mbed.h"

bool alert_on, all_clear;
enum position{red, green, yellow};
int position = red;
float time_positions[] = {10,20,4};
extern DigitalOut light[];
extern InterruptIn bt_lights;

Timeout timeout;
Timer timer;
Ticker ticker;

void clear();
void transition();
void alert();
void begin_timer();
void end_timer();

#endif