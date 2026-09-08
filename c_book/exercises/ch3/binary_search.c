#include <stdio.h>
#include <stdbool.h>

#define DEFAULT -1

int binsearch(int val, int arr[], int len); 

int main() {
	int arr[10] = {1, 4, 9, 31, 43, 85, 99, 102, 103, 302};
	int len = 10;

	int values[6] = {9, 1, 44, 103, 302, 402};
	int expected[6] = {2, 0, -1, 8, 9, -1};
	int result[6] = {0};
	
	bool success = true;
	for (int i = 0; i < 6; i++) {
		result[i] = binsearch(values[i], arr, len);
		if (result[i] != expected[i]) {
			printf("Assertion failed on case %d. Actual: %d, Expected: %d\n", i, result[i], expected[i]);
			success = false;
		}
	}

	if (success) {
		printf("ALL TESTS PASSED\n");
	}
}

int binsearch(int val, int arr[], int len) {
	int left = 0;
	int right = len - 1;
	
	while (left < right) {
		int mid = left + (right - left) / 2;
		if (arr[mid] < val) {
			left = mid + 1;
		} else {
			right = mid;
		}
	}

	if (arr[left] == val) {
		return left;
	} else {
		return DEFAULT;
	}
}
