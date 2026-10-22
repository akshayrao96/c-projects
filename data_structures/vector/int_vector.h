#include <stdlib.h>
#include <stdbool.h>

typedef struct {
      int *data;
      size_t cap;
      size_t len;
} Vec;

Vec* init_vec();
bool push_back(Vec *v, int value);
int get_size(Vec *v);
