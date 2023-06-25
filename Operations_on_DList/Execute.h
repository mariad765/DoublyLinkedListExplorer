/* DOBRE Maria-Adina - 312CD */
#include "Move.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This function will execute the commands stored in the queue/stalk
extern void exec(Type type, List *list, FILE *output, TStack1 *s1);
extern void undo(TStack1 *s1, List *list, Node *carent, TStack2 *s2);
extern void redo(TStack2 *s2, List *list, FILE *output, TStack1 *s1,
                 Node *carent);
