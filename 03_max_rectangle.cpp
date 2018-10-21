#include <iostream>
using namespace std;

// 1. 蛮力解法
int getMaxRectangle1(int* heights, int size) {
  int result = 0, tmp;
  for(int i = 0; i < size; i++)
  {
    for(int j = i + 1; j < size + 1; j++)
    {
      if(heights[j] < heights[i])
      {
        tmp = heights[i] * (j - i);
        cout << tmp << endl;
        if (tmp > result)
        {
          result = tmp;
        }
        break;
      }
    }
  }
  return result;
}

// 2. 动态规划法
void processLR(int* heights, int size, int* left, int* right) {
  // 用 left[i] 表示第 i 个柱子可以最多向左延伸至第 left[i] 个柱子
  for (int i = 1; i <= size; i++) {
    int k = i;
    while (heights[i] <= heights[k - 1]) {
      k = left[k - 1];
    }
    left[i] = k;
  }

  // 用 right[i] 表示第 i 个柱子可以最多向右延伸至第 right[i] 个柱子
  for (int i = size; i > 0; i--) {
    int k = i;
    while (heights[i] <= heights[k + 1]) {
      k = right[k + 1];
    }
    right[i] = k;
  }
}

int getMaxRectangle2(int heights[], int size) {
  int result = 0;
  int* left = new int[size + 1];
  int* right = new int[size + 1];
  processLR(heights, size, left, right);
  for(int i = 1; i <= size; i++) {
    int tmp = (right[i] - left[i] + 1) * heights[i];
    if (result < tmp) {
      result = tmp;
    }
  }
  return result;
}

int main() {
  int n, i = 1;
  cin >> n;

  int* heights = new int[n + 2];

  // 直方图左右各添加一个哨兵
  heights[0] = -1;
  while(i <= n)
  {
    cin >> heights[i];
    i++;
  }
  heights[n + 1] = -1;

  int result = getMaxRectangle2(heights, n);
  cout << result << endl;
}