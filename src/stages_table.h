/*
 ============================================================================
 Name        : stages_table.h
 Author      : Toni Cafiero
 Version     :
 Copyright   : Holistic Systems all right reserved
 Description : Railway signalling in C, Ansi-style
 ============================================================================
 */

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
