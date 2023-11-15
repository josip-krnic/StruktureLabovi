#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "constants.h"
#include "struct.h"


int main() {
	Position head;
	char imeDatoteke[MAX_STR_LEN];
	int s;
	s = 0;
	memset(imeDatoteke, 0, MAX_STR_LEN);

	ProgramDescription();
	printf("\n Enter filename (in form example.txt): ");
	s = scanf(" %s", &imeDatoteke);

	if (s == 0) { return EXIT_FAILURE; }
	head = malloc(sizeof(Cvor));
	if (head == NULL) {
		printf("Memory allocation fail");
		return EXIT_FAILURE;
	}

	head->f = 0.0;
	head->Next = NULL;

	ProcessFile(imeDatoteke, head, 1);

	printf("\n\nResult: ");
	PrintList(head);
	printf("\n");

	DelAll(head);
	ProgramEndnote();
	return EXIT_SUCCESS;
}