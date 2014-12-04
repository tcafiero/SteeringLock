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
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#ifdef OPTIMIZE
static char string2[4096];
char *str_replace(char *orig, char *rep, char *with)
{
//	int i;
	char *p;
	char *orig2;
	orig2=malloc(strlen(orig)+strlen(rep)+strlen(with));
	if(orig2 == NULL) return NULL;
	sprintf(orig2,"%s",orig);
	p=strstr(orig2, rep);
	if(p == NULL) {free(orig2); return NULL;}
//	i=p-orig2;
	p[0]=0;
	sprintf(string2,"%s%s%s",orig2,with,&p[strlen(rep)]);
	str_replace(string2, rep, with);
	free(orig2);
	return string2;
	}
char *legalchar(const char *string)
{
	strcpy(string2,string);
	str_replace(string2, "\x26", "abadcafe");
	str_replace(string2, "\x22", "&quot;");
	str_replace(string2, "abadcafe", "&amp;");
	str_replace(string2, "\x27", "&apos;");
	str_replace(string2, "\x3C", "&lt;");
	str_replace(string2, "\x3E", "&gt;");
	return string2;
}
#endif

#define X(name) name();
void SYS_FUN_iterate(){
	SYS_FUN_TABLE
}
#undef X
