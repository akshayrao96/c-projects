#include "int_vector.h"
#include <stdio.h>

int main() {
      Vec *vec = init_vec();
      push_back(vec, 10);
      push_back(vec, 20);
      push_back(vec, 30);

      size_t count = 0;
      while ((count != vec->len)) {
            printf("NUMBER: %d\n", *((vec->data) + count));
            ++count;
      }
      free(vec->data);
      free(vec);
}
