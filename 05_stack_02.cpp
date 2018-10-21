#include <iostream>
using namespace std;

string* stack;
int top;

void stack_push(string str) {
  stack[++top] = str;
};

void stack_pop() {
  top--;
}

string stack_seek(int i) {
  return stack[i - 1];
}

string stack_top() {
  return stack[top];
}

int main() {
  int n, op, i;
  string str;

  cin >> n;
  stack = new string[n];
  top = -1;

  while (n > 0) {
    cin >> op;
    switch (op)
    {
    case 1:
      cin >> str;
      stack_push(str);
      break;
    case 2:
      cout << stack_top() << endl;
      stack_pop();
      break;
    case 3:
      cin >> i;
      cout << stack_seek(i) << endl;
      break;
    default:
      break;
    }
    n--;
  }
  return 0;
}