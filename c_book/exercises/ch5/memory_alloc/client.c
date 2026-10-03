#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "alloc.h"
/* This program calls the alloc function to obtain some memory/buffer */

int main() {
   
    size_t first_size = 10;
    char* buffer = alloc(first_size);

    memset(buffer, 'A', first_size);
    
    buffer[first_size - 1] = '\0';

    printf("%s\n", buffer);
    
    // should print 90
    free_space();
    alloc_free(buffer);
    
    // should print 100
    free_space();
}
