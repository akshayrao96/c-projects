#include <stdio.h>

int main() {
   
    float celsius, farenheit;
    int start = -40;
    int end = 100;
    int step = 20;
    celsius = start;

    while (start <= end) {
        farenheit = ((celsius * 9.0) / 5.0) + 32;
        printf("%5.1f\t%6.1f\n", celsius, farenheit);
        start += step;
        celsius = start;
    }
}


