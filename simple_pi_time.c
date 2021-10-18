#include "simple_pi_time.h"

struct timespec startTime;
struct timespec currentTime;
bool initRun = 0;

void millisInit()
{
    clock_gettime(CLOCK_REALTIME, &startTime);
    initRun = 1;
}
uint32_t millis()
{
    if (!initRun)
        millisInit();
    clock_gettime(CLOCK_REALTIME, &currentTime);
    uint32_t currentMS = (currentTime.tv_sec - startTime.tv_sec) * 1000 + (currentTime.tv_nsec / 1e6);
    //printf("millis(): %i\n", currentMS);
    return currentMS;
}
/*
void delay(int milliseconds)
{
    usleep(milliseconds * 1000);
}*/

#include <time.h>
#include <errno.h>    

/* msleep(): Sleep for the requested number of milliseconds. */
int delay(long msec)
{
    struct timespec ts;
    int res;

    if (msec < 0)
    {
        errno = EINVAL;
        return -1;
    }

    ts.tv_sec = msec / 1000;
    ts.tv_nsec = (msec % 1000) * 1000000;

    do {
        res = nanosleep(&ts, &ts);
    } while (res && errno == EINTR);

    return res;
}