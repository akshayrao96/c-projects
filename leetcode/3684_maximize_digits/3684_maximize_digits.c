/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MIN_VAL(a, b) ((a < b) ? (a) : (b))
#define MAX_VAL(a, b) ((a > b) ? (a) : (b))

/* Dynamic array struct */
typedef struct {
      int cap;
      int len;
      int *data;
} Vec;

/* Priority Queue struct */
typedef struct {
      Vec *vec;
      int size;
} PriorityQueue;

/* Adding to the vector */
bool vec_push(Vec *vec, int num) {
      if (vec->cap == vec->len) {
            int cap = vec->data != NULL ? vec->cap * 2 : 8;
            int *new_data = (int *)realloc(vec->data, cap * sizeof(int));

            if (new_data == NULL) {
                  return false;
            }

            vec->cap = cap;
            vec->data = new_data;
      }

      vec->data[vec->len] = num;
      vec->len++;
      return true;
}

/* Helper - ideally with good design, these go to seperate files */
int get_percolate_up_idx(int idx) {
      return idx % 2 == 0 ? (idx / 2) - 1 : idx / 2;
}

/* Helper */
int get_percolate_up_val(Vec *vec, int idx) {
      return idx % 2 == 0 ? vec->data[(idx / 2) - 1] : vec->data[(idx / 2)];
}

/* Helper */
int get_left_child(Vec *vec, int idx) {
      int next_idx = (idx * 2) + 1;
      return next_idx < vec->len ? vec->data[next_idx] : -1;
}

int get_right_child(Vec *vec, int idx) {
      int next_idx = (idx * 2) + 2;
      return next_idx < vec->len ? vec->data[next_idx] : -1;
}

int get_left_child_idx(int idx) { return (idx * 2) + 1; }

int get_right_child_idx(int idx) { return (idx * 2) + 2; }

/* Swaps 2 indices in an array */
void swap(Vec *vec, int a, int b) {
      int temp = vec->data[a];
      vec->data[a] = vec->data[b];
      vec->data[b] = temp;
}

/* Helper */
void percolate_up(Vec *vec) {
      int idx = vec->len - 1;
      while ((idx != 0) && (vec->data[idx] > get_percolate_up_val(vec, idx))) {
            swap(vec, idx, get_percolate_up_idx(idx));
            idx = get_percolate_up_idx(idx);
      }
}

void percolate_down(Vec *vec) {
      if (vec->len == 0)
            return;

      int idx = 0;
      int largest_idx = idx;
      int largest = vec->data[largest_idx];

      do {
            swap(vec, idx, largest_idx);
            idx = largest_idx;

            int left = get_left_child(vec, idx);
            int right = get_right_child(vec, idx);

            largest = MAX_VAL(left, right);
            largest_idx = largest == left ? get_left_child_idx(idx)
                                          : get_right_child_idx(idx);

      } while (vec->data[idx] < largest);
}

bool vec_empty(Vec *vec) { return vec->len == 0; }

void push(PriorityQueue *pq, int num) {
      vec_push(pq->vec, num);
      pq->size++;
      percolate_up(pq->vec);
}

int pop(PriorityQueue *pq) {
      int val = pq->vec->data[0];
      swap(pq->vec, 0, pq->vec->len - 1);
      pq->vec->len--;
      percolate_down(pq->vec);
      pq->size--;
      return val;
}

int peek(PriorityQueue *pq) {
      int val = pq->vec->data[0];
      return val;
}

bool is_empty(PriorityQueue *pq) { return pq->size == 0; }

Vec *init_vec() {
      Vec *vec = (Vec *)malloc(sizeof(Vec));
      vec->cap = 0;
      vec->len = 0;
      vec->data = NULL;
      return vec;
}

PriorityQueue *init_pq() {
      PriorityQueue *pq = (PriorityQueue *)malloc(sizeof(PriorityQueue));
      pq->size = 0;
      pq->vec = init_vec();
      return pq;
}

/* Business logic, gets the top K elements based on digit size */
int *maxKDistinct(int *nums, int numsSize, int k, int *returnSize) {
      PriorityQueue *pq = init_pq();
      for (int i = 0; i < numsSize; i++) {
            int num = nums[i];
            push(pq, num);
      }

      int temp[numsSize];
      int idx = 0;

      while (!is_empty(pq) && idx < k) {
            int val = pop(pq);
            if (idx == 0 || temp[idx - 1] != val) {
                  temp[idx++] = val;
            }
      }

      int *result = (int *)malloc(idx * sizeof(int));
      for (int i = 0; i < idx; i++) {
            result[i] = temp[i];
      }
      *returnSize = idx;
      free(pq->vec->data);
      free(pq->vec);
      free(pq);
      return result;
}
