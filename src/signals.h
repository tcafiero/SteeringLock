/*
 ============================================================================
 Name        : signals.h
 Author      : Toni Cafiero
 Version     :
 Copyright   : Holistic Systems all right reserved
 Description : Railway signalling in C, Ansi-style
 ============================================================================
 */

#ifndef SINGNALS
#define SIGNALS
#include "signal_table.h"

#define X(name, type, spec) name,
enum SIGNAL {
		SIGNAL_TABLE
};
#undef X


#define X(name, type, spec) type name;
typedef struct {
		SIGNAL_TABLE
}Struct_signal;
#undef X

extern char *signal_name[];
extern Struct_signal s;

#define X(name, type, spec) type name ## _get();
	SIGNAL_TABLE
#undef X

#define X(name, type, spec) void name ## _set(type value);
	SIGNAL_TABLE
#undef X


#define X(name, type, spec) void name ## _print();
	SIGNAL_TABLE
#undef X

#endif
