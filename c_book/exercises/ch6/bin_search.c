#include <stdio.h>
#include <string.h>

/*
 * Decomposing the problem
 * 1) we will need to first get our word, make sure its not greater than maxWord
 * 2) binary search on our array of structs to see which struct it is
 * 3) If it matches, increment the count field. If not, don't do anything
 * 4) For each struct, print out the keyword name, and the occurrence
 */

#define DEFAULT_LEN 50
#define NKEYS (int)(sizeof(keytab) / sizeof(keytab[0]))

struct key {
  char *key_name;
  int count;
} keytab[] = {{"auto", 0},  {"break", 0},    {"case", 0},    {"char", 0},
              {"const", 0}, {"continue", 0}, {"default", 0}, {"unsigned", 0},
              {"void", 0},  {"volatile", 0}, {"while", 0}};

int bin_search(char word[]);

int main() {
  char word[DEFAULT_LEN];
  while (scanf("%s", word) != EOF) {
    int pos = bin_search(word);
    if (pos >= 0) {
      keytab[pos].count++;
    }
  }

  for (int i = 0; i < NKEYS; i++) {
    printf("key name: %s, occurrence: %d\n", keytab[i].key_name,
           keytab[i].count);
  }
}

int bin_search(char word[]) {
  int left = 0;
  int right = NKEYS - 1;

  while (left <= right) {
    int mid = left + (right - left) / 2;
    int val = strcmp(word, keytab[mid].key_name);
    if (val == 0) {
      return mid;
    } else if (val < 0) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  return -1;
}
