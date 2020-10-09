#include <stdlib.h>
#include <stdio.h>
#include "stack.h"


void stack_init(struct stack_t *stack) {
  stack->top = NULL;
}

int stack_empty(struct stack_t *stack) {
  if (stack == NULL) {
    fprintf(stderr, "stack_empty() error: stack uninitialized\n");
    exit(1);
  }

  return stack->top == NULL;
}

void *stack_top(struct stack_t *stack) {
  if (stack == NULL) {
    fprintf(stderr, "stack_top() error: stack uninitialized\n");
    exit(1);
  }

  return stack->top->data;
}

void *stack_pop(struct stack_t *stack) {
  if (stack == NULL) {
    fprintf(stderr, "stack_pop() error: stack uninitialized\n");
    exit(1);
  }

  struct node *old_top = stack->top;

  if (old_top == NULL)
    return NULL;

  void *data = old_top->data;

  stack->top = old_top->next;

  free(old_top);

  return data;
}

int stack_push(struct stack_t *stack, void *data) {
  if (stack == NULL) {
    fprintf(stderr, "stack_push() error: stack uninitialized\n");
    exit(1);
  }

  struct node *new_top = malloc(sizeof(struct node));

  new_top->data = data;
  new_top->next = stack->top;

  stack->top = new_top;

  return 0;
}
