/*
 ============================================================================
 Name        : sysfun.h
 Author      : Toni Cafiero
 Version     :
 Copyright   : IoThingsWare all rights reserved
 Description : Signal Management Engine in C, Ansi-style
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

#ifdef OPTIMIZED
#define OR
#else
#define OR ||
#endif


#include "sysfun_table.h"
#define X(name) void name();
	SYS_FUN_TABLE
#undef X

#ifdef OPTIMIZE
char *legalchar(const char *string);
#endif

#ifdef OPTIMIZED
	void SYS_FUN_iterate_optimized();
#else
	void SYS_FUN_iterate();
#endif

#ifdef OPTIMIZE
#define SYS_FUN_entry printf("<SYS_FUN NAME=\"%s\">\n", legalchar(__func__))
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
#define SYS_FUN_gate(condition) printf("<GATE>\n");\
			condition\
			printf("</GATE>\n")
#else
#ifdef OPTIMIZED
#define SYS_FUN_gate(condition)
#else
#define SYS_FUN_gate(condition) if(!(condition)) return
#endif
#endif

#ifdef OPTIMIZE
#define context(evaluation, action, contribution) printf("<CONTEXT>\n<EVALUATION>%s</EVALUATION>\n",legalchar(#evaluation));\
		printf("<ACTION>%s</ACTION>\n",legalchar(#action));\
		printf("<CONTRIBUTION>%s</CONTRIBUTION>\n</CONTEXT>\n",legalchar(#contribution))
#else
#define context(evaluation, action, contribution) {\
	result = result contribution (evaluation);\
	if(evaluation) {action;}\
}
#endif

#endif
