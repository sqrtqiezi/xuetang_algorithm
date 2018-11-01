#include <queue>
#include <vector>
#include <cstdio>
using namespace std;

typedef priority_queue<int, vector<int>, greater<int> > BigHeap;
typedef priority_queue<int, vector<int>, less<int> > SmallHeap;

BigHeap bigHeap;
SmallHeap smallHeap;

//返回值：当前序列中位数的值
int getMedian() {
	if (bigHeap.size() < smallHeap.size()) {
    return smallHeap.top();
  } else {
    return bigHeap.top();
  }
}

// 向当前数列末尾插入一个数x
void add(int x) {
  if (bigHeap.size() == 0 && smallHeap.size() == 0) {
    bigHeap.push(x);
  } else if (x > getMedian()) {
    bigHeap.push(x);
    if (bigHeap.size() > smallHeap.size() + 1) {
      smallHeap.push(bigHeap.top());
      bigHeap.pop();
    }
  } else {
    smallHeap.push(x);
    if (smallHeap.size() > bigHeap.size() + 1) {
      bigHeap.push(smallHeap.top());
      smallHeap.pop();
    }
  }
}

/* ==================== 代码实现结束 ================== */

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= 2 * n - 1; i++) {
		int a;
		scanf("%d", &a);
		add(a);
		if (i & 1)
			printf("%d\n", getMedian());
	}

	return 0;
}
