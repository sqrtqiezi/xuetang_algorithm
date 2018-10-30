#include <iostream>
using namespace std;

void selection_sort(int* arr, int length) {
  int i, j, tmp;
  for (i = 0; i < length; i++) {
    int min = i;
    for (j = i+1; j < length; j++) {
      if (arr[j] < arr[min]) {
        min = j;
      }
    }
    // 交换
    tmp = arr[min];
    arr[min] = arr[i];
    arr[i] = tmp;
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

  // 选择排序
  selection_sort(arr, n);

  for(i = 0; i < n; i++){
    printf("%d ", arr[i]);
  }
  printf("\n");

  free(arr);
  return 0;
}