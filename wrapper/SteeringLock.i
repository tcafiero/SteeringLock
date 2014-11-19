%module steeringlock


%inline %{
#define SIGNAL_TABLE \
	X(BatteryValue, float, %f)\
	X(UnlockInProcess, int, %d)\
	X(pippo, int, %d)\
	X(pluto, int, %d)\

#define X(name, type, spec) type name;
typedef struct {
		SIGNAL_TABLE
}Struct_signal;
#undef X

extern void SYS_FUN_iterate();
extern Struct_signal s;
%}



