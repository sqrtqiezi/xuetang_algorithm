#include <iostream>
#include <vector>
using namespace std;

int mask;
vector<bool> vis[2];
string result;

// 计算 2 的 x 次方
int twoPow(int x) {
  return 1 << x;
}

// 深度优先搜索
void dfs(int u) {
  for (int i = 0; i < 2; i++) {
    if (!vis[i][u]) {
      int v = (( u << 1) | i) & mask;
      vis[i][u] = 1;

      dfs(v);
      result.push_back('0' + i);
      // cout << result << endl;
    }
  }
}

string solve(int n) {
  mask = twoPow(n - 1) -1;
  result = "";
  for (int i = 0; i < 2; i++) {
    vis[i].resize(twoPow(n - 1), 0);
  }
  dfs(0);
}

int main() {
  int n; 
  cin >> n;
  solve(n);
  cout << result << endl;
  return 0;
}