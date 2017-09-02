/*
 ============================================================================
 Name        : stages.c
 Author      : Toni Cafiero
 Version     :
 Copyright   : IoThingsWare all rights reserved
 Description : Signal Management Engine in C, Ansi-style
 ============================================================================
 */
#include "stages.h"

#define X(a) # a,
char *stage_name[] = {
		STAGE_TABLE
};
#undef X

enum STAGE Stage = StageInitial;

