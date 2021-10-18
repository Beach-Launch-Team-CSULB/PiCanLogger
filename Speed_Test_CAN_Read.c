#include "can_pi.h"
#include "simple_pi_time.h"
struct can_frame msg;

void main()
{
	canInit();
	uint32_t startTime = millis(),
			 lastReceivedTime = millis(),
			 canCount = 0;

	//delay(1000);
	//Serial.println(CANbus0.available());
	if (millis() - lastReceivedTime > 100)
	{
		if (canCount > 0)
		{
			double secondsElapsed = (millis() - startTime) / 1000.0;
			printf("canCount: %i\n", canCount);
			printf("seconds: %i\n", secondsElapsed);

			double framesPerSecond = canCount / secondsElapsed;
			printf("Frames/S: %d\n", framesPerSecond);
			printf("effectiveBitrate: %i\n\n", (64 + 31) * framesPerSecond);
			printf("Teensy 3.6 can bus SPEED test");

			canCount = 0;
		}

		startTime = millis();
	}

	//if (CANbus0.available())
	//{
	readCan(msg);
	lastReceivedTime = millis();
	canCount++;
	//Serial.print("CAN bus 0: ");
	//printData(msg);
	if (msg.can_id != 0xAA)
		printf("ERROR, ID: %i Doesn't match 0xAA\n",msg.can_id);

	bool copyError = false;
	for (int i = 0; i < msg.can_dlc; i++)
		if (msg.data[i] != 128)
			copyError = true;
	if (copyError)
		printf("ERROR IN DATA\n");

	//Serial.print("ID: ");
	//Serial.println(msg.id, HEX);
}
