#include <stdio.h>
#include <stdbool.h>

/* This program creates a simple memory allocaters for chars
 * A caller can call the memory allocator function with desired size
 * If can be fulfilled, it's given. Otherwise, informs client of lack of space
 */ 

#define BUFFER_LEN 10000

static char alloc_buffer[BUFFER_LEN];
static char* alloc_p = alloc_buffer; 

char* alloc(size_t bytes) {
    if (alloc_buffer + BUFFER_LEN - alloc_p > (long) bytes) {
        char* curr_ptr = alloc_p;
        alloc_p += bytes;
        return curr_ptr;
    } else {
        return NULL;
    }
}

void alloc_free(size_t bytes) {
    char* base = alloc_buffer;
    if (alloc_p - bytes < base) {
        alloc_p = base;
    } else {
        alloc_p -= bytes;
    }
}



