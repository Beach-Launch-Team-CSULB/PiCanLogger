#include "simple_pi_time.h"
#include "can_pi.h"

int main()
{
    printf("works great\n");
    int startTime = millis();    
    printf("currentTIme :%i\n",startTime);
    delay(1000);    
    printf("currentTIme :%i\n",millis());


}