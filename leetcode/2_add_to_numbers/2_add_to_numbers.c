#include <stdio.h>
#include <stdlib.h>

#define TENS 10

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode *nextCurr(int num);
struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2);

int main() {
  // to fill up
}
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

  while (l1 != NULL && l2 != NULL) {
    int num = l1->val + l2->val + carry;

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

    l1 = l1->next;
    l2 = l2->next;
  }

  struct ListNode *temp = l1 != NULL ? l1 : l2;

  while (temp != NULL) {
    int num = temp->val + carry;

    carry = num >= TENS ? 1 : 0;

    if (num >= TENS) {
      num %= TENS;
    }

    curr->next = nextCurr(num);
    curr = curr->next;
    temp = temp->next;
  }

  if (carry == 1) {
    curr->next = nextCurr(1);
    curr = curr->next;
  }

  return result;
}
