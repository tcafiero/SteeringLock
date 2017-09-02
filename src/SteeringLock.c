/*
 ============================================================================
 Name        : SteeringLock.c
 Author      : Toni Cafiero
 Version     :
 Copyright   : IoThingsWare all rights reserved
 Description : Signal Management Engine in C, Ansi-style
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
//	SYS_FUN_gate(check(Stage,StageInitial));
//	context(4 == 4, printf("zero\n"); printf("uno\n"); printf("due\n");, &= );
	SYS_FUN_exit;
}

void SYS_FUN_002(){
	SYS_FUN_entry;
	SYS_FUN_gate(check(Stage,NegativeUnlockFeedback) OR check(Stage,StageInitial));
	context(pippo_get() == pluto_get(), pluto_set(pluto_get()+1);, && );
	Stage_set(StageInitial);
	SYS_FUN_exit;
}

void SYS_FUN_030(){
	SYS_FUN_entry;
	SYS_FUN_gate(check(Stage, StageInitial));
	context(s.BatteryValue > 7.0 && s.BatteryValue < 16.0 && !s.UnlockInProcess, ;, && );
	Stage_set(NegativeUnlockFeedback);
	SYS_FUN_exit;
}
/* end of define SYS_FUN behaviour */

/* called once at startup */
void setup(void) {
	puts("Hello World!\n"); /* prints SteeringLock welcome */
	Stage_init;
	pippo_set(0);
	pluto_set(pippo_get());
	Stage=NegativeUnlockFeedback;
}

/* called every 20 ms */
void loop(void)
{
#if 0
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
#endif
	BatteryValue_set(9.0);
	UnlockInProcess_set(0);
#ifdef OPTIMIZED
	SYS_FUN_iterate_optimized();
#else
	SYS_FUN_iterate();
#endif
//	Stage_print;
	return;
}

