#include <queue>
#include <cstdio>
#include <vector>
#include <math.h>

using namespace std;

typedef long long Type;
typedef vector<Type> Container;
typedef priority_queue<Type, vector<Type>, greater<Type> > PQ;

// =================== 代码实现开始 ========================

// n: 初始点数
// k: 哈夫曼树的叉树
// w: w[i] 表示第i个点的点权
//返回值：最终编码的长度
Type solve(PQ& w, int n, int k)
{
	Type sum = 0;
  int r = 0;
  int rest = n % (k-1);

  if (rest != 1 && k > 2) {
    if (rest == 0) {
      r = 1;
    } else {
      r = k - rest;
    }
  }

  for (int i = 0; i < r; i++) {
    w.push(0);
  }

  while(w.size() > k - 1) {
    Type tmp = 0;
    for(int i = 0; i < k; i++) {
      tmp += w.top();
      w.pop();
    }
    sum += tmp;
    w.push(tmp);
  }
  return sum;
}

// ================== 代码实现结束 ======================

int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
  Container container;
  container.reserve(n + k);

	PQ w(greater<Type>(), move(container));
	for (int i = 0; i < n; i++) {
		Type a;
		scanf("%lld", &a);
		w.push(a);
	}

	printf("%lld\n", solve(w, n, k));
	return 0;
}
