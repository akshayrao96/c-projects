#include <stdio.h>
#include <stdlib.h>
#inlcude 'linked_list.h'
#include 'node.h'

/*
 * Creating a LinkedList in C. It will hold integers.
 * Supported API will be insert_front, insert_back, insert at idx
 * remove_front, remove_back, remove at idx
 * peek_first, peek_last, peek at idx
 * contains, is_empty
 */

int main() {}

void insert_front(LinkedList *list, int val) {
  Node *new_node = init_node(val);
  if (list->front == NULL) {
    list->front = new_node;
    list->back = new_node;
  } else {
    Node *curr_front = list->front;
    list->front = new_node;
    new_node->next = curr_front;
  }
  list->size++;
}
