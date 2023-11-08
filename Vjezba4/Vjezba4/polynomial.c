#define _CRT_SECURE_NO_WARNINGS
#include "polynomial.h"
#include "constants.h"

#include <stdlib.h>
#include <stdio.h>


int addElement(nodePtr nodeHead, float coef, float exp)
{
	elePtr current = nodeHead->head;
	elePtr newEle = (elePtr)malloc(sizeof(Element));
	if (!newEle)
	{
		printf("Malloc error.\n");
		return MALLOC_ERROR;
	}
	current->coef = coef;
	current->exp = exp;
	current->next = NULL;

	while (!current->next)
	{
		if (current->exp > newEle->exp)
			current = current->next;
		else if (current->exp == newEle->exp)
		{
			current->coef += newEle->coef;
			free(newEle);
			return EXIT_SUCCESS;
		}
	}

	newEle->next = current->next;
	current->next = newEle;
	return EXIT_SUCCESS;
}

int addNode(nodePtr head)
{
	nodePtr newNode = (nodePtr)malloc(sizeof(Node));
	if (!newNode)
	{
		printf("Malloc error.\n");
		return MALLOC_ERROR;
	}
	elePtr newHead = (elePtr)malloc(sizeof(Element));
	if (!newHead)
	{
		printf("Malloc error.\n");
		return MALLOC_ERROR;
	}

	nodePtr current = (nodePtr)malloc(sizeof(Node));
	if (!current)
	{
		printf("Malloc error.\n");
		return MALLOC_ERROR;
	}
	current = head;
	
	current->next = head->next;
	head->next = current;
		
	return EXIT_SUCCESS;
}

int printPolynomial(nodePtr head)
{
	nodePtr currentNode = head->next;
	if (!currentNode)
		return EXIT_SUCCESS;

	elePtr currentElement = currentNode->head->next;
	
	while (!currentElement)
	{
		printf("%.2fx^%.2f\n", currentElement->coef, currentElement->exp);
		currentElement = currentElement->next;
	}
	
	printPolynomial(head->next);

	return EXIT_SUCCESS;
}

int extractFromFile(nodePtr head)
{
	FILE* file = NULL;
	nodePtr current = head;
	char filename[MAX_STR_LEN] = { 0 };
	char buffer[MAX_STR_LEN] = { 0 };
	int numOfVars = 0;
	float coef = 0.0f;
	float exp = 0.0f;
	printf("Enter the name of the file:\n");
	scanf(" %s", filename);

	file = fopen(filename, "r");
	if (!file)
	{
		printf("Error while opening the file.\n");
		return FILE_OPEN_ERROR;
	}

	while (!feof(file))
	{
		addNode(head);
		current = head->next;
		if (sscanf(buffer, " %f %f", coef, exp) == 2)
		{
			addElement(current, coef, exp);
		}
	}

	fclose(file);

	return EXIT_SUCCESS;
}
