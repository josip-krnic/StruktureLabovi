#include <stdio.h>
#include <stdlib.h>

#include "structs.h"
#include "constants.h"

int main()
{
	Ptr head = initHead();
	if (!head)
		return MALLOC_ERROR;

	menu(head);

	deleteAll(head);

	return EXIT_SUCCESS;
}