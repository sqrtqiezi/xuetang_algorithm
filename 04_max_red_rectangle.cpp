#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solveInRow(int* heights, int n) {
  int result = 0;
  stack<int> myStack;
  myStack.push(0);

  for (int i = 1; i <= n+1; ++i) {
    while(heights[myStack.top()] > heights[i]) {
      int nowHeight = heights[myStack.top()];
      myStack.pop();
      result = max(result, nowHeight * (i - myStack.top() - 1));
    }
    myStack.push(i);
  }
  return result;
}

int solve(string* matrix, int n, int m) {
  int maxrect = 0;
  int* heights = new int[m + 2];

  for (int i = 0; i < m + 2; i++) {
    heights[i] = 0;
  }

  for (int i = 0; i < n; i ++) {
    for (int j = 0; j < m; j++) {
      if (matrix[i][j] == 'X') {
        heights[j + 1] = 0;
      } else {
        heights[j + 1]++;
      }
    }
    maxrect = max(maxrect, solveInRow(heights, m));
  }

  return maxrect;
}

int main() {
  int n, m;
  cin >> n >> m;

  string* matrix = new string[n];
  for(int i = 0; i < n; i++) {
    cin >> matrix[i];
  }
  cout << solve(matrix, n, m) << endl;

  delete [] matrix;
  return 0;
}