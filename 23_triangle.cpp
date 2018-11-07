#include <vector>
#include <cstdio>
using namespace std;

// ================= 代码实现开始 =================

/* 请在这里定义你需要的全局变量 */

// 本函数计算答案（最大经过位置数字总和）
// n：描述数字三角形大小，意义同题目描述
// a：描述整个数字三角形，第 i 行的第 j 个数存放在 a[i][j]
// 中（你需要特别注意的是，所有下标均从 1 开始，也就是说下标为 0 的位置将存放无效信息）
// 返回值：最大经过位置数字总和
int getAnswer(int n, vector<vector<int> >& a) {
  vector<vector<int> > dp;
  dp.resize(n + 1);
  for (int i = 0; i <= n; ++i)
    dp[i].resize(i + 2);
  for (int i = 0; i <= n; ++i)
    for (int j = 0; j <= i; ++j)
      dp[i][j] = 0;

  dp[1][1] = a[1][1];
  for (int i = 2; i <= n; ++i) {
    dp[i][0] = 0;
    dp[i][i+1] = 0;
    for (int j = 1; j <= i; ++j) {
      dp[i][j] = max(dp[i-1][j] + a[i][j], dp[i-1][j-1] + a[i][j]);
    }
  }

  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans = max(ans, dp[n][i]);
  }
  return ans;
}

// ================= 代码实现结束 =================

int main() {
  int n;
  vector<vector<int> > a;
  scanf("%d", &n);
  a.resize(n + 1);
  for (int i = 0; i <= n; ++i)
    a[i].resize(i + 1);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= i; ++j)
      scanf("%d", &a[i][j]);
  int ans = getAnswer(n, a);
  printf("%d\n", ans);
  return 0;
}
