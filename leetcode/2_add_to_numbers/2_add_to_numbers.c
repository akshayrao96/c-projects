#include <stdio.h>
#include <stdlib.h>

#define TENS 10

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode *nextCurr(int num) {
  struct ListNode *ptr = (struct ListNode *)malloc(sizeof(struct ListNode));
  ptr->val = num;
  ptr->next = NULL;
  return ptr;
}

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {

  struct ListNode *result = NULL;
  struct ListNode *curr = result;
  int carry = 0;

  while (l1 != NULL || l2 != NULL || carry == 1) {
    int num = (l1 != NULL ? l1->val : 0) + (l2 != NULL ? l2->val : 0) + carry;

    carry = num >= TENS ? 1 : 0;

    if (num >= TENS) {
      num %= TENS;
    }

    if (result == NULL) {
      result = nextCurr(num);
      curr = result;
    } else {
      curr->next = nextCurr(num);
      curr = curr->next;
    }

    l1 = (l1 != NULL ? l1->next : NULL);
    l2 = (l2 != NULL ? l2->next : NULL);
  }

  return result;
}
