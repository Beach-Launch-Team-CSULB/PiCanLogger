#ifndef CAN_PI_H   /* Include guard */
#define CAN_PI_H

//STD library stuff
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

//network stuff
#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/socket.h>

//CAN Stuff
#include <linux/can.h>
#include <linux/can/raw.h>

//this sets up CAN Receives and Sends
void canInit();

/* Read NBYTES into BUF from FD.  Return the
   number read, -1 for errors or 0 for EOF.

   This function is a cancellation point and therefore not marked with
   __THROW.  */
ssize_t readCan(struct can_frame frame);

#endif