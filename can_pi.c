#include "can_pi.h"

int socketId;
int nbytes;
struct sockaddr_can addr;
struct ifreq ifr;
struct can_frame frame;

void canInit()
{
	printf("CAN Sockets Receive Demo\r\n");

	if ((socketId = socket(PF_CAN, SOCK_RAW, CAN_RAW)) < 0)
	{
		perror("Socket");
		//return 1;
	}

	strcpy(ifr.ifr_name, "can0");
	ioctl(socketId, SIOCGIFINDEX, &ifr);

	memset(&addr, 0, sizeof(addr));
	addr.can_family = AF_CAN;
	addr.can_ifindex = ifr.ifr_ifindex;

	if (bind(socketId, (struct sockaddr *)&addr, sizeof(addr)) < 0)
	{
		perror("Bind");
		//return 1;
	}
}

ssize_t readCan(struct can_frame frame)
{
	nbytes = read(socketId, &frame, sizeof(struct can_frame));

	if (nbytes < 0)
	{
		perror("Read");
		//return 1;
	}

	printf("0x%03X [%d] ", frame.can_id, frame.can_dlc);

	for (int i = 0; i < frame.can_dlc; i++)
		printf("%02X ", frame.data[i]);

	printf("\r\n");

	return nbytes;
}

void closeCan()
{
	if (close(socketId) < 0)
	{
		perror("Close");
		//return 1;
	}
}
/*
void main()
{
	canInit();
	while (1)
	{
		int nBytes = readCan(frame);
		printf("canRead: %i\n",nBytes);
	}
	
}
*/