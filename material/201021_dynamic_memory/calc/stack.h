#ifndef STACK_H
#define STACK_H

struct stack {
} stack;

void stack_init(struct stack*);

int stack_empty(struct stack*);

void* stack_top(struct stack*);

void* stack_pop(struct stack*);

int stack_push(struct stack*, void*);


#endif
