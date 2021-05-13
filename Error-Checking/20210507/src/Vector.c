#include <stdio.h>
#include <stdlib.h>

#include "Vector.h"

int vectorInit(Vector *vec, size_t initialCapacity) {
  vec->capacity = initialCapacity;
  vec->size = 0;
  vec->items = malloc(sizeof(void*) * vec->capacity);
  
  if (vec->items) {
    return 0;
  } else {
      fprintf(stderr, "%s: Memory allocation failed.", __func__);
    return 1;
  }
}

size_t vectorGetSize(Vector *v) {
  return v->size;
}

bool vectorIsEmpty(Vector *vec) {
  return vec->size == 0;
}

int vectorResize(Vector *vec, size_t capacity) {
  void **items = realloc(vec->items, sizeof(void*) * capacity);
  if (items) {
    vec->items = items;
    vec->capacity = capacity;
  } else {
    fprintf(stderr, "%s: Memory reallocation failed.", __func__);
    return 1;
  }

  if (vec->size >= capacity) {
    vec->size = capacity;
  }

  return 0;
}

int vectorPush(Vector *vec, void *item) {
  if (vec->capacity == vec->size) {
    if ( vectorResize(vec, vec->capacity * 2) ) {
      fprintf(stderr, "%s: Failed to expand vector. Item not added.", __func__);
      return 1;
    }
  }
  vec->items[vec->size] = item;
  vec->size++;

  return 0;
}

int vectorSet(Vector *vec, size_t idx, void *item) {
  if (idx < vec->size) {
    vec->items[idx] = item;
    return 0;
  } else {
    fprintf(stderr, "%s: Cannot set element %d outside vector with size %d.", __func__, idx, vec->size);
    return 1;
  }
}

void* vectorGet(Vector *vec, size_t idx) {
  if (idx < vec->size) {
    return vec->items[idx];
  }
  
  fprintf(stderr, "%s: Element %d outside vector with size %d.", __func__, idx, vec->size);
  return NULL;
}

void* vectorBack(Vector *vec) {
  if (0 == vec->size) {
    fprintf(stderr, "%s: Vector is empty.", __func__);
    return NULL;
  }

  return vec->items[vec->size - 1];
}

int vectorDelete(Vector *vec, size_t idx) {
  if (idx >= vec->size) {
    fprintf(stderr, "%s: Could not delete element %d.", __func__, idx);
    return 1;
  }

  vec->items[idx] = NULL;

  for (size_t i = idx; i < vec->size - 1; ++i) {
    vec->items[i] = vec->items[i + 1];
    vec->items[i + 1] = NULL;
  }

  vec->size--;

  return 0;
}

int vectorPop(Vector *vec) {
  if (vec->size == 0) {
    fprintf(stderr, "%s: Vector is empty.", __func__);
    return 1;
  }

  vec->size--;

  return 0;
}

void vectorFree(Vector *vec) {
  if (vec->items != NULL) {
    free(vec->items);
    vec->items = NULL;
    vec->size = 0;
    vec->capacity = 0;
  }
}
