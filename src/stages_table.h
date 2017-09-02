/*
 ============================================================================
 Name        : stages_table.h
 Author      : Toni Cafiero
 Version     :
 Copyright   : IoThingsWare all rights reserved
 Description : Signal Management Engine in C, Ansi-style
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
