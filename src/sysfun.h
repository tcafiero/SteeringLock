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

#ifdef OPTIMIZE
#define SYS_FUN_entry printf("<SYS_FUN>\n<NAME>%s</NAME>\n", __func__)
#else
#define SYS_FUN_entry int result=1
#endif

#ifdef OPTIMIZE
#define SYS_FUN_exit printf("</SYS_FUN>\n");\
		return
#else
#ifdef SYS_FUN_TRACE
#define SYS_FUN_exit printf("%s=%d\n", __func__, result );\
		return
#else
#define SYS_FUN_exit return
#endif
#endif

#ifdef OPTIMIZE
#define SYS_FUN_gate(condition) printf("<GATE>%s</GATE>\n", # condition)
#else
#define SYS_FUN_gate(condition) if(!(condition)) return
#endif

#ifdef OPTIMIZE
#define context(evaluation, action, contribution) printf("<CONTEXT><EVALUATION>%s</EVALUATION><ACTION>%s</ACTION><CONTRIBUTION>%s</CONTRIBUTION>\n", # evaluation, # action, # contribution)
#else
#define context(evaluation, action, contribution) {\
	result contribution (evaluation);\
	if(evaluation) {action;}\
}
#endif

#endif
