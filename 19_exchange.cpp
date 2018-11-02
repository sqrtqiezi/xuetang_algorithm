#include <vector>
#include <cstdio>
using namespace std;

// ================= 代码实现开始 =================

//seq:原序列，为了方便处理，将其设为全局变量
//seqTemp：用以辅助计算的临时数组
//cnt：统计逆序对个数
vector<int> seq,seqTemp;
long long cnt;
//归并排序
//l，r分别为归并排序排序区间的左右端点
void mergeSort(int l, int r) {
  if(l==r)
    return;
  int mid = (l + r)>>1;
  mergeSort(l, mid);//递归，排序mid以左的部分
  mergeSort(mid + 1, r);//递归，排序mid以右的部分
  int p = l,q = mid + 1;//用两个指针来指向归并时需要比较的两个元素
  for(int i = l; i <= r; ++i){
    if(q>r || (p <= mid && seq[p] <= seq[q]))//判断哪个元素更小
      seqTemp[i] = seq[p++];//如果左边的元素更小，则将右边的元素插入末尾
    else {
      seqTemp[i] = seq[q++];//如果右边的元素更小，则将左边的元素插入末尾
      cnt += mid - p + 1;//并统计产生的逆序对数目
    }
  }
  for(int i = l; i <= r; ++i)
    seq[i] = seqTemp[i];//将排序后的序列复制回原序列的对应位置
}

// 这个函数的功能是计算答案（即最少花费的金钱）
// n：表示序列长度
// a：存储整个序列 a
// 返回值：最少花费的金钱（需要注意，返回值的类型为 64 位有符号整数）
long long getAnswer(int n, vector<int> a) {
  seq = a;//复制序列到全局变量
  seqTemp.resize(n);//初始化临时数组的长度
  cnt = 0;//置零计数量
  mergeSort(0, n-1);//进行归并排序
  return cnt;//返回答案
}

// ================= 代码实现结束 =================

int main() {
  int n, tmp;
  vector<int> a;
  a.clear();
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &tmp);
    a.push_back(tmp);
  }
  long long ans = getAnswer(n, a);
  printf("%lld\n", ans);
  return 0;
}
