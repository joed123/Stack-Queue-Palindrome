/*
 * Name: Joseph Di Lullo
 */

#include <stdlib.h>

#include "queue.h"
#include "dynarray.h"

struct queue {
  struct dynarray* array;
};

struct queue* queue_create() {
	struct queue* new_queue = malloc(sizeof(struct queue));
	new_queue -> array = dynarray_create();
    return new_queue;
}

void queue_free(struct queue* queue) {
	dynarray_free(queue -> array);
	free(queue);
  	return;
}

int queue_isempty(struct queue* queue) {
	return dynarrayis_empty(queue -> array);
}

void queue_enqueue(struct queue* queue, void* val) {
	dynarray_insert(queue -> array, val);
	return;
}

void* queue_front(struct queue* queue) {
	return dynarray_get(queue ->array,0);
}

void* queue_dequeue(struct queue* queue) {
	return dynarray_removepart2(queue -> array);
}
