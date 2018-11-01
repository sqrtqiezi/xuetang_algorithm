#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

const int N = 505*2, M= N * N;
struct E {
  //next:下一条邻接边
  //to：本条边所指向的终点
  int next,to;
} e[M];

//ihead:邻接表的头
//cnt：邻接表大小 
//mc：表示每个点所匹配到的另一个点match
//vis：Y集元素是否被访问过
int cnt,ihead[N],mc[N];
bool vis[N];

//邻接表连边，表示连一条x到y的有向边
//x：起点
//y：终点
void add(int x,int y){
  ++cnt;
  e[cnt].next = ihead[x];
  e[cnt].to = y;
  ihead[x] = cnt;
}

//匈牙利算法
//x：x集上的点，从当前点出发找增广路
//返回值：若找到增广路则返回true，否则返回false
bool dfs(int x){
  for(int i=ihead[x]; i!=0; i=e[i].next){
    int y = e[i].to;
    if (!vis[y]) { //如果找到一个Y集上的点没有标记
      vis[y] = true;//标记该点
      //如果y是没有匹配点的，说明找到了一条增广路；或者说递归查找y的匹配点，得到了一条增广路
      if (mc[y] == 0 || dfs(mc[y])) {
        //找到了增广路，更新mc数组
        mc[x] = y;
        mc[y] = x;
        return true;
      }
    }
  }
  return false;
}

// 求解棋盘上最多能放多少个“车”
// n：棋盘的大小为n×n的
// board：所给棋盘，对于某个位置上的数：若值为1表示可以放“车”；若值为0表示不能放“车”
// 返回值：能放“车”的最大个数
int getAnswer(int n, vector<vector<int> > board) {
  //将行看作n个点，将列看作另外n个点，标号分别是1到n和n+1到2n
  cnt = 0;
  for (int i=1; i <= n * 2; ++i) {
    ihead[i] = 0;
    mc[i] = 0;
  }
  //连边
  for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= n; ++j)
      if(board[i-1][j-1] == 1)
        add(i,j+n);
  int ans = 0;
  for(int i=1; i<=n; ++i)
    if(!mc[i]){
      //如果x集中的第i个点没有匹配到Y集上的点，则从这个点出发寻找增广路
      memset(vis, 0, sizeof(bool) * (n * 2 + 1));
      //将数组置为0
      if(dfs(i))
        ++ans;//如果找到，答案直接+1
    }
  return ans;
}

int main() {
  int n;
  scanf("%d", &n);
  vector<vector<int> > e;
  for (int i = 0; i < n; ++i) {
    vector<int> t;
    for (int j = 0; j < n; ++j) {
      int x;
      scanf("%d", &x);
      t.push_back(x);
    }
    e.push_back(t);
  }
  printf("%d\n", getAnswer(n, e));
  return 0;
}