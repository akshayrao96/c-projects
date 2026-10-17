#include <ctype.h>
#include <stdio.h>

int main() {

  char c;

  while ((c = getchar()) != EOF) {
    putchar(tolower(c));
  }
}
