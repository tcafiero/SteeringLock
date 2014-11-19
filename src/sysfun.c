/*
 ============================================================================
 Name        : sysfun.c
 Author      : Toni Cafiero
 Version     :
 Copyright   : Holistic Systems all right reserved
 Description : Railway signalling in C, Ansi-style
 ============================================================================
 */
#include "sysfun.h"

#define X(name) name();
void SYS_FUN_iterate(){
	SYS_FUN_TABLE
}
#undef X
