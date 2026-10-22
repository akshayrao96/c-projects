#include "int_vector.h"
#include <stdbool.h>

Vec *init_vec() {
      Vec *vec = (Vec *)malloc(sizeof(Vec));
      vec->data = NULL;
      vec->cap = 0;
      vec->len = 0;
      return vec;
}

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
      return true;
}

int get_size(Vec *v) { return v->len; }
