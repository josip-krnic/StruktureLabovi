#ifndef STRUCT_H
#define STRUCT_H

#include "constants.h"
typedef struct Cvor* Position;
typedef struct Cvor {

	float f;
	Position Next;

} Cvor;

Position EndOfList(Position P);
int ProgramDescription();
int ProgramEndnote();
int NewElAfter(Position P, float F);
int NewElEnd(Position P, float F);
int PrintEl(Position P);
int PrintList(Position P);

int ProcessFile(char nameOfFile[MAX_STR_LEN], Position Pozn, int line);

int Add(Position P);
int Sub(Position P);
int Div(Position P);
int Mult(Position P);
int DelNextEl(Position P);
int DelAll(Position P);


#endif