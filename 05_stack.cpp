#include <iostream>
using namespace std;

class Stack {
  public:
    Stack(int size) {
      _stack = new string[size];
      _top = -1;
    }

    ~Stack() {
      delete[] _stack;
    }

    void push(string str) {
      _stack[_top + 1] = str;
      _top++;
    }

    void pop() {
      _top--;
    }

    string top() {
      return _stack[_top];
    }

    string seek(int i) {
      return _stack[i - 1];
    }

  private:
    string* _stack;
    int _top;
};

int main() {
  int n, op, i;
  string str;

  cin >> n;
  Stack stack(n);

  while (n > 0) {
    cin >> op;
    switch (op)
    {
    case 1:
      cin >> str;
      stack.push(str);
      break;
    case 2:
      cout << stack.top() << endl;
      stack.pop();
      break;
    case 3:
      cin >> i;
      cout << stack.seek(i) << endl;
      break;
    default:
      break;
    }
    n--;
  }
  return 0;
}