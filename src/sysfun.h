/*
 ============================================================================
 Name        : sysfun.h
 Author      : Toni Cafiero
 Version     :
 Copyright   : Holistic Systems all right reserved
 Description : Railway signalling in C, Ansi-style
 ============================================================================
 */

#ifndef SYSFUN
#define SYSFUN

#ifndef  TRUE
#define TRUE 1
#endif
#ifndef FALSE
#define FALSE 0;
#endif

#include "sysfun_table.h"
#define X(name) void name();
	SYS_FUN_TABLE
#undef X

void SYS_FUN_iterate();


#define SYS_FUN_entry int result=1

#ifdef TRACE
#define SYS_FUN_exit printf("%s=%d\n", __func__, result );\
		return
#else
#define SYS_FUN_exit return
#endif

#define SYS_FUN_gate(condition) if(!(condition)) return

#define context(evaluation, action, contribution) {\
	if(evaluation) {action;}\
	result contribution (evaluation);\
}

#endif
