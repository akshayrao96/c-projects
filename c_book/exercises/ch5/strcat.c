#include <stdio.h>

/* This program concatenates 2 strings
 * It appends string t onto string s, to practice pointer arithmetic.
 * Example: s = "tattoo" t = "shop", output = "tattooshop" 
*/ 

#define SIZE 100

void strcat_custom(char* s, char* t);

int main() {
    char s[SIZE] = "tattoo";
    char t[] = "shop";

    strcat_custom(s, t);

    printf("Output is : %s\n", s);
}

void strcat_custom(char* s, char* t) {
    char* s_temp = s;

    while (*s_temp != '\0') {
        s_temp++;
    }

    int i = (s_temp - s);
    s_temp = s;

    while (*t != '\0') {
        s[i++] = *t;
        t++;
    }

    s[i] = '\0';
}
