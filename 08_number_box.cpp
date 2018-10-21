#include <iostream>
using namespace std;

typedef long long Type;

typedef struct LinkNode
{
  Type value;
  struct LinkNode* next;
} LinkNode, *Link;

const int Mod = 1000003;
inline int Hash(Type n) {
  return n % Mod;
}

LinkNode* create_node(Type value) {
  Link p;
  p = (LinkNode*)malloc(sizeof(LinkNode));
  p->value = value;
  p->next = NULL;

  return p;
}

bool hash_insert(Link* hash, Type value) {
  int i = Hash(value);
  if (hash[i] == NULL) {
    hash[i] = create_node(value);
    return true;
  }
  Link p = hash[i];
  while(1) {
    if (p->value == value) {
      return false;
    }
    if (p->next == NULL) {
      p->next = create_node(value);
      return true;
    }
    p = p->next;
  }
}

bool hash_find(Link* hash, Type value) {
  int i = Hash(value);
  if (hash[i] == NULL) {
    return false;
  }
  if (hash[i]->value == value) {
    hash[i] = NULL;
    return true;
  }
  Link parent = hash[i];
  Link p = parent->next;
  while(p != NULL) {
    if (p->value == value) {
      parent->next = p->next;
      free(p);
      return true;
    }
    parent = p;
    p = parent->next;
  }
  return false;
}

int main() {
  int n, op;
  Type k;
  Link* hash = new Link[Mod];
  for(int i = 0; i < Mod; i++) {
    hash[i] = NULL;
  }
  cin >> n;
  
  while (n-- > 0) {
    cin >> op >> k;
    switch (op) {
      case 1:
        if (hash_insert(hash, k)) {
          cout << "Succeeded" << endl;
        } else {
          cout << "Failed" << endl;
        }
        break;
      case 2:
        if (hash_find(hash, k)) {
          cout << "Succeeded" << endl;
        } else {
          cout << "Failed" << endl;
        }
        break;
      default:
        break;
    }
  }

  for (int i =0; i < Mod; i++) {
    if (hash[i] != NULL) {
      LinkNode* p = hash[i];
      LinkNode* next;
      while(p != NULL) {
        next = p->next;
        free(p);
        p = next;
      }
    }
  }
  return 0;
}