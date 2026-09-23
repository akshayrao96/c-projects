#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "alloc.h"
/* This program calls the alloc function to obtain some memory/buffer */

int main() {
   
    size_t first_size = 100;
    char* buffer = alloc(first_size);
    memset(buffer, 'A', first_size);
    buffer[first_size - 1] = '\0';
    for (size_t i = 0; i < first_size; i++) {
        printf("%s\n", buffer);
    }

    alloc_free(first_size);
}
