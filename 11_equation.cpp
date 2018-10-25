#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

const int N = 500000;
int Father[N], Rank[N];
int A[N], B[N];

int find(int x) {
  return Father[x] == x ? x : find(Father[x]);
}

bool solve(int n, int m) {
  int a, b, e, cnt = 0;

  for (int i = 1; i <= n; i++) {
    Father[i] = i;
    Rank[i] = 0;
  }

  while(m--) {
    cin >> a >> b >> e;
    if (e == 0) {
      A[cnt] = a;
      B[cnt] = b;
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
  cin >> t; 
  while (t--) {
    cin >> n >> m;
    if (solve(n, m)) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
}