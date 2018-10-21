#include <iostream>
using namespace std;

int aPlusB(int a, int b) {
  return a + b;
}

int main() {
  int a, b;
  cin >> a >> b;
  cout << aPlusB(a,b) << endl;
  return 0;
}