#include <vector>
#include <queue>
#include <utility>
#include <memory.h>
#include <cstdio>
using namespace std;

// ================= 代码实现开始 =================

const int N = 100005;
typedef pair<int,int> pii;
//graph:存放图，graph[i]表示的是节点i的出边，其中first存储到达的节点，second存储边权
//pq：辅助Dijkstra算法的优先队列
//flag：记录每个节点是否进行过松弛，1表示进行过，0表示未进行过
//mind：存储起点s到每个节点的最短路径长度
vector<pii> graph[N];
priority_queue<pii,vector<pii>,greater<pii> > pq;
bool flag[N];
int mind[N];

// 这个函数用于计算答案（最短路）
// n：节点数目
// m：双向边数目
// U,V,W：分别存放各边的两端点、边权
// s,t：分别表示起点、重点
// 返回值：答案（即从 s 到 t 的最短路径长度）
int shortestPath(int n, int m, vector<int>& U, vector<int>& V, vector<int>& W, int s, int t) {
  while(!pq.empty())
    pq.pop();
  for(int i=1; i<=n; ++i)
    graph[i].clear();
  memset(mind,127,sizeof(mind));
  memset(flag,0,sizeof(flag));
  //建图，连接图中各边
  for(int i=0; i<m; ++i) {
    graph[U[i]].push_back(make_pair(V[i],W[i]));
    graph[V[i]].push_back(make_pair(U[i],W[i]));
  }
  //设置起点的最短路为0，并将起点加入到优先队列中
  mind[s] = 0;
  pq.push(make_pair(mind[s],s));
  //执行Dijkstra算法
  while(!flag[t]){
    int u = pq.top().second;
    pq.pop();
    if(!flag[u]){//每个节点最多做一次松弛
      flag[u] = 1;
      for(vector<pii>::iterator it = graph[u].begin(); it != graph[u].end(); ++it){//枚举所有u出发的边
        int v = it->first, w = it->second;
        if(mind[v] <= mind[u]+w)
          continue;
        mind[v] = mind[u] + w;
        pq.push(make_pair(mind[v],v));//将v伴随其最新的最短路径长度加入优先队列
      }
    }
  }
  return mind[t];
}

// ================= 代码实现结束 =================

int main() {
int n, m, s, t;
scanf("%d%d%d%d", &n, &m, &s, &t);
vector<int> U, V, W;
U.clear();
V.clear();
W.clear();
for (int i = 0; i < m; ++i) {
int u, v, w;
scanf("%d%d%d", &u, &v, &w);
U.push_back(u);
V.push_back(v);
W.push_back(w);
}

printf("%d\n", shortestPath(n, m, U, V, W, s, t));
return 0;
}
