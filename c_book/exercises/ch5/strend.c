#include <stdio.h>

/* This program checks if the 2nd string is in the 1st string ending
 * Example: "programming" and "ming" return 1. "apple" and "" return 1
 * "programming" and "gram" return 0. "cat" and "bobcat" return 0
*/ 

int get_str_end(char* s, char* t);

int main() {
    // case 1
    char s1[] = "programming";
    char t1[] = "ming";
    printf("case 1. Received %d. Expected 1\n", get_str_end(s1, t1));

    char s2[] = "apple";
    char t2[] = "";
    printf("case 2. Received %d. Expected 1\n", get_str_end(s2, t2));


    char s3[] = "programming";
    char t3[] = "gram";
    printf("case 3. Received %d. Expected 0\n", get_str_end(s3, t3));

    char s4[] = "cat";
    char t4[] = "bobcat";
    printf("case 4. Received %d. Expected 0\n", get_str_end(s4, t4));
}

int get_str_end(char* s, char* t) {
    char* s_temp = s;
    char* t_temp = t;

    char c;

    while ((c = *s_temp) != '\0') {
        s_temp++;
    }

    while ((c = *t_temp) != '\0') {
        t_temp++;
    }

    s_temp--;
    t_temp--;

    // 1) check t_temp is finished. 2) check s_temp is finished 3) different character
    while (s_temp > s && t_temp > t)  {
        if (*s_temp != *t_temp) {
            return 0;
        }
        s_temp--;
        t_temp--;
    }

    if (t_temp > t) {
        return 0;
    } else {
        return 1;
    }
}
