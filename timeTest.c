#include "simple_pi_time.h"

struct timespec startTime;
struct timespec currentTime;

void main()
{

    while (1)
    {
        //clock_gettime(CLOCK_REALTIME, &currentTime);
        //printf("%i", currentTime.tv_sec);//works great, outputs seconds

        delay(100);
          
        printf("millis(): %i\n", millis());

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