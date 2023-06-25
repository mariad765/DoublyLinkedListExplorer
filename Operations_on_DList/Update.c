/* DOBRE Maria-Adina - 312CD */
#include "Update.h"
#include <stdio.h>
#include <stdlib.h>

//...................................................................

// This function initializes a Type element with a given move name and sets the
// character field to '0'
Type init1(char move_Name[30]) {
  Type element;
  strcpy(element.move_Name, move_Name);
  element.c = '0';
  return element;
}

// This function initializes a Type element with a given move name and a given
// character
Type init2(char move_Name[30], char c) {
  Type element;
  strcpy(element.move_Name, move_Name);
  element.c = c;
  return element;
}

Nodeu *initNode(Type data) {
  Nodeu *nodeu = malloc(sizeof(struct nodeu));
  nodeu->data = data;
  nodeu->next = NULL;
  return nodeu;
}

// This fuction frees memory for a nodeu aka node from the list in queue
Nodeu *freeNode(Nodeu *nodeu) {
  if (nodeu)
    free(nodeu);
  return NULL;
}

TQueue initQueue(Type data) {
  TQueue queue = malloc(sizeof(struct queue));
  queue->head = queue->tail = initNode(data);
  queue->size = 1;
  return queue;
}

TQueue init() { return NULL; }
int isEmpty(TQueue queue) {
  return queue == NULL || queue->head == NULL || queue->size == 0;
}

TQueue enqueue(TQueue queue, Type data) {
  Nodeu *nodeu;
  if (isEmpty(queue)) {
    if (queue == NULL)
      return initQueue(data);
    free(queue);
    return initQueue(data);
  }
  nodeu = initNode(data);
  queue->tail->next = nodeu;
  queue->tail = nodeu;
  queue->size++;
  return queue;
}

TQueue dequeue(TQueue queue) {
  Nodeu *tmp;
  if (!isEmpty(queue)) {
    tmp = queue->head;
    queue->head = queue->head->next;
    tmp = freeNode(tmp);
    queue->size--;
  }
  return queue;
}
Type front(TQueue queue) {
  if (!isEmpty(queue))
    return queue->head->data;
  else
    exit(1);
}

// This function frees memory for the queue of commands
TQueue freeQueue(TQueue queue) {
  while (!isEmpty(queue))
    queue = dequeue(queue);
  if (queue)
    free(queue);
  return NULL;
}

//..............................................................

// for undo

//..............................................................

TStack1 initStack1(Node *date) {
  TStack1 s = (TStack1)malloc(sizeof(struct stack1));
  s->date = date;
  s->next = NULL;
  return s;
}

int isEmpty1(TStack1 s) { return s == NULL; }

TStack1 push1(TStack1 s, Node *date) {
  TStack1 top;
  if (isEmpty1(s))
    return initStack1(date);
  top = initStack1(date);
  top->next = s;
  return top;
}

TStack1 pop1(TStack1 s) {
  TStack1 tmp;
  if (isEmpty1(s))
    return s;
  tmp = s;
  s = s->next;
  free(tmp);
  return s;
}

Node *top1(TStack1 s) {
  if (isEmpty1(s))
    exit(1);
  return s->date;
}

TStack1 freeStack1(TStack1 s) {
  while (!isEmpty1(s))
    s = pop1(s);
  free(s);
  return NULL;
}

TStack1 init11() { return NULL; }

//............................................................
// for redo
//............................................................
// This function initializes a new stack2 and returns a pointer to it
TStack2 initStack2(Node *date) {
  TStack2 s = (TStack2)malloc(sizeof(struct stack2));
  s->date = date;
  s->next = NULL;
  return s;
}

// This function checks if a given stack2 is empty or not and returns 1 if it's
// empty and 0 if it's not empty
int isEmpty2(TStack2 s) { return s == NULL; }

// This function pushes a new element onto the stack2 and returns a pointer to
// the new top of the stack2
TStack2 push2(TStack2 s, Node *date) {
  TStack2 top;
  if (isEmpty2(s))
    return initStack2(date);
  top = initStack2(date);
  top->next = s;
  return top;
}

// This function removes the top element from the stack2 and returns a pointer
// to the new top of the stack2
TStack2 pop2(TStack2 s) {
  TStack2 tmp;
  if (isEmpty2(s))
    return s;
  tmp = s;
  s = s->next;
  free(tmp);
  return s;
}

// This function returns the data stored in the top element of the stack2
Node *top2(TStack2 s) {
  if (isEmpty2(s))
    exit(1);
  return s->date;
}

// This function frees all memory used by the stack2 and returns a pointer to
// the empty stack2
TStack2 freeStack2(TStack2 s) {
  while (!isEmpty2(s))
    s = pop2(s);
  return NULL;
}

// This function initializes an empty stack2 and returns a pointer to it
TStack2 init22() { return NULL; }
