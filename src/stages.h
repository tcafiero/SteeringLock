/*
 ============================================================================
 Name        : stages.h
 Author      : Toni Cafiero
 Version     :
 Copyright   : Holistic Systems all right reserved
 Description : Railway signalling in C, Ansi-style
 ============================================================================
 */
#ifndef STAGE_H
#define STAGE_H

#include "stages_table.h"

#ifdef OPTIMIZE
char *legalchar(const char *string);
#endif

#define X(a) a,
enum STAGE {
		STAGE_TABLE
};
#undef X

extern char *stage_name[];

extern enum STAGE Stage;

#define Stage_init Stage=StageInitial

#if OPTIMIZE
#define Stage_set(name)
#else
#ifdef STAGE_TRACE
#define Stage_set(name) {\
		if(result) {\
		printf("Stage from:%s to:%s\n",stage_name[Stage], stage_name[name]);\
		fflush(stdout);\
		Stage=name;\
		}\
	}
#else
#define Stage_set(name) {\
		if(result) Stage=name;\
	}

#endif
#endif


#ifdef OPTIMIZE
#ifdef OR
#undef OR
#define OR
#endif
#define check(name, value) printf("<CHECK>\n<NAME>%s</NAME>\n", legalchar(#name));\
	printf("<VALUE>%s</VALUE>\n</CHECK>\n", legalchar(# value));
#else
#ifdef OPTIMIZED
#define check(name, value)
#else
#define check(name, value) ( name == (value))
#endif
#endif

#define Stage_print printf("Stage = %s\n", stage_name[Stage]);

#endif
