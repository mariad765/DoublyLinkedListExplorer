/* DOBRE Maria-Adina - 312CD */
#include "Update.h"
#include <stdio.h>
#include <stdlib.h>

//...................................................................

// functions added in the queue
extern void moveRight(List *list);
extern void moveLeft(List *list, int *bool);
extern void moveRightChar(List *list, char c);
extern void moveLeftChar(List *list, char c, FILE *output);
extern void insertLeft(List *list, T c, FILE *output);
extern void insertRight(List *list, T c);
extern void write(List *list, T c);

// function to get the current node
extern Node *getCrt(List *list);
