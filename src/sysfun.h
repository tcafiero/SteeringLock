/*
 ============================================================================
 Name        : sysfun.h
 Author      : Toni Cafiero
 Version     :
 Copyright   : Holistic Systems all right reserved
 Description : Railway signalling in C, Ansi-style
 ============================================================================
 */

#ifndef SYSFUN
#define SYSFUN

#ifndef  TRUE
#define TRUE 1
#endif
#ifndef FALSE
#define FALSE 0;
#endif


#define entrySYS_FUN int result=1

#ifdef TRACE
#define exitSYS_FUN printf("%s=%d\n", __func__, result );\
		return result
#else
#define exitSYS_FUN return result
#endif

#define gateSYS_FUN(condition) if(!(condition)) return result

#define context(evaluation, action, contribution) {\
	if(evaluation) {action;}\
	result contribution (evaluation);\
}

#endif
