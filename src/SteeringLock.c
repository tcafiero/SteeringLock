/*
 ============================================================================
 Name        : SteeringLock.c
 Author      : Toni Cafiero
 Version     :
 Copyright   : Holistic Systems all right reserved
 Description : Railway signalling in C, Ansi-style
 ============================================================================
 */
#define STAGE_TRACE


#include <stdio.h>
#include <stdlib.h>
#include "sysfun.h"
#include "signals.h"
#include "stages.h"

/* define here SYS_FUN behaviour */
void SYS_FUN_001(){
	SYS_FUN_entry;
	SYS_FUN_gate(Stage_check(StageInitial));
//	context(4 == 4, printf("zero\n"); printf("uno\n"); printf("due\n");, &= );
	SYS_FUN_exit;
}

void SYS_FUN_002(){
	SYS_FUN_entry;
	SYS_FUN_gate(Stage_check(NegativeUnlockFeedback) /* || Stage_check(NegativeUnlockFeedback) */);
	context(pippo_get() == pluto_get(), pluto_set(pluto_get()+1);, &= );
	Stage_set(StageInitial);
	SYS_FUN_exit;
}

void SYS_FUN_030(){
	SYS_FUN_entry;
	SYS_FUN_gate(Stage_check(StageInitial) /* || Stage_check(NegativeUnlockFeedback) */);
	context(s.BatteryValue > 7.0 && s.BatteryValue < 16.0 && !s.UnlockInProcess, ;, &=);
	Stage_set(NegativeUnlockFeedback);
	SYS_FUN_exit;
}
/* end of define SYS_FUN behaviour */

/* called once at startup */
void setup(void) {
	puts("Hello World!\n"); /* prints SteeringLock welcome */
	Stage_init;
}

/* called every 20 ms */
void loop(void)
{
	pippo_set(0);
	pluto_set(pippo_get());
	SYS_FUN_iterate();
	pluto_set(1);
	SYS_FUN_iterate();
	s.pluto=s.pippo;
	SYS_FUN_iterate();
	BatteryValue_set(9.0);
//	printBatteryValue();
	UnlockInProcess_set(0);
	SYS_FUN_iterate();
//	Stage_print;
	return;
}

