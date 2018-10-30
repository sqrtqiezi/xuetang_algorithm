/**
 *  堆的定义：https://zh.wikipedia.org/wiki/%E5%A0%86%E7%A9%8D
 *  堆排序：https://zh.wikipedia.org/wiki/%E5%A0%86%E6%8E%92%E5%BA%8F
 **/
#include <iostream>
using namespace std;

inline void swap(int* a, int* b) {
  int tmp = *b;
  *b = *a;
  *a = tmp;
}

// 使删除堆顶元素的堆再次成为堆
void max_heapify(int* arr, int start, int end) {
  // 建立父节点下标和子节点下标
  int dad = start;
  int son = dad * 2 + 1;
  while (son <= end) {
    // 先比较两个子节点大小，选择最大的
    if (son + 1 <= end && arr[son] < arr[son + 1]) {
      son++;
    } 
    if (arr[dad] > arr[son]) { // 如果父节点大于子节点，代表调整完毕，直接跳出函数
      return;
    } else { // 否则，交互父子节点内容，再继续子节点和孙节点的比较
      swap(&arr[dad], &arr[son]);
      dad = son;
      son = dad * 2 + 1;
    }
  }
}

//TODO: 当重复值较多的时候，有bug。没有处理好边界情况
void heap_sort(int* arr, int length) {
  int i;
  // 调整，i 从最后一个父节点开始
  for (i = length/2 -1; i >= 0; i--) {
    max_heapify(arr, i, length - i);
  }

  // 先将第一个元素和已排好元素的前一位做交互，再重新调整，直到排序完毕
  for (i = length - 1; i > 0; i--) {
    swap(&arr[0], &arr[i]);
    max_heapify(arr, 0, i - 1);
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

  // 堆排序
  heap_sort(arr, n);

  for(i = 0; i < n; i++){
    printf("%d ", arr[i]);
  }
  printf("\n");

  free(arr);
  return 0;
}