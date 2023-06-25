/* DOBRE Maria-Adina - 312CD */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//..................................................................

// Define type alias T to be of type char
typedef char T;

// Define a node struct for use in a doubly linked list
typedef struct ListNode {
  T elem;                // Stored node value
  struct ListNode *next; // Pointer to next node
  struct ListNode *prev; // Pointer to previous node
} Node, *NodePoint;

// Define a doubly linked list struct
typedef struct list {
  Node *first; // Pointer to first node in list
  Node *last;  // Pointer to last node in list
  Node *crt;   // Pointer to current node in list
} List, *ListPoint;

extern List *createList(); // Create list and allocates mem
extern Node *createNode(); // Create a node and allocates mem
// Make the initial list santinel and node with '#' element
extern List *initBandSantinel();
extern List *initContent();
extern void insertAtEnd(List *list); // Insert element at the end
// Insert element after current position
extern void insertAfter(List *list, T c);
// Insert element before current position
extern void insertBefore(List *list, T c, FILE *output);
// Free funcs
extern void freeNode_(Node *node);
extern void freeList(List *list);