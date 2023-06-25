/* DOBRE Maria-Adina - 312CD */
#include "Free.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxCharsInWord 30

//.....................................................

//.....................................................
int main() {
  // start file reading
  FILE *input;
  FILE *output;              // output file
  int num;                   // number of operations to be done
  char word[MaxCharsInWord]; // variable to read the chars
  char c;                    // character
  TQueue queue = init();     // queue that stores UPDATE stuff
  List *list = initContent();
  // list containing only the santinel and the crt node
  input = fopen("tema1.in", "r"); // open files
  output = fopen("tema1.out", "w");
  // new undo stack s1 of type TStack1 and initialize it to an empty stack
  TStack1 s1 = init11();
  //   new redo stack s2 of type TStack2 and initialize it to an empty stack
  TStack2 s2 = init22();
  if (input == NULL) {
    // If the file fails to open, print an error message and return 1
    printf("Error opening file.\n");
    return 1;
  }
  if (output == NULL) {
    printf("Error opening file!\n");
    return 1;
  }
  // Read an integer aka number of comands
  fscanf(input, "%d", &num);
  //  Iterate "num" times, reading in a word from the file each iteration
  for (int i = 0; i < num; i++) {
    fscanf(input, "%s",
           word); // read an array called "word" to hold the current command
    //  If the current word is "command", enqueue a new node containing
    //  "command" at the back of the "queue"
    if (!strcmp(word, "MOVE_LEFT"))
      queue = enqueue(queue, init1(word));
    if (!strcmp(word, "MOVE_RIGHT"))
      queue = enqueue(queue, init1(word));
    if (!strcmp(word, "MOVE_RIGHT_CHAR")) {
      fscanf(input, " %c", &c);
      queue = enqueue(queue, init2(word, c));
      while (s1) {
        s1 = pop1(s1); // Clear the first stack
      }
      while (s2) {
        s2 = pop2(s2); // Clear the second stack
      }
    }

    if (!strcmp(word, "MOVE_LEFT_CHAR")) {
      fscanf(input, " %c", &c);
      queue = enqueue(queue, init2(word, c));
      while (s1) {
        s1 = pop1(s1);
      }
      while (s2) {
        s2 = pop2(s2);
      }
    }
    if (!strcmp(word, "WRITE")) {
      fscanf(input, " %c", &c);
      queue = enqueue(queue, init2(word, c));
      while (s1) {
        s1 = pop1(s1);
      }
      while (s2) {
        s2 = pop2(s2);
      }
    }
    if (!strcmp(word, "INSERT_LEFT")) {
      fscanf(input, " %c", &c); // read the character preceiding the command
      queue = enqueue(queue, init2(word, c));
      while (s1) {
        s1 = pop1(s1); // Clear the first stack
      }
      while (s2) {
        s2 = pop2(s2); // Clear the second stack
      }
    }
    if (!strcmp(word, "INSERT_RIGHT")) {
      // read the character preceiding the command
      fscanf(input, " %c", &c);
      queue = enqueue(queue, init2(word, c));
      while (s1) {
        s1 = pop1(s1); // Clear the first stack
      }
      while (s2) {
        s2 = pop2(s2); // Clear the second stack
      }
    }
    // when command EXECUTE is met, it will execute a command stored at queue
    // front
    if (!strcmp(word, "EXECUTE")) {
      if (isEmpty(queue)) {
        fprintf(output, "%s", "ERROR: NO COMMANDS TO EXECUTE");
        return 1;
      }
      exec(front(queue), list, output, &s1);
      queue = dequeue(queue);
    }
    // the following lines will help print the list or element
    if (!strcmp(word, "SHOW_CURRENT")) {
      showCrt(list, output);
    }
    if (!strcmp(word, "SHOW")) {
      showAll(list, output);
    }
    // undo and redo
    if (!strcmp(word, "UNDO")) {
      // Get a pointer to the current node in the list

      Node *carent = getCrt(list);

      undo(&s1, list, carent, &s2);
    }

    // same explanation for redo
    if (!strcmp(word, "REDO")) {
      Node *carnt = getCrt(list);

      redo(&s2, list, output, &s1, carnt);
    }
  }
  // Close the input file
  fclose(input);
  // Close the output file
  fclose(output);
  // Free all the memory used by the list, s1, s2, and queue
  freeAllMem(list, s1, s2, queue);
  return 0;
}