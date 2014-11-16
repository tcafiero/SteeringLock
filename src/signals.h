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

#define SIGNAL_TABLE \
	X(BatteryValue, float, %f)\
	X(UnlockInProcess, int, %d)\
	X(pippo, int, %d)\
	X(pluto, int, %d)\

#define X(a, b, c) a,
enum SIGNAL {
		SIGNAL_TABLE
};
#undef X

#define X(a, b, c) # a,
char *signal_name[] = {
		SIGNAL_TABLE
};
#undef X

#define X(a, b, c) b a;
struct struct_signal{
		SIGNAL_TABLE
};
#undef X


struct struct_signal s;

#define X(name, type, spec) type get ## name()\
	{\
	return s.name;\
	}
	SIGNAL_TABLE
#undef X

#define X(name, type, spec) void set ## name(type value)\
	{\
	s.name=value;\
	}
	SIGNAL_TABLE
#undef X


#define X(name, type, spec) void print ## name()\
	{\
	printf( #name);\
	printf("=");\
	printf( # spec, s.name);\
	printf("\n");\
	}
	SIGNAL_TABLE
#undef X


#endif
