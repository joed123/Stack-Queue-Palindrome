/*
 * Name: Joseph Di Lullo
 */

#include <stdlib.h>

#include "stack.h"
#include "list.h"

struct stack {
  struct list* list;
};

struct stack* stack_create() {
	struct stack* new_stack = malloc(sizeof(struct stack));
	new_stack -> list = list_create();							
    return new_stack;
}

void stack_free(struct stack* stack) {
	list_free(stack -> list);									
	free(stack);
	return;
}

int stack_isempty(struct stack* stack) {
	return listis_empty(stack -> list);						
}

void stack_push(struct stack* stack, void* val) {
	list_insert(stack -> list, val);
	return;
}

void* stack_top(struct stack* stack) {
	return list_top(stack -> list);
}

void* stack_pop(struct stack* stack) {
	return list_pop(stack -> list);
}
