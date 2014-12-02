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
#include "stages.h"


void setup(void);
void loop(void);


int main(void) {
#ifdef OPTIMIZE
	Stage_init;
	printf("<?xml version=\"1.0\" encoding=\"utf-8\"?>\n");
	printf("<SYSTEM>\n");
	SYS_FUN_iterate();
	printf("</SYSTEM>\n");
#else
	setup();
	while(1)
	{
		loop();
		fflush(stdout);
		usleep(20000);
	}
#endif
	return 1;
}
