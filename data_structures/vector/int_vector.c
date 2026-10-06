#include <stdio.h>
#include <string.h>

typedef struct {
  int *data;
  size_t cap;
  size_t len;
} Vec;

bool push_back(Vec *v, int value) {

  if (v->len == v->cap) {
    size_t cap = v->cap ? v->cap * 2 : 8;
    int *data = realloc(v->data, cap * sizeof(*data));

    if (data == NULL) {
      return false;
    }

    v->data = data;
    v->cap = cap;
  }

  v->data[v->len] = value;
  v->len++;
}
