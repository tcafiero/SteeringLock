/*
 ============================================================================
 Name        : signals.c
 Author      : Toni Cafiero
 Version     :
 Copyright   : IoThingsWare all rights reserved
 Description : Signal Management Engine in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include "signals.h"

#define X(name, type, spec) # name,
char *signal_name[] = {
		SIGNAL_TABLE
};
#undef X

Struct_signal s;

#define X(name, type, spec) type name ## _get()\
	{\
	return s.name;\
	}
	SIGNAL_TABLE
#undef X

#define X(name, type, spec) void name ## _set(type value)\
	{\
	s.name=value;\
	}
	SIGNAL_TABLE
#undef X


#define X(name, type, spec) void name ## _print()\
	{\
	printf( #name);\
	printf("=");\
	printf( # spec, s.name);\
	printf("\n");\
	}
	SIGNAL_TABLE
#undef X


/*
#define X(name, type, spec) void print ## name()\
	{\
	char format[128];\
	sprintf(format,""" %s = %s \n""", name, spec);\
	printf(format, s.name);\
	}
	SIGNAL_TABLE
#undef X
*/
/*
#define X(name, type, spec) void print ## name()\
	{\
	char format[128];\
	sprintf(format,"%s = %s \n", name, spec);\
	puts(format);\
	}
	SIGNAL_TABLE
#undef X
*/
