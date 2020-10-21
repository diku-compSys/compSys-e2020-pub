#ifndef STACK_H
#define STACK_H

struct node {
  void        *data;
  struct node *next;
};

struct stack {
  struct node *top;
};

void stack_init(struct stack*);

int stack_empty(struct stack*);

void* stack_top(struct stack*);

void* stack_pop(struct stack*);

int stack_push(struct stack*, void*);


#endif
