#include <iostream>
#include <vector>
using namespace std;

// 判断 arr 数组是否能分成不超过 m 份，满足每一份数字之和不超过 d
bool check(long long d, int n, int m, vector<int>& arr) {
  long long sum = 0; // 记录当前那一份的数字之和
  int cnt = 1;
  for (int i = 0; i < n; i++) {
    if (arr[i] > d) {
      return false;
    }
    sum += arr[i];
    if (sum > d) {
      cnt++;
      sum = 0;
      i--;
    }
  }
  return cnt <= m;
}

long long solve(int n, int m, vector<int>& arr) {
  // l 表示答案的下界
  long long l = 1, r = 0;
  // r 表示答案的上界
  for (int i = 0; i < n; i++) {
    r += arr[i];
  }
  // 二分法解答
  while (l <= r) {
    long long mid = (l + r) >> 1;
    if (check(mid, n, m, arr)) { // 验证 mid 可不可能为答案，如果可能，则答案在 [1, mid] 里，上界缩小
      r = mid - 1;
    } else { // 否则，答案在 [mid + 1, r] 里，下界缩小
      l = mid + 1;
    }
  }
  return r + 1;
}

int main() {
  int n, m, k;
  cin >> n >> m;
  vector<int> arr;
  arr.resize(n);

  for (int i = 0; i < n; i++) {
    cin >> k;
    arr[i] = k;
  }

  cout << solve(n, m, arr) << endl;
  return 0;
}