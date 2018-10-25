#include <bits/stdc++.h>
using namespace std;

typedef long long Type;
typedef priority_queue<Type, vector<Type>, greater<Type> > Container;

Type recode(Container& pq) {
  Type sum = 0;
  while(pq.size() > 1)
  {
    Type tmp = 0;
    for(int k = 0; k < 2; k++) 
    {
      tmp += pq.top();
      pq.pop();
    }
    sum += tmp;
    pq.push(tmp);
  }
  return sum;
}

int main() {
  int n;
  Type w;
  Container pq;

  cin >> n;
  while (n-- > 0)
  {
    cin >> w;
    pq.push(w);
  }
  cout << recode(pq) << endl;
  return 0;
}