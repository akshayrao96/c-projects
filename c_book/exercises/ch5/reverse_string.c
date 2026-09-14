#include <stdio.h>
#include <string.h>

/* Reverses a string in place */

void reverse_string(char* str);
void reverse_string_ptr(char* str);
void swap(char* str, int i, int j);

int main() {
    char str[] = "crazy";
    printf("%s\n", str);
    reverse_string(str);
    printf("%s\n\n", str);
    
    char str2[] = "reverse this string";
    printf("%s\n", str2);
    reverse_string_ptr(str2);
    printf("%s\n", str2);
}

void reverse_string_ptr(char* str) {

    char* start = str;
    char* end = str;
    char c;
    
    while ((c = *end) != '\0') {
        end++;
    }
    
    end--;

    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

void reverse_string(char* str) {
    int i = 0;
    int j = strlen(str) - 1;

    while (i < j) {
        swap(str, i, j);
        i++;
        j--;
    }
}

void swap(char* str, int i, int j) {
    char temp = *(str + i);
    *(str + i) = *(str + j);
    *(str + j) = temp;
}


