#include <iostream>
using namespace std;

int min(int x, int y) {
  return x < y ? x : y;
}

// TODO: 有bug 。。。。。。。。
void merge_sort(int* arr, int length) {
  int* a = arr;
  int* b = (int*)malloc(length * sizeof(int));
  int seg, start;

  for (seg = 1; seg < length; seg += seg) {
    for (start = 0; start < length; start += seg + seg) {
      int low = start, 
        mid = min(start + seg, length), 
        high = min(start + seg + seg, length);
      int k = low;
      int start1 = low, end1 = mid;
      int start2 = mid, end2 = high;

      while (start1 < end1 && start2 < end2) {
        b[k++] = a[start1] <= a[start2] ? a[start1++] : a[start2++];
      }

      while (start1 < end1) {
        b[k++] = a[start1++];
      }

      while (start2 < end2) {
        b[k++] = a[start2++];
      }
    }

    int* temp = a;
    a = b;
    b = temp;
  }

  if (a != arr) {
    for (int i = 0; i < length; i++) {
      b[i] = a[i];
      b = a;
    }
  }
  free(b);
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

  // 归并排序
  merge_sort(arr, n);

  for(i = 0; i < n; i++){
    printf("%d ", arr[i]);
  }
  printf("\n");

  free(arr);
  return 0;
}