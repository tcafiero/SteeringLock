/*
 ============================================================================
 Name        : SteeringLock.c
 Author      : Toni Cafiero
 Version     :
 Copyright   : Holistic Systems all right reserved
 Description : Railway signalling in C, Ansi-style
 ============================================================================
 */
#define TRACE

#include <stdio.h>
#include <stdlib.h>
#include "sysfun.h"
#include "signals.h"
#include "stages.h"
int a,b;


int SYS_FUN_001(){
	entrySYS_FUN;
	gateSYS_FUN(checkStage(StageInitial));
	context(4 == 4, printf("zero\n"); printf("uno\n"); printf("due\n");, &= );
	exitSYS_FUN;
}

int SYS_FUN_002(){
	entrySYS_FUN;
	gateSYS_FUN(checkStage(StageInitial) /* || checkStage(NegativeUnlockFeedback) */);
	context(a == b, ;, &= );
	exitSYS_FUN;
}

int SYS_FUN_030(){
	entrySYS_FUN;
	gateSYS_FUN(checkStage(StageInitial) /* || checkStage(NegativeUnlockFeedback) */);
	context(s.BatteryValue > 7.0 && s.BatteryValue < 16.0 && !s.UnlockInProcess, ;, &=);
	setStage(NegativeUnlockFeedback);
	exitSYS_FUN;
}


void setup(void) {
	puts("Hello World!\n"); /* prints SteeringLock welcome */
	initStage;
}

void loop(void)
{
	SYS_FUN_001();
	a=0;
	b=a;
	SYS_FUN_002();
	b=1;
	SYS_FUN_002();
	setsignal(BatteryValue, 9.0);
	setsignal(UnlockInProcess, 0);
	SYS_FUN_030();
//	printStage;
	return;
}
