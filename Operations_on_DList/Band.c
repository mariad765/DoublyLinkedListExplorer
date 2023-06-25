/* DOBRE Maria-Adina - 312CD */
#include "Band.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//.........................................................................

// Function to create an empty list
List *createList() {
  List *list = (List *)malloc(sizeof(List)); // allocate memory for the list
  if (list == NULL)
    exit(1);          // exit if memory allocation fails
  list->first = NULL; // initialize pointers to NULL
  list->last = NULL;
  list->crt = NULL;
  return list;
}

// Function to create a new node with default values
Node *createNode() {
  Node *result = (Node *)malloc(sizeof(Node)); // allocate memory for the node
  if (result == NULL)
    exit(1);           // exit if memory allocation fails
  result->elem = '#';  // initialize element to #
  result->prev = NULL; // initialize pointers to NULL
  result->next = NULL;
  return result;
}

// Function to initialize the band with a sentinel node
List *initBandSantinel() {
  List *list = createList(); // create an empty list
  Node *nod = createNode();  // create a new node with default values
  list->first = nod; // set the first node in the list to be the new node
  list->first->elem = ' ';
  list->last = nod; // set the last node in the list to be the new node
  list->crt = nod;  // set the current node in the list to be the new node
  return list;
}

// Function to initialize the content of the band
List *initContent(void) {
  List *list = initBandSantinel(); // create a list with a sentinel node
  Node *curt = createNode();       // create a new node with default values
  list->first->elem = ' '; // initialize the sentinel node element to space
  curt->next = NULL;       // initialize pointers to NULL
  curt->prev = list->first;
  list->first->next = curt;
  curt->elem = '#';  // set the element of the new node to #
  list->last = curt; // set the last node in the list to be the new node
  list->crt = curt;  // set the current position
  return list;
}

// This function inserts a new node at the end of a linked list
void insertAtEnd(List *list) {
  Node *nod = createNode();
  // list->last->prev->next = nod;
  // Set the previous node's next pointer to the new node
  list->last->next = nod;
  nod->prev = list->last;
  list->last = nod;
  // Update the last node pointer to
  // the new node
}

// This function inserts a new node after the current node in a linked list with
// the given element c
void insertAfter(List *list, T c) {

  // If the current node has a next node
  if (list->crt->next != NULL) {

    Node *nod = list->crt; // Get the current node and create a new node
    Node *new = createNode();
    new->elem = c;         // Set the new node's element to the given element
    list->crt = new;       // Set the current node to the new node
    new->next = nod->next; // Update the  pointers
    new->prev = nod;
    // nod->next->prev = new;
    nod->next = new;
    if (list->last == nod)
      list->last == new;
    return;
  }

  // If the current node does not have a next node
  if (list->crt->next == NULL) {

    Node *nod = list->crt; // Get the current node and create a new node
    Node *new = createNode();
    new->elem = c; // Set the new node's element to the given element
    nod->next = new;
    new->prev = nod;
    list->crt = new;
    if (list->last == nod)
      list->last == new;
    return;
  }
  return;
}

// This function inserts a new node before the current node in a linked list
// with the given element c
void insertBefore(List *list, T c, FILE *output) {
  Node *nod = list->crt;
  Node *curent = list->crt;
  // If the node before the current node is not the first node in the list
  if (list->crt != NULL && list->crt->prev != list->first) {
    // printf("merge");
    Node *new = createNode();
    new->elem = c;
    list->crt = new;
    // Updates
    new->next = nod;
    new->prev = nod->prev;
    nod->prev->next = new;
    nod->prev = new;
    // printf("merge3");
  }

  // If the node before the current node is the first node in the
  // list
  if (list->crt->prev == list->first) {
    fprintf(output, "%s", "ERROR\n"); // error message
    // Set the current node back to the original current node
  }

  //  If the current node is the first node in the list
  if (list->crt == list->first) {
    fprintf(output, "%s", "ERROR\n");
    // Set the current node back to the original current node
    list->crt = curent;
  }
}
// Free memory used by a single node in a linked list
void freeNode_(Node *node) {
  free(node);
  node = NULL; // Set the node pointer to NULL to avoid dangling pointers
  return;
}
// Free memory used by a linked list
void freeList(List *list) {
  if (list == NULL)
    return; // If the list is already empty, return from the function
  Node *iter, *temp;
  iter = list->first;

  while (iter != NULL) { // Loop through the list
    temp = iter;         // Store the current node in a temporary variable
    iter = iter->next;   // Move to the next node in the list
    freeNode_(temp);     // Free the memory used by the current node
  }

  free(list); // Free the memory used by the list structure itself
  list = NULL;
  return;
}