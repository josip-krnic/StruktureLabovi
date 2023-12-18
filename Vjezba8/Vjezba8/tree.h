#ifndef TREE_H
#define TREE_H

typedef struct node* Position;

typedef struct node {
	int value;
	Position right;
	Position left;
} Node;

typedef struct stog* Poz;

typedef struct stog {
	Position adr;
	Poz next;
	Poz prev;
} Stog;

int initNode(Position P);                     //funkcija za incijaliziranje Nodea
int initStog(Poz S);                          //funkcija za inicijalizranje elementa stoga
Position newNode(Position P, int val);        //funkcija za stvaranje nodea poziva insertNode
Position insertNode(Position P, Position Q);  //funkcija za insetiranje nodea u stablo
int printNode(Position P);                    //funkcija za ispis jednog nodea
int printTreeinorder(Position P);             //funkcija za ispis stabla inorder poziva printnode
int printTreepreorder(Position P);            //funkcija za ispis stabla preorder poziva printnode
int printTreepostorder(Position P);           //funkcija za ispis stabla postorder poziva printnode
int printTreelevelorder(Position P);          //funkcija za ispis stabla level order poziva printnode
int printMenu();                              //funkcija za ispis menia za odabir
int switchCase(Position* Padr, int choice);   //funkcija koja poziva potrebne funkcije ovisno o izboru choice
int push(Poz prev, Position P);               //funkcija za ubacivanje u stog
int pushtree(Poz stack, Position P);          //pomocna funkcija za ispis stabla level order (printTreelevelorder)
Position pop(Poz prev);                       //funkcija za izbacivanje iz stoga
int printStack(Poz stack);                    //funkcija za pop-anje svega iz stacka
int findNode(Position P, int val, int D);     //funkcija za pronalazak nekog elementa
int getInput(int* val);                       //funkcija za uzimanje vrijednosti s stdin
Position deleteNode(Position P, int val);     //funkcija za brisanje jednog elementa ili vrijednosti iz stabla
Position findMin(Position P);				  //funkcija za trazenje minimalnog elementa u stablu
Position findMax(Position P);				  //funkcija za trazenje maksimalnog elementa u stablu
Position deletetree(Position P);			  //funkcija za brisanje stabla

#endif