#define _CRT_SECURE_NO_WARNINGS

#include "constants.h"
#include "struct.h"
#include <stdio.h>
#include <stdlib.h>

Position EndOfList(Position P) {

	while (P->Next != NULL) {
		P = P->Next;
	}
	return P;
}
int ProgramDescription() {

	printf(" #*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*\n");
	printf(" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf(" \n");
	printf(" This is a program for calculating postfix expression.\n");
	printf(" The values are loaded from a file.\n");
	printf(" \n");
	printf(" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf(" #*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*\n\n");
	return EXIT_SUCCESS;
}
int ProgramEndnote() {

	printf("\n\n #*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*\n");
	printf(" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf(" \n");
	printf(" End of program.\n");
	printf(" \n");
	printf(" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf(" #*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*\n\n");
	return EXIT_SUCCESS;
}
int NewElAfter(Position P, float F) {

	Position Q = malloc(sizeof(struct Cvor));

	if (Q == NULL)
	{
		printf("\n\nMemory allocation unsuccessful.\n\n\n");
		return EXIT_FAILURE;
	}

	Q->f = F;

	Q->Next = P->Next;
	P->Next = Q;

	return EXIT_SUCCESS;
}
int NewElEnd(Position P, float F) {
	P = EndOfList(P);
	NewElAfter(P, F);
	printf("\n\nNew element created!\n\n\n");
}
int PrintEl(Position P) {
	//P = P->Next;
	printf("%f ", P->f);
	return EXIT_SUCCESS;
}
int PrintList(Position P) {

	P = P->Next;

	if (P == NULL) {

		printf("\nList is empty!!\n");
		return EXIT_SUCCESS;
	}
	else {
		while (P != NULL) {
			PrintEl(P);
			P = P->Next;
		}

		printf("\n");
	}
	return EXIT_SUCCESS;
}

int ProcessFile(char nameOfFile[MAX_STR_LEN], Position Poz, int line)
{
	FILE* file = NULL;
	int  n, r, i, x;
	file = fopen(nameOfFile, "r");
	char buffer[MAX_STR_LEN] = { 0 };
	char* P = buffer;
	char c = ' ';
	float F = 0.0, f = 0;
	n = 1; r = 1; i = 0;

	if (file == NULL) {
		printf("\n\nNemoguce otvoriti datoteku.\n\n");
		return EXIT_FAILURE;
	}
	while (i < line) {
		fgets(buffer, MAX_STR_LEN, file);
		i++;
	}
	while (r != -1) {


		r = sscanf(P, " %f %n", &F, &n);

		if (r == 1) {
			NewElAfter(Poz, F);
		}
		else if (sscanf(P, " %c %n", &c, &n) == 1)
		{
			switch (c)
			{
			case '+':
				Add(Poz);
				break;
			case '-':
				Sub(Poz);
				break;
			case '*':
				Mult(Poz);
				break;
			case '/':
				Div(Poz);
				break;
			default:
				break;
			}
		}
		P += n * sizeof(char);
	}
	fclose(file);
	return EXIT_SUCCESS;
}

int Add(Position P) {

	P->Next->Next->f += P->Next->f;
	DelNextEl(P);
	return EXIT_SUCCESS;

}
int Sub(Position P) {

	P->Next->Next->f -= P->Next->f;
	DelNextEl(P);
	return EXIT_SUCCESS;

}
int Mult(Position P) {

	P->Next->Next->f *= P->Next->f;
	DelNextEl(P);
	return EXIT_SUCCESS;

}
int Div(Position P) {

	if (P->Next->f == 0)
	{
		printf("Division by zero is not allowed!!");
		return EXIT_FAILURE;
	}

	P->Next->Next->f /= P->Next->f;
	DelNextEl(P);
	return EXIT_SUCCESS;

}
int DelNextEl(Position P) {

	Position temp = NULL;

	if (P->Next == NULL) {

		printf("\nElement was not found!\n");
		return EXIT_FAILURE;
	}
	temp = P->Next;
	P->Next = P->Next->Next;

	free(temp);
	//printf("\nDeleted 1 element!\n");
	return EXIT_SUCCESS;
}
int DelAll(Position P) {

	int i = 0;
	if (P->Next == NULL)
	{
		printf("List is empty!! Success?\n");
		return EXIT_SUCCESS;
	}
	while (P->Next != NULL) {
		DelNextEl(P);
		i++;
	}
	if (i == 1) {
		printf("Deleted list! Deleted %i entry.\n", i);
	}
	else {
		printf("Deleted list! Deleted %i entries.\n", i);
	}

	return EXIT_SUCCESS;
}