#include 'node.h'

Node *init_node(int val) {
  Node *node = (Node *)malloc(sizeof(Node));
  node->val = val;
  node->node = NULL;
  return node;
}
