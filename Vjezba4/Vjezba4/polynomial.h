#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

struct _element;
typedef struct _element* elePtr;
typedef struct _element {
	float coef;
	float exp;
	elePtr next;
} Element;

struct _node;
typedef struct _node* nodePtr;
typedef struct _node {
	elePtr head;
	nodePtr next;
} Node;

int addElement(elePtr eleHead, float coef, float exp);
int addNode(nodePtr head);
int printPolynomial(nodePtr head);
int extractFromFile(nodePtr head);

#endif
