#include "linked_list.h"

int main() {
  LinkedList *list = init_linked_list();
  int value;
  insert_back(list, 5);
  insert_back(list, 10);
  insert_back(list, 20);
  // 5, 10, 20

  get_last_val(list, &value);
  printf("EXPECTED: 20, RECEIVED: %d\n", value);
  remove_front(list);
  // 10, 20

  get_first_val(list, &value);
  printf("EXPECTED: 10, RECEIVED: %d\n", value);

  insert_front(list, 100);
  insert_back(list, 200);
  // 100, 10, 20, 200

  get_first_val(list, &value);
  printf("EXPECTED: 100, RECEIVED: %d\n", value);

  get_last_val(list, &value);
  printf("EXPECTED 200, RECEIVED: %d\n", value);

  remove_node(list, 2);
  // 100, 10, 200

  remove_front(list);
  // 10, 200

  get_first_val(list, &value);
  printf("EXPECTED: 10, RECEIVED: %d\n", value);

  get_last_val(list, &value);
  printf("EXPECTED 200, RECEIVED: %d\n", value);

  free_list(list);
}
