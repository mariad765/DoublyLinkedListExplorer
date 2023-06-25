/* DOBRE Maria-Adina - 312CD */
#include "Execute.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//...........................................................

// This function will execute the commands stored in the tail
void exec(Type type, List *list, FILE *output, TStack1 *s1) {

  int bool = 0;

  if (!strcmp(type.move_Name, "MOVE_LEFT")) {
    *s1 = push1(*s1, list->crt);
    moveLeft(list, &bool);
    if (bool == 1)
      *s1 = pop1(*s1);
    bool = 0;
  }
  if (!strcmp(type.move_Name, "MOVE_RIGHT")) {
    *s1 = push1(*s1, list->crt);

    moveRight(list);
  }
  // If the command is to move right to a specific character
  if (!strcmp(type.move_Name, "MOVE_RIGHT_CHAR")) {
    // Move the current node to the right until it reaches the specified
    // character
    moveRightChar(list, type.c);
  }
  // If the command is to move left to a specific character
  if (!strcmp(type.move_Name, "MOVE_LEFT_CHAR")) {
    // Move the current node to the left until it reaches the specified
    // character
    moveLeftChar(list, type.c, output);
  }
  // If the command is to write a character to the current node
  if (!strcmp(type.move_Name, "WRITE")) {
    // Write the given character to the current node
    write(list, type.c);
  }
  // Insert functions
  if (!strcmp(type.move_Name, "INSERT_RIGHT")) {

    insertAfter(list, type.c);
  }
  if (!strcmp(type.move_Name, "INSERT_LEFT")) {

    insertBefore(list, type.c, output);
  }
}

//...................................................................
// for undo
//...................................................................

void undo(TStack1 *s1, List *list, Node *carent, TStack2 *s2) {
  // Set the current node of the list to the top node of the first stack
  list->crt = top1(*s1);
  *s2 = push2(*s2, carent); // Push the previous current node of the list onto
                            // the second stack
  *s1 = pop1(*s1);          // Pop the top node off the first stack

  return;
}

//...................................................................
// for redo
//...................................................................

void redo(TStack2 *s2, List *list, FILE *output, TStack1 *s1, Node *carent) {
  // Set the current node of the list to the top node of the second stack
  list->crt = top2(*s2); // Set the current node of the list to the top node of
                         // the second stack
  *s1 = push1(*s1, carent); // Push the previous current node of the list onto
                            // the first stack
  *s2 = pop2(*s2);          // Pop the top node off the second stack

  return;
}
