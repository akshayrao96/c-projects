#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define CHARS 26
#define LOWER 'a'
#define UPPER 'A'

/*
* Returns count of special characters
* A special character is defined as found as uppercase and lowercase in word
* 
* Input  = "aaAbcBC"
* Output = 3 (a and A, b and B, c and C)
*
* Input  = "abc"
* Output = 0 
*
* Input  = abBCab
* Output = 1 (b and B)
*/

static int number_of_special_chars(char* word);

int main() {
    char input[] = "aaAbCBc";
    int res = number_of_special_chars(input);
    printf("Case 1: Expected : %d, Output : %d\n", 3, res);

    char input2[] = "abc"; 
    int res2 = number_of_special_chars(input2);
    printf("Case 2: Expected : %d, Output : %d\n", 0, res2);
    
    char input3[] = "abBCab";
    int res3 = number_of_special_chars(input3);
    printf("Case 3: Expected : %d, Output : %d\n", 1, res3);

    char input4[] = "aA";
    int res4 = number_of_special_chars(input4);
    printf("Case 4: Expected : %d, Output : %d\n", 1, res4);
}


int number_of_special_chars(char* word) {
    int lower_mask = 0;
    int upper_mask = 0; 
    int i = 0;
    int c;
    
    while ((c = word[i++]) != '\0') {
        if (islower(c)) {
            int shift = c - LOWER;
            int temp_pattern = 1 << shift;
            lower_mask |= temp_pattern;
        } else if (isupper(c)) {
            int shift = c - UPPER;
            int temp_pattern = 1 << shift;
            upper_mask |= temp_pattern;
        }
    }
    
    int common_mask = lower_mask & upper_mask;
    
    return __builtin_popcount(common_mask);
}

