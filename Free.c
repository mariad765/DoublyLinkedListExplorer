/* DOBRE Maria-Adina - 312CD */
#include "Free.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//.......................................................................
// Function that frees all memory allocated
void freeAllMem(ListPoint list, TStack1 s1, TStack2 s2, TQueue queue) {
  freeList(list);
  freeQueue(queue);
  freeStack1(s1);
  freeStack2(s2);
  return;
}