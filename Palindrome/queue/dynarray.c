

#include <stdlib.h>
#include <assert.h>
#include "dynarray.h"

struct dynarray {
  void** data;
  int size;
  int capacity;
};

#define DYNARRAY_INIT_CAPACITY 4


struct dynarray* dynarray_create() {
  struct dynarray* da = malloc(sizeof(struct dynarray));
  assert(da);

  da->data = malloc(DYNARRAY_INIT_CAPACITY * sizeof(void*));
  assert(da->data);
  da->size = 0;
  da->capacity = DYNARRAY_INIT_CAPACITY;

  return da;
}

void dynarray_free(struct dynarray* da) {
  assert(da);
  free(da->data);
  free(da);
}


int dynarray_size(struct dynarray* da) {
  assert(da);
  return da->size;
}

void _dynarray_resize(struct dynarray* da, int new_capacity) {
  assert(new_capacity > da->size);

  void** new_data = malloc(new_capacity * sizeof(void*));
  assert(new_data);

  for (int i = 0; i < da->size; i++) {
    new_data[i] = da->data[i];
  }

  free(da->data);
  da->data = new_data;
  da->capacity = new_capacity;
}

void dynarray_insert(struct dynarray* da, void* val) {
  assert(da);

  if (da->size == da->capacity) {
    _dynarray_resize(da, 2 * da->capacity);
  }

  da->data[da->size] = val;
  da->size++;
}

void dynarray_remove(struct dynarray* da, int idx) {
  assert(da);
  assert(idx < da->size && idx >= 0);

  for (int i = idx; i < da->size - 1; i++) {
    da->data[i] = da->data[i+1];
  }

  da->size--;
}

void* dynarray_get(struct dynarray* da, int idx) {
  assert(da);
  assert(idx < da->size && idx >= 0);
  return da->data[idx];
}

void dynarray_set(struct dynarray* da, int idx, void* val) {
  assert(da);
  assert(idx < da->size && idx >= 0);
  da->data[idx] = val;
}

int dynarrayis_empty(struct dynarray* dynarray){
  if (dynarray -> size == 0){
    return 1;
  }
  else{
    return 0;
  }
}

void* dynarray_removepart2(struct dynarray* da) {
  assert(da);
  void * val = da -> data[0];
  dynarray_remove(da, 0);
  return val;
}