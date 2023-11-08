#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#include "constants.h"
#include "polynomial.h"


int main()
{
	nodePtr head = (nodePtr)malloc(sizeof(Element));

	if (!head)
	{
		printf("Malloc error.\n");
		return MALLOC_ERROR;
	}

	head->head = NULL;
	head->next = NULL;

	if (!extractFromFile(head))
	{
		printf("Error reading from file.\n");
		return EXIT_FAILURE;
	}

	printPolynomial(head);

	return EXIT_SUCCESS;
}