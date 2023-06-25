/* DOBRE Maria-Adina - 312CD */
#include "Print.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//.....................................................................

// This function prints the current element in the list
void showCrt(List *list, FILE *output) {
  if (list->crt != NULL) {
    fprintf(output, "%c", list->crt->elem);
    fprintf(output, "\n");
  }
  return;
}

// This function prints all elements in the list, and encloses the current
// element with "|" symbols
void showAll(List *list, FILE *output) {
  Node *iter = list->first;
  for (iter = list->first->next; iter != NULL; iter = iter->next) {

    if (list->crt != NULL)
      if (iter == list->crt) {
        fprintf(output, "%s", "|");
        fprintf(output, "%c", list->crt->elem);
        fprintf(output, "%s", "|");
      } else {
        fprintf(output, "%c", iter->elem);
      }
  }
  fprintf(output, "%s", "\n");
  return;
}
