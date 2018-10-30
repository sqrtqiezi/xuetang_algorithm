#include <iostream>
using namespace std;

inline void swap(int* a, int* b) {
  int tmp = *b;
  *b = *a;
  *a = tmp;
}

// 快速排序 - 递归版本
void quick_sort_recursive(int* arr, int start, int end) {
  if (start >= end) {
    return;
  }
  int mid = arr[end];
  int left = start, right = end - 1;
  while (left < right) {
    while (arr[left] < mid && left < right) {
      left++;
    }
    while (arr[right] >= mid && left < right) {
      right--;
    }
    swap(&arr[left], &arr[right]);
  }
  if (arr[left] >= arr[end]) {
    swap(&arr[left], &arr[end]);
  } else {
    left++;
  }
  if(left) {
    quick_sort_recursive(arr, start, left - 1);
  }
  quick_sort_recursive(arr, left + 1, end);
}

void quick_sort(int* arr, int length) {
  quick_sort_recursive(arr, 0, length - 1);
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