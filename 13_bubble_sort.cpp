#include <iostream>
using namespace std;

void buble_sort(int* arr, int length) {
  int i, j, tmp;
  for (i = 0; i < length - 1; i++) {
    for (j = 0; j < length - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        // 交换
        tmp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = tmp;
      }
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

  // 冒泡排序
  buble_sort(arr, n);

  for(i = 0; i < n; i++){
    printf("%d ", arr[i]);
  }
  printf("\n");

  free(arr);
  return 0;
}