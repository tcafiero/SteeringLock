/*
 ============================================================================
 Name        : stages.c
 Author      : Toni Cafiero
 Version     :
 Copyright   : Holistic Systems all right reserved
 Description : Railway signalling in C, Ansi-style
 ============================================================================
 */
#include "stages.h"

#define X(a) # a,
char *stage_name[] = {
		STAGE_TABLE
};
#undef X

enum STAGE Stage = StageInitial;

