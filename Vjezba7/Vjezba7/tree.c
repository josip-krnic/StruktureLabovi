#define _CRT_SECURE_NO_WARNINGS
#include "tree.h"

#include <stdio.h>
#include <stdlib.h>

#include "constants.h"

int addNode(nodePtr current, char folderName[MAX_STR_LENGTH])
{
	nodePtr newNode = (nodePtr)malloc(sizeof(Node));
	if (!newNode)
	{
		printf("Malloc error in int addNode(nodePtr current, char folderName[MAX_STR_LENGTH])\n");
		return MALLOC_ERROR;
	}
	strcpy(newNode->folderName, folderName);
	newNode->nextFolder = NULL;

	newNode->nextFolder = current->subfolder;
	current->subfolder = newNode;

	return EXIT_SUCCESS;
}

int dir(nodePtr current)
{
	nodePtr newCurrent = current->subfolder;
	while (newCurrent->nextFolder != NULL)
	{
		printf("\t%s\n", newCurrent->folderName);
	}

	printf("No ore folders.\n\n");

	return EXIT_SUCCESS;
}



int executeCommand(nodePtr head, char command[MAX_STR_LENGTH])
{
	char cmd1[MAX_STR_LENGTH] = "\0";
	char cmd2[MAX_STR_LENGTH] = "\0";
	nodePtr current = head;
	sscanf(command, " %s %s", cmd1, cmd2);
	printf("%s\n%s\n", cmd1, cmd2);

	if (cmd1 == "md")
	{
		addNode(current, cmd2);
	}
	/*
	else if (cmd1 == "cd")
	{
		moveToSubfolder();
		
		// Check if cmd2 is .. (return to parent folder) or folder name (check if it exists) 
		
	}
	*/
	else if (cmd1 == "dir")
	{
		dir(current);
	}

	else if (cmd1 == "exit")
	{
		return EXIT;
	}

	else
	{
		printf("Command not recognised.\n");
		return CMD_NOT_FOUND;
	}

	return EXIT_SUCCESS;
}

int menu(nodePtr head)
{
	char command[MAX_STR_LENGTH] = "\0";

	printf(
		"Enter your command.Available commands : \n"
		"md {folder_name}\n" // make folder
		"cd {folder_name}\n" // go to folder
		"cd ..\n" // go to parent folder
		"dir\n" // list all folders in current folder
		"exit\n" // quit app
	);

	scanf("%[^\n]", command);

	executeCommand(head, command);

	return EXIT_SUCCESS;
}
