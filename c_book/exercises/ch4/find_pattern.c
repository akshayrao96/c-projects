#include <stdio.h>
#include <stdbool.h>
#define MAXLINES 1000


/* This program finds lines that matches the pattern and prints it */ 

int get_line(char line[], FILE* file);
bool has_pattern(char pattern[], char line[]);

int main() {

	// Open a file, declare the pattern
	FILE* file = fopen("lines.txt", "r");
	char pattern[] = "ould";
	char line[MAXLINES];
	int c;	

	if (file == NULL) {
		printf("file not found\n");
		return 1;
	}
	
	while ((c = get_line(line, file)) > 0) {
        if (has_pattern(pattern, line)) {
			printf("%s\n", line);
		}
	}
}

int get_line(char line[], FILE* file) {
	int curr_count;
	int i;
	int c;
    
    curr_count = 0;
	i = 0;
	
	c = fgetc(file);
	while (c != EOF && c != '\n') {
		line[i++] = c;
		curr_count++;
		c = fgetc(file);
	}

	line[i] = '\0';
	return curr_count;
}

bool has_pattern(char pattern[], char line[]) {
	int i = 0;
	int j = 0;

	while (line[j] != '\0') {
        if (line[j] == ' ') {
			i = 0;
		} else if (pattern[i] == line[j]) {
			i++;
		}

		if ((pattern[i]) == '\0') {
			return true;
		}
		j++;
	}
	return false;
}




