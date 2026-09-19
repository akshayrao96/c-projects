#include <stdio.h>

/* This program creates a simple memory allocaters for chars
 * A caller can call the memory allocator function with desired size
 * If can be fulfilled, it's given. Otherwise, informs client of lack of space
 */ 

#define ALLOC_BUFFER 10000

int main() {
    // allocate 100 bytes of space to the pointer
    char* space = alloc(100);
    
    if (space == NULL) {
        printf("Requested too much space. Please free some previous space, or allocate less space!");
        return 1;
    }
    
    int space_left = get_space();
    free_alloc(space);

    
    
    

}



