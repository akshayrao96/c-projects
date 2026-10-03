#include <stdio.h>
#include <stdbool.h>

/* This program creates a simple memory allocaters for chars
 * A caller can call the memory allocator function with desired size
 * If can be fulfilled, it's given. Otherwise, informs client of lack of space
 */ 

#define BUFFER_LEN 100

static char alloc_buffer[BUFFER_LEN];
char* alloc_p = alloc_buffer;
char* alloc_p_start = alloc_buffer;

char* alloc(size_t bytes) {
    if (alloc_buffer + BUFFER_LEN - alloc_p >= (long) bytes) {
        char* curr_ptr = alloc_p;
        alloc_p += bytes;
        return curr_ptr;
    } else {
        return NULL;
    }
}

void alloc_free(char* ptr) {
    if (ptr >= alloc_p && ptr < (alloc_p + BUFFER_LEN)) {
        alloc_p = ptr;
    }
}

void free_space() {
    char* alloc_p_end = alloc_p_start + BUFFER_LEN;
    size_t free_space_left = (size_t) (alloc_p_end - alloc_p);
    printf("size left: %zu\n", free_space_left);
}
