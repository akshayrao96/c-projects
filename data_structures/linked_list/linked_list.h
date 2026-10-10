#include <stdlib.h>
#include <stdbool.h>
#include "node.h"

typedef struct {
    size_t size;
    Node* front;
    Node* back;
} LinkedList;

LinkedList* init_linked_list();

/* Inserts at front of the list */
void insert_front(LinkedList* list, int val);

/* Inserts at back of the list */
void insert_back(LinkedList* list, int val);

/* Inserts at given index. After inserting, element is at given index. False if unable to */
bool insert(LinkedList* list, int val, int idx);

/* Remove value from front of the list. False if list is empty */
bool remove_front(LinkedList* list);

/* Remove value from back of the list. False if list is empty */
bool remove_back(LinkedList* list);

/* Remove value at current index. False if list is smaller than index */
bool remove_node(LinkedList* list, int idx);
 
/* Return true if list contains val */
bool contains_val(LinkedList* list, int val);

/* Return true if list is empty */
bool is_empty(LinkedList* list);

