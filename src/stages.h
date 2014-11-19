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

#define X(a) a,
enum STAGE {
		STAGE_TABLE
};
#undef X

extern char *stage_name[];

extern enum STAGE Stage;

#define Stage_init Stage=StageInitial

#define Stage_set(name) {\
		if(result) Stage=name;\
	}

#define Stage_check(name) (Stage == (name))

#define Stage_print printf("Stage = %s\n", stage_name[Stage]);

#endif
