#include "linked_list.h"

/*
 * Creating a LinkedList in C. It will hold integers.
 * Supported API will be insert_front, insert_back, insert at idx
 * remove_front, remove_back, remove at idx
 * peek_first, peek_last, peek at idx
 * contains, is_empty
 */

int main() {}

LinkedList *init_linked_list() {
  LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
  list->size = 0;
  list->front = NULL;
  list->back = NULL;
  return list;
}

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

void insert_back(LinkedList *list, int val) {
  Node *new_node = init_node(val);
  if (list->back == NULL) {
    list->front = new_node;
    list->back = new_node;
  } else {
    Node *curr_back = list->back;
    list->back = new_node;
    curr_back->next = new_node;
  }
}

bool insert(LinkedList *list, int val, int idx) {
  if (idx < 0 || idx > list->size) {
    return false;
  }

  if (idx == list->size) {
    insert_back(list, val);
  } else if (idx == 0) {
    insert_front(list, val);
  } else {
    int curr_idx = 0;
    Node *curr_node = list->front;
    while (curr_idx == idx - 1) {
      curr_node = curr_node->next;
    }
    Node *new_node = init_node(val);
    Node *next_node = curr_node->next;
    curr_node->next = new_node;
    new_node->next = next_node;
  }

  list->size++;
}

bool remove_front(LinkedList *list) {
  if (list->size == 0) {
    return false;
  }

  Node *front_node = list->front;
  list->front = front_node->next;

  if (list->front == NULL) {
    list->back = NULL;
  }

  free_node(front_node);

  list->size--;

  return true;
}

bool remove_back(LinkedList *list) {
  if (list->size == 0) {
    return false;
  }

  if (list->size == 1) {
    Node *removal_node = list->front;
    list->front = NULL;
    list->back = NULL;
    free_node(removal_node);
    list->size--;
  } else {
    remove_node(list, list->size - 1);
  }

  return true;
}

bool remove_node(LinkedList *list, int idx) {
  if (idx < 0 || idx >= list->size || list->size == 0) {
    return false;
  }

  int curr_idx = 0;
  Node *curr_node = list->front;

  while (curr_idx != idx - 1) {
    curr_node = curr_node->next;
  }

  Node *removal_node = curr_node->next;
  Node *next_node = removal_node->next;

  curr_node->next = next_node;
  free_node(removal_node);

  list->size--;
}

bool contains_val(LinkedList *list, int val) {
  Node *curr_node = list->front;
  while (curr_node != NULL) {
    if (curr_node->val == val) {
      return true;
    }
    curr_node = curr_node->next;
  }
  return false;
}

bool is_empty(LinkedList *list) { return list->size == 0; }
