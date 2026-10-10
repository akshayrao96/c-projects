#include <stdio.h>

typedef struct Node {
    int val;
    struct Node* next;
} Node;

/* Create a node */
Node* init_node(int val);

void free_node(Node* node);

