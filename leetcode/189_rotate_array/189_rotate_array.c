#include <stdio.h>
#include <assert.h>
#include <string.h>

/*
 * Rotates a given array by k spots to the right
 * Input  =  [1, 2, 3, 4, 5, 6, 7] k = 3
 * Output =  [5, 6, 7, 1, 2, 3, 4]
 * [2] [3, 4, 5, 6, 7, 1] 
 * Input =  [1, 2, 3, 4, 5, 6, 7, 8, 10] k = 2
 * Output = [8, 10, 1, 2, 3, 4, 5, 6, 7]
 *
 * Input  =  [4, 10, 20, -100] k = 1
 * Output =  [-100, 4, 10, 20]
 * 
 * Input  = [4, 10, 20, -100] k = 6
 * Output = [20, -100, 4, 10]
*/

static void rotate(int* nums, int numSize, int k);
static void reverse(int* nums, int i, int j);
static void swap(int* nums, int i, int j);
static void assert_eq(int* actual, int* expected, int len);

int main() {

    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int len_1 = 7;

    /* case 1 */
    int a_1[len_1];
    memcpy(a_1, arr, sizeof(arr));
    rotate(a_1, len_1, 3);
    int e_1[] = {5, 6, 7, 1, 2, 3, 4};
    assert_eq(a_1, e_1, len_1);
	
    /* case 2 */
    memcpy(a_1, arr, sizeof(arr));
    rotate(a_1, len_1, 6);
    int e_2[] = {2, 3, 4, 5, 6, 7, 1};
    assert_eq(a_1, e_2, len_1);

    /* case 3 */
    memcpy(a_1, arr, sizeof(arr));
    rotate(a_1, len_1, 35);
    assert_eq(a_1, a_1, len_1);
}

void rotate(int* nums, int numSize, int k) {
    k = k % numSize;
    int first = 0;
    int last = numSize - 1;
    int reverse_point = last - k;

    reverse(nums, first, reverse_point);
    reverse(nums, reverse_point + 1, last);
    reverse(nums, first, last);
}

void reverse(int* nums, int i, int j) {
    while (i < j) {
        swap(nums, i++, j--);
    }
}

void swap(int* nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp; 
}

void assert_eq(int* actual, int* expected, int len) {
    for (int i = 0; i < len; i++) {
        assert(actual[i] == expected[i]);
    }
}
