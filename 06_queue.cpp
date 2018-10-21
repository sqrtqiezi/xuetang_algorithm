#include <iostream>
using namespace std;

int _size, _begin, _end;
string* _queue;

void queue_init(int n) {
  _size = n;
  _begin = 0;
  _end = 0;
  _queue = new string[_size];
}

void queue_add(string str) {
  _queue[_end++] = str;
  if (_end == _size) {
    _end = 0;
  }
}

string& queue_poll() {
  int tmp = _begin++;
  if (_begin == _size) {
    _begin = 0;
  }
  return _queue[tmp];
}

string& queue_seek(int i) {
  return _queue[(_begin + i - 1) % _size];
}

int main() {
  int n, op, i;
  string str;
  cin >> n;
  queue_init(n);

  while (n > 0) {
    cin >> op;
    switch (op) {
      case 1:
        cin >> str;
        queue_add(str);
        break;
      case 2:
        cout << queue_poll() << endl;
        break;
      case 3:
        cin >> i;
        cout << queue_seek(i) << endl;
        break;
      default:
        break;
    }
    n--;
  }

  return 0;
}