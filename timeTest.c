#define _POSIX_C_SOURCE 200809L

#define _DEFAULT_SOURCE//for usleep
#include <unistd.h>//for usleep

#include <inttypes.h>
#include <stdio.h>
#include <time.h>


void delay2(int milliseconds)//uses busy waiting
{
    struct timespec startTime;
    struct timespec currentTime;

    clock_gettime(CLOCK_REALTIME, &startTime);
    clock_gettime(CLOCK_REALTIME, &currentTime);

    uint32_t startMillis = 1000 * startTime.tv_sec + (startTime.tv_nsec / 1e6);
    uint32_t currentMillis = 1000 * currentTime.tv_sec + (currentTime.tv_nsec / 1e6);
    while (currentMillis - startMillis < milliseconds)
    {
        clock_gettime(CLOCK_REALTIME, &currentTime);
        currentMillis = 1000 * currentTime.tv_sec + (currentTime.tv_nsec / 1e6);
    }
}
void delay(int milliseconds)
{
    usleep(milliseconds*1000);
}
void main()
{
    float ms; // Milliseconds
    time_t s; // Seconds
    struct timespec startTime;
    struct timespec currentTime;

    clock_gettime(CLOCK_REALTIME, &startTime);
    clock_gettime(CLOCK_REALTIME, &currentTime);

    float startMS = startTime.tv_sec + ((float)(startTime.tv_nsec)) / 1e6;

    while (1)
    {
        delay2(250);
        printf("timeElapsed: \n");
    }
    //printf("timeElapsed: %i", timeElapsed);

    /*
    s  = startTime.tv_sec;
    ms = round(startTime.tv_nsec / 1.0e6); // Convert nanoseconds to milliseconds
    if (ms > 999) {
        s++;
        ms = 0;
    }
*/
}