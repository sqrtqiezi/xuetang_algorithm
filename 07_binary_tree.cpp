#include <iostream>
using namespace std;

typedef struct BTreeNode
{
  int value;
  struct BTreeNode* left;
  struct BTreeNode* right;
} Node, *BTree;

Node* create_node(int value) {
  Node* p;
  if ((p = (Node *)malloc(sizeof(Node))) == NULL)
      return NULL;
  p->value = value;
  p->left = NULL;
  p->right = NULL;
  return p;
}

void insert_btree(BTree btree, Node* node) {
  while (1) {
    if (node->value <= btree->value) {
      if (btree->left == NULL) {
        btree->left = node;
        break;
      } else {
        btree = btree->left;
      }
    } else {
      if (btree->right == NULL) {
        btree->right = node;
        break;
      } else {
        btree = btree->right;
      }
    }
  }
}

// 前序遍历，根左右
void btree_dlr(BTree point) {
  if (point == NULL) return;
  cout << point->value << ' ';
  btree_dlr(point->left);
  btree_dlr(point->right);
}

// 后序遍历，左右根
void btree_lrd(Node* point) {
  if (point == NULL) return;
  btree_lrd(point->left);
  btree_lrd(point->right);
  cout << point->value << ' ';
}

int main() {
  int n, k;
  BTree btree;
  cin >> n;

  while(n-- > 0) {
    cin >> k;
    Node* node = create_node(k);
    if (btree == NULL) {
      btree = node;
    } else {
      insert_btree(btree, node);
    }
  }
  btree_dlr(btree);
  cout << endl;
  btree_lrd(btree);
  cout << endl;
  return 0;
}