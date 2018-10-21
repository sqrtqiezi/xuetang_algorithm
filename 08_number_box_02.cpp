#include <iostream>
#include <vector>
#include <set>
#include <stdio.h>
#define mod 1000003
typedef long long ll;
using namespace std;

vector<ll> ht[mod];
inline int MOD(ll x){
  return x%mod;
}

bool func(int op, ll x){
  ll hashnum = MOD(x);
  //通过ptr是否在end()判断x是否存在与vector
  vector<ll>::iterator ptr = ht[hashnum].end();
  for(vector<ll>::iterator it = ht[hashnum].begin();it!=ht[hashnum].end();++it) {
    if(*(it) == x){
      ptr = it;
      break;
    }
  }
    
  if(op == 1){
    //插入操作
    if(ptr == ht[hashnum].end()){
      ht[hashnum].push_back(x);
      return true;
    }
    else return false;
  }
  else{
    //删除操作 把最后一个数覆盖ptr位置，删除最后一个数(pop_back())
    if(ptr == ht[hashnum].end()) {
      return false;
    } else {
      *(ptr) = ht[hashnum].back();
      ht[hashnum].pop_back();
      return true;
    }
  }
}

int main() {
  int N,op;
  ll x;
  cin>>N;
  while(N--){
    scanf("%d %lld",&op,&x);
    if(func(op,x)) {
      printf("Succeeded\n");
    } else {
      printf("Failed\n");
    }
  }
  return 0;
}