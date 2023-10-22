#ifndef STRUCTS_H
#define STRUCTS_H

#include "constants.h"

struct _student;
typedef struct _student* Ptr;
typedef struct _student {
	char firstName[MAX_STR_LENGTH];
	char lastName[MAX_STR_LENGTH];
	int birthYear;
	Ptr next;
} Student;

Ptr initHead();
Ptr initElement(char firstName[MAX_STR_LENGTH], char lastName[MAX_STR_LENGTH], int year);
int addToBeginning(Ptr head, Ptr element);
int addToEnd(Ptr head, Ptr element);
int printList(Ptr head);
int menu(Ptr head);
int deleteAll(Ptr head);

#endif