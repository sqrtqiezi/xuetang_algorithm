#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int* arr;
  int n, i, k;

  scanf("%d", &n);
  arr = (int*)malloc(sizeof(int) * n);
  for(i = 0; i < n; i++) {
    scanf("%d", &k);
    arr[i] = k;
  }
  sort(arr, arr + n);
  for(i = 0; i < n; i++){
    printf("%d ", arr[i]);
  }
  printf("\n");

  free(arr);
  return 0;
}