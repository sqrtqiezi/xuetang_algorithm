#include <iostream>
#include <vector>
using namespace std;

const int N = 300005;
//max_value:用于存储solve函数中的前缀最大值
//min_value:用于存储solve函数中的前缀最小值
int n, d, max_value[N], min_value[N];
vector<int> a;
//分治计算区间[l,r]中有多少个连续子序列满足最大值最小值之差不小于d
//l:区间左边界
//r：区间右边界
//返回值：满足条件的连续子序列的个数
long long solve(int l,int r){
  if(l==r) return 0;
  int mid = (l+r)>>1;//中点
  long long ans = solve(l,mid)+solve(mid+1,r);//分治求出左右两半的值
  //我们计算区间[mid+1,r]的前缀最小值，也就是说min_value = mid(a[mid+1...i]),max_value同理

  for(int i = mid+1; i<=r; ++i){
    min_value[i] = (i == mid+1)?a[i]:min(min_value[i-1],a[i]);
    max_value[i] = (i == mid+1)?a[i]:max(max_value[i-1],a[i]);
  }

  //我们倒序枚举子序列的左端点i，i的取值范围在[1,mid]
  //pos表示若连续子序列的左端点是i，那么子序列的右端点最远能拓展到pos位置，当然pos取值范围在[mid+1,r],一开始初始化为r
  //mn是后缀最小值，mx是后缀最大值，那也就是说mn=min(a[i...mid]),mx同理
  //那么以i为左端点的连续子序列（右端点在[mid+1,r]内）个数应该优pos-mid个
  int mn = 0,mx = 0, pos = r;
  for(int i=mid; i>=l && pos > mid; --i){
    //更新mn和mx
    mn = (i==mid)?a[i]:min(mn,a[i]);
    mx = (i==mid)?a[i]:max(mx,a[i]);
    for(; pos>mid && max(mx, max_value[pos])-min(mn, min_value[pos]) > d; --pos);
    ans += pos - mid;//更新答案
  }
  return ans;
}

// 求出有多少个a数组中的连续子序列（长度大于1），满足该子序列的最大值最小值之差不大于d
// n：a数组的长度
// d：所给d
// a：数组a，长度为n
// 返回值：满足条件的连续子序列的个数
long long getAnswer() {
 return solve(0,n-1);
}

int main()
{
  scanf("%d%d", &n, &d);
  a.resize(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &a[i]);
  printf("%lld\n", getAnswer());

  return 0;
}

