// #include <bits/stdc++.h>
#include <iostream>
#include <stack>

using namespace std;

stack<int> sorting(stack<int> myStack) {
  stack<int> result;
  if (myStack.empty()) 
    return result;
  
  int tmp = myStack.top();
  myStack.pop();
  while (!myStack.empty() || (!result.empty() && tmp > result.top())) {
    if (result.empty() || tmp <= result.top()) {
      result.push(tmp);
      tmp = myStack.top();
      myStack.pop();
    } else {
      myStack.push(result.top());
      result.pop();
    }
  }
  result.push(tmp);
  return result;
}

int main() {
  int n, a;
  stack<int> myStack;

  cin >> n;
  while (n > 0) {
    n--;
    cin >> a;
    myStack.push(a);
  }

  stack<int> result = sorting(myStack);
  while(!result.empty()) {
    cout << result.top() << endl;
    result.pop();
  }
  return 0;
}