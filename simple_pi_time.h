#ifndef SIMPLE_PI_TIME_H   /* Include guard */
#define SIMPLE_PI_TIME_H

#define _POSIX_C_SOURCE 200809L
//#define _DEFAULT_SOURCE //for usleep
//#include <unistd.h>     //for usleep
#include <stdbool.h>    //for bool

#include <inttypes.h>
#include <stdio.h>
#include <time.h>

/*
returns either the time since millisInit() was called or the
time since millis() was first called if millisInit() was
never called.
*/
uint32_t millis();
void millisInit();//millis will return the time since when this was called

int delay(long milliseconds);

#endif //SIMPLE_PI_TIME_H