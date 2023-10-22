#include "structs.h"

#include <stdio.h>
#include <stdlib.h>

Ptr initHead()
{
	Ptr temp = (Ptr)malloc(sizeof(Student));
	if (!temp)
	{
		printf("Unable to initialize head element.\n");
		return MALLOC_ERROR;
	}
	strcpy(temp->firstName, "HEAD");
	strcpy(temp->lastName, "HEAD");
	temp->birthYear = 0;
	temp->next = NULL;

	return temp;
}

Ptr initElement(char firstName[MAX_STR_LENGTH], char lastName[MAX_STR_LENGTH], int year)
{
	Ptr temp = (Ptr)malloc(sizeof(Student));
	if (!temp)
	{
		printf("Unable to initialize element.\n");
		return MALLOC_ERROR;
	}
	strcpy(temp->firstName, firstName);
	strcpy(temp->lastName, lastName);
	temp->birthYear = year;
	temp->next = NULL;

	return temp;
}

int addToBeginning(Ptr head, Ptr element)
{
	element->next = head->next;
	head->next = element;
	return EXIT_SUCCESS;
}

int addToEnd(Ptr head, Ptr element)
{
	while (head->next)
		head = head->next;

	head->next = element;
	return 0;
}

int printList(Ptr head)
{
	printf("%20s%20s%20s", "First Name", "Last Name", "Year Of Birth\n");
	head = head->next;
	while (head) 
	{
		printf("%20s%20s%20d\n", head->firstName, head->lastName, head->birthYear);
		head = head->next;
	}
		
	return EXIT_SUCCESS;
}

int menu(Ptr head)
{
	int condition = TRUE;
	char choice = "\0";
	Ptr newNode = NULL;
	char firstName[MAX_STR_LENGTH] = "\0";
	char lastName[MAX_STR_LENGTH] = "\0";
	int birthYear = 0;

	while (condition)
	{
		printf("MENU\n");
		printf("a) New element at beginning\n");
		printf("b) New element at end\n");
		printf("c) Print list\n");
		printf("x) Exit\n");
		scanf(" %c", &choice);

		switch (choice)
		{
		case 'A':
		case 'a':
			printf("Enter first name, last name and year of birth.\n");
			scanf(" %s %s %d", firstName, lastName, &birthYear);
			newNode = initElement(firstName, lastName, birthYear);
			addToBeginning(head, newNode);
			break;

		case 'B':
		case 'b':
			printf("Enter first name, last name and year of birth.\n");
			scanf(" %s %s %d", firstName, lastName, &birthYear);
			newNode = initElement(firstName, lastName, birthYear);
			addToEnd(head, newNode);
			break;

		case 'C':
		case 'c':
			printList(head);
			break;
		
		case 'X':
		case 'x':
			condition = FALSE;
			break;
		default:
			printf("Command not found.\n");			
		}
	}

	return EXIT_SUCCESS;
}

int deleteAll(Ptr head)
{
	Ptr temp = initHead();
	temp = head->next;

	while (!temp)
	{
		head->next = temp->next;
		free(temp);
		temp = head->next;
	}
	free(head);

	return EXIT_SUCCESS;
}
