#include <iostream>
using namespace std;

void insertion_sort(int* arr, int length) {
  int i, j, key;
  for (i = 1; i < length; i++) {
    key = arr[i];
    j = i - 1;
    while(j >= 0 && arr[j] > key) {
      arr[j+1] = arr[j];
      j--;
      arr[j+1] = key;
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

  // 插入排序
  insertion_sort(arr, n);

  for(i = 0; i < n; i++){
    printf("%d ", arr[i]);
  }
  printf("\n");

  free(arr);
  return 0;
}