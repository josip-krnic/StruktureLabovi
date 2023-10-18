#include <stdio.h>
#include <stdlib.h>
#include "structs.h"

int main() 
{
	Ptr head = (Ptr)malloc(sizeof(Student));
	if (!head)
		return MALLOC_ERROR;

	headInit(head);
	readFromFile("studenti.txt", head);
	printList(head->next);

	return 0;
}