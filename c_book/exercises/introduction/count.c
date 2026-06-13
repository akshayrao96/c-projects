#include <stdio.h>

int main() {
    FILE* file = fopen("17_lines.txt", "r");
    
    int count;
    int c;
    
    count = 0;

    if (file == NULL) {
        printf("file not found");
        return 1;
    }

    c = fgetc(file);
    while (c != EOF) {
        if (c == '\n') {
            ++count;
        }
        c = fgetc(file);
    }

    printf("%d\n", count);
}
