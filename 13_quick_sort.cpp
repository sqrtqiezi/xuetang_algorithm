#include <iostream>
using namespace std;

typedef struct _Range {
  int start, end;
} Range;

Range create_range(int start, int end) {
  Range range;
  range.start = start;
  range.end = end;
  return range;
}

inline void swap(int* a, int* b) {
  int tmp = *b;
  *b = *a;
  *a = tmp;
}

// 快速排序，迭代版本
void quick_sort(int* arr, int length) {
  if (length <= 0) {
    return;
  }

  // 管理调用栈
  Range ranges[length];
  int p = 0;
  ranges[p++] = create_range(0, length - 1);
  while(p) {
    Range range = ranges[--p];
    if (range.start >= range.end) {
      continue;
    }
    int mid = arr[(range.start + range.end) / 2];
    int left = range.start,
      right = range.end;
    do {
      while (arr[left] < mid) {
        ++left;
      }
      while (arr[right] > mid) {
        --right;
      }
      if (left <= right) {
        swap(&arr[left], &arr[right]);
        left++;
        right--;
      }
    } while(left <= right);

    if(range.start < right) {
      ranges[p++] = create_range(range.start, right);
    }
    if (range.end > left) {
      ranges[p++] = create_range(left, range.end);
    }
  }
}

int main() {
  int* arr;
  int n, i, k;

  scanf("%d", &n);
  arr = (int*)malloc(sizeof(int) * n);
  for(i = 0; i < n; i++) {
    scanf("%d", &k);
    arr[i] = k;
  }

  // 快速排序
  quick_sort(arr, n);

  for(i = 0; i < n; i++){
    printf("%d ", arr[i]);
  }
  printf("\n");

  free(arr);
  return 0;
}