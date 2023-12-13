#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#include "tree.h"
#include "constants.h"

int main()
{
	int choice = 0;
	nodePtr head = (nodePtr)malloc(sizeof(Node));
	strcpy(head->folderName, "\0");
	head->nextFolder = NULL;
	head->subfolder = NULL;

	if (!head)
	{
		printf("Malloc error in main function.\n");
		return MALLOC_ERROR;
	}

	do
	{
		choice = menu(head);
		printf("%d\n\n", choice);
	} while (!choice);
	

	return EXIT_SUCCESS;
}