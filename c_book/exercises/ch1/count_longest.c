#include <stdio.h>

/* Program counts the longest line from given input
*  It also stores the longest line in an array
*/

#define MAXLINES 1000


int getLine(char line[], FILE* file);
void copy(int count, char line[], char max_line[]);

int main() {

	FILE* file = fopen("17_lines.txt", "r");
	int count;
	int max_count;
	char line[MAXLINES];
	char max_line[MAXLINES];

	count = 0;
	max_count = 0;

	if (file == NULL) {
		printf("file not found");
		return 1;
	}

	while ((count = getLine(line, file)) > max_count) {
		max_count = count;
		copy(count, line, max_line);
	}

	if (max_count > 0) {
		printf("longest line: %s\n", max_line);
	}
}

int getLine(char line[], FILE* file) {
	int curr_count;
	int i;
	int c;
	
	i = 0;
	curr_count = 0;

	c = fgetc(file);
	while (c != EOF && c != '\n') {
		line[i++] = c;
		curr_count += 1;
		c = fgetc(file);
	}
	line[i] = '\0';
	return curr_count;
}

void copy(int count, char line[], char longest_line[]) {
	int i;
	for (i = 0; i < count; i++) {
		longest_line[i] = line[i];
	}
}
	
