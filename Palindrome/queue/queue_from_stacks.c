
#include <stdlib.h>

#include "stack.h"
#include "queue_from_stacks.h"

struct queue_from_stacks {
  struct stack* s1;
  struct stack* s2;
};

struct queue_from_stacks* queue_from_stacks_create() {
  	return NULL;
}

void queue_from_stacks_free(struct queue_from_stacks* qfs) {
  	
  	return;
}

int queue_from_stacks_isempty(struct queue_from_stacks* qfs) {
  	return 1;
}

void queue_from_stacks_enqueue(struct queue_from_stacks* qfs, void* val) {
  	
  	return;
}

void* queue_from_stacks_front(struct queue_from_stacks* qfs) {
  	return NULL;
}

void* queue_from_stacks_dequeue(struct queue_from_stacks* qfs) {
  	return NULL;
}
