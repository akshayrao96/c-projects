#include "node.h"
#include <stdlib.h>

Node *init_node(int val) {
  Node *node = (Node *)malloc(sizeof(Node));
  node->val = val;
  node->next = NULL;
  return node;
}

void free_node(Node *node) { free(node); }
