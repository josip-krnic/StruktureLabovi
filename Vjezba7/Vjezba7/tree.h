#ifndef TREE_H
#define TREE_H

#include "constants.h"

struct _node;
typedef struct _node* nodePtr;
typedef struct _node {
	char folderName[MAX_STR_LENGTH];
	nodePtr nextFolder;
	nodePtr subfolder;
} Node;

int addNode(nodePtr current, char folderName[MAX_STR_LENGTH]);
int dir(nodePtr current);
int executeCommand(nodePtr head, char command[MAX_STR_LENGTH]);
int menu(nodePtr head);

#endif