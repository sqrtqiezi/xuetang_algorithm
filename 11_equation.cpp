#include <iostream>
#include <vector>
using namespace std;

vector<int> Father, Rank, A, B;

inline int find(int x) {
  while(Father[x] != x) {
    x = Father[x];
  }
  return x;
}

bool solve(int n, int m) {
  int a, b, e, cnt = 0;

  Father.resize(n+1);
  Rank.resize(n+1);
  for (int i = 1; i <= n; i++) {
    Father[i] = i;
    Rank[i] = 0;
  }

  A.resize(0);
  B.resize(0);
  while(m--) {
    scanf("%d%d%d", &a, &b, &e);
    if (e == 0) {
      A.push_back(a);
      B.push_back(b);
      cnt++;
    } else {
      int setA = find(a);
      int setB = find(b);
      if(setA != setB) {
        if (Rank[setA] > Rank[setB]) {
          swap(setA, setB);
        }
        Father[setA] = setB;
        if (Rank[setA] == Rank[setB]) {
          Rank[setB]++;
        }
      }
    }
  }

  for(int i = 0; i < cnt; i++) {
    if (find(A[i]) == find(B[i])) {
      return false;
    }
  }

  return true;
}

int main() {
  int t, n, m;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &m);
    if (solve(n, m)) {
      printf("Yes\n");
    } else {
      printf("No\n");
    }
  }
}