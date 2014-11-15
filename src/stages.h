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

#define STAGE_TABLE \
	X(StageInitial)\
	X(NegativeUnlockFeedback)\
	X(ESLReceivesAValidUnlockCommand)\
	X(NegativeUnlockDiagnosticFeedback)\
	X(ESLStartsToPerformAnUnlockActuation)\
	X(ESLRecaivesAValidLockCommand)\
	X(ESLReceivesValidKeyOffSignals)\
	X(NegativeLockFeedback)\
	X(ESLReceivesSafeVSDValue)\
	X(ESLStartsToPerformALockActuation)

#define X(a) a,
enum STAGE {
		STAGE_TABLE
};
#undef X

#define X(a) # a,
char *stage_name[] = {
		STAGE_TABLE
};
#undef X

enum STAGE Stage = StageInitial;

#define initStage Stage=StageInitial

#define setStage(name) {\
		if(result) Stage=name;\
	}

#define checkStage(name) (Stage == (name))

#define printStage printf("Stage = %s\n", stage_name[Stage]);

#endif
