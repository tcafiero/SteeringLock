/*
 ============================================================================
 Name        : SteeringLock.c
 Author      : Toni Cafiero
 Version     :
 Copyright   : Holistic Systems all right reserved
 Description : Railway signalling in C, Ansi-style
 ============================================================================
 */
#include <unistd.h>
#include <stdio.h>
void setup(void);
void loop(void);

int main(void) {
	setup();
	while(1)
	{
		loop();
		fflush(stdout);
		usleep(20000);
	}
	return 1;
}
