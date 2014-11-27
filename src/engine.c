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
#include "sysfun.h"


void setup(void);
void loop(void);


int main(void) {
	setup();
#ifdef OPTIMIZE
  SYS_FUN_iterate();
#else
	while(1)
	{
		loop();
		fflush(stdout);
		usleep(20000);
	}
#endif
	return 1;
}
