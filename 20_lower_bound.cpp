#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

// ================= 代码实现开始 =================

vector<int> ans;

// 本函数传入数组 a 及所有询问，你需要求解所有询问并一并返回
// n：序列 a 的长度
// a：存储了序列 a
// Q：询问个数
// query：依次存储了所有询问的参数 x
// 返回值：一个 vector<int>，依次存放各询问的答案
void getAnswer(int n, vector<int>& a, int Q, vector<int>& query) {
  ans.clear();//清空ans
  sort(a.begin(),a.end());//由于要进行二分查找，需要保证a有序，因此将a排序
  for(int i = 0; i < Q; ++i){
    int key = query[i];//key为本次询问的x
    //进行二分查找
    int l = -1,r = n,mid;
    while(l+1 < r){
      mid = (l+r)>>1;
      if(a[mid] < key)
        l = mid;
      else
        r = mid;
    }
    int pos = r;
    if(pos >= n)
      ans.push_back(-1);
    else
      ans.push_back(a[pos]);
  }
}

// ================= 代码实现结束 =================

int main() {
  int n, Q, tmp;
  vector<int> a, query;
  a.clear();
  query.clear();
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &tmp);
    a.push_back(tmp);
  }
  scanf("%d", &Q);
  for (int i = 0; i < Q; ++i) {
      scanf("%d", &tmp);
      query.push_back(tmp);
  }
  getAnswer(n, a, Q, query);
  for (int i = 0; i < Q; ++i)
      printf("%d\n", ans[i]);
  return 0;
}
