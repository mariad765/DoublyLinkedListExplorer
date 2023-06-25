/* DOBRE Maria-Adina - 312CD */
#include "Band.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxCharsInString 30

//...................................................................

// queue for execute

//...................................................................

// tructure for the queue elements
typedef struct Q {
  char move_Name[MaxCharsInString];
  char c;
} Type;

// structure for a node in the queue
typedef struct nodeu {
  Type data;
  struct nodeu *next;
} Nodeu;

// define a structure for the queue itself
typedef struct queue {
  Nodeu *head, *tail; // pointers to the first and last nodes in the queue
  int size;           // the number of nodes in the queue
} * TQueue;

extern Nodeu *initNode(Type data);
extern Nodeu *freeNode(Nodeu *nodeu);
extern TQueue initQueue(Type data); // initialize a queue with the given data
extern TQueue init();               // initialize an empty queue
extern int isEmpty(TQueue queue);   // check
extern TQueue enqueue(TQueue queue, Type data);
extern TQueue dequeue(TQueue queue);
extern Type front(TQueue queue);
extern TQueue
freeQueue(TQueue queue); // returns the data of the first node in the queue
// declare external functions for initializing Type
// initializes a Type with only the move_Name
extern Type init1(char move_Name[MaxCharsInString]);
// initializes a Type with both move_Name and c.
extern Type init2(char move_Name[MaxCharsInString], char c);

//....................................................................
// stive for undo
//....................................................................

typedef struct stack1 {
  Node *date;
  struct stack1 *next;

} * TStack1;
// functions working with stack for undo
extern TStack1 initStack1(Node *date);
extern int isEmpty1(TStack1 s);
extern TStack1 push1(TStack1 s, Node *date);
extern TStack1 pop1(TStack1 s);
extern Node *top1(TStack1 s);
extern TStack1 freeStack1(TStack1 s);
extern TStack1 init11();

//....................................................................
// stack for redo
//....................................................................
typedef struct stack2 {
  Node *date;
  struct stack2 *next;

} * TStack2;
// functions working with stack for redo
extern TStack2 initStack2(Node *date);
extern int isEmpty2(TStack2 s);
extern TStack2 push2(TStack2 s, Node *date);
extern TStack2 pop2(TStack2 s);
extern Node *top2(TStack2 s);
extern TStack2 freeStack2(TStack2 s);
extern TStack2 init22();
