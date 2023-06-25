/* DOBRE Maria-Adina - 312CD */
#include "Move.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//...................................................................

void moveRight(List *list) {
  // printf("merge");
  if (list->crt->next == NULL) {
    /// printf("merge");
    // Current node is the last node, so create a new node and append it
    Node *nou = createNode();
    nou->prev = list->crt;
    list->crt->next = nou;
    list->last = nou;
    list->crt = nou;
    // printf("merge");
    return;
  } else {
    // Current node is not the last node, so move to the next node
    list->crt = list->crt->next;
    return;
  }
  return;
}

void moveLeft(ListPoint list, int *bool) {
  // If the current node is already at the beginning of the list, do nothing
  if (list->crt->prev == list->first) {
    *bool = 1;
    return;
  }
  // Otherwise, move the current node to the left
  list->crt = list->crt->prev;
  *bool = 0;
  return;
}

void moveRightChar(List *list, char c) {

  if (list == NULL) {
    // Handle error case where the input list is NULL
    fprintf(stderr, "Error: moveRightChar received NULL list pointer\n");
    return;
  }

  if (list->crt == NULL) {
    // Handle error case where the input list is empty
    fprintf(stderr, "Error: moveRightChar received empty list\n");
    return;
  }
  Node *nod = list->crt;
  while (list->crt != NULL) {
    if (list->crt->elem == c) {
      // Found the element, exit loop
      break;
    }

    if (list->crt->next == NULL) {
      // Element not found, insert at end
      list->last = list->crt;
      insertAtEnd(list);
      list->crt = list->last;
      return;
    }
    // Move to next node
    list->crt = list->crt->next;
  }
  return;
}

void moveLeftChar(List *list, char c, FILE *output) {

  // Check if the list pointer is NULL, print an error message if so and return
  if (list == NULL) {
    fprintf(stderr, "Error: moveLeftChar received NULL list pointer\n");
    return;
  }
  // Check if the list is empty, print an error message if so and return
  if (list->crt == NULL) {
    fprintf(stderr, "Error: moveLeftChar received empty list\n");
    return;
  }
  // Store the current node of the list in a variable
  Node *curentul = list->crt;
  // Loop through the list until the node containing the character is found
  while (list->crt->elem != c) {
    list->crt = list->crt->prev;
    if (list->crt == NULL) {
      // current position shall not reach NULL
      // Error: moveLeftChar could not find element in list
      // if crt pointer is NULL, reset position of crt
      list->crt = curentul;
      return;
    }
    if (list->crt->elem == c) {
      break; // the element has been found, exit while loop
    }
    if (list->crt == list->first) {
      // the current node is the first node in the list aka the santinel,
      //  print an error message
      fprintf(output, "%s", "ERROR\n");
      // reset the current node to the original
      // position, and return.
      list->crt = curentul;
      return;
    }
  }
  return;
}

// The following functions  add a node containing a specific element aka
// argument of commands on the left or right of the current position
void insertLeft(List *list, T c, FILE *output) {
  insertBefore(list, c, output);
  return;
}
void insertRight(List *list, T c) {
  insertAfter(list, c);
  return;
}

// This function writes another value in the current node
void write(List *list, T c) {
  // caution not to reach seg fault
  if (list == NULL) {
    fprintf(stderr, "Error: write func received NULL list pointer\n");
    return;
  }

  if (list->crt == NULL) {
    fprintf(stderr, "Error: write func received empty list\n");
    return;
  }
  list->crt->elem = c;
  return;
}
//...................................................................
// Function that gets the adress of the current node
Node *getCrt(List *list) {
  Node *curent = list->crt;
  return curent;
}