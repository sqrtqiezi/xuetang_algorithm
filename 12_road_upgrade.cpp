#include <vector>
using namespace std;

vector<int> Father, Rank, U, V, ans;

int find(int x) {
  while(Father[x] != x) {
    x = Father[x];
  }
  return x;
}

void solve(int n, int m) {
  Father.resize(n+1);
  Rank.resize(n+1);
  for(int i = 1; i <= n; i++) {
    Father[i] = i;
    Rank[i] = 0;
  }
  
  int u,v;
  U.resize(m+1);
  V.resize(m+1);
  for(int i = 1; i <= m; i++) {
    scanf("%d%d", &u, &v);
    U[i] = u;
    V[i] = v;
  }

  int cnt = 0;
  ans.resize(n-1); // 答案可以确定为最小生成树，因此长度为 n-1
  for(int i = m; i >= 1; i--) {
    int setU = find(U[i]);
    int setV = find(V[i]);
    if(setU != setV) {
      if (Rank[setU] > Rank[setV]) {
        swap(setU, setV);
      }
      Father[setU] = setV;
      if (Rank[setU] == Rank[setV]) {
        Rank[setV]++;
      }
      ans[cnt++] = i;
    }
  }

  printf("%d\n", cnt);
  for(int i = cnt-1; i >= 0; i--) {
    printf("%d\n", ans[i]);
  }
}

int main() {
  int m, n;
  scanf("%d%d", &n, &m);
  solve(n, m);
  return 0;
}