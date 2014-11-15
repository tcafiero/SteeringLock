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
	X(BatteryValue, float)\
	X(UnlockInProcess, int)

#define X(a, b) a,
enum SIGNAL {
		SIGNAL_TABLE
};
#undef X

#define X(a, b) # a,
char *signal_name[] = {
		SIGNAL_TABLE
};
#undef X

#define X(a, b) b a;
struct struct_signal{
		SIGNAL_TABLE
};
#undef X

struct struct_signal s;

#define signal(name) {\
	if(result) s.name=TRUE;\
}

#define printsignal(name) printf("%s = %d\n", signal_name[name], s.name);

#define setsignal(name, value) s.name=value


#endif
