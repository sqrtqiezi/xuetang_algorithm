#include <iostream>
#include <tuple>
#include <vector>
#include <utility>
using namespace std;

// id、总分、算法训练营分数、数据结构分数
typedef tuple<int, int, int, int> Grade;
typedef vector<Grade* > Container;

// 冒泡排序算法，当需要 swap 时逆序对计数加一
int sort(Container& c) {
  int n = c.size();
  int count = 0;
  for (int i = 0; i < n-1; i++) {
    for (int j = 0; j < n-1-i; j++) {
      if (get<1>(*c[j+1]) > get<1>(*c[j]) || (get<1>(*c[j+1]) == get<1>(*c[j]) && get<2>(*c[j+1]) > get<2>(*c[j]))) {
        swap(c[j+1], c[j]);
        ++count;
      }
    }
  }
  return count;
}

int main() {
  int n, a, b;
  Grade* grade;
  
  cin >> n;
  Container c;
  c.reserve(n);

  for(int i = 1; i <= n; i++) {
    cin >> a >> b;
    Grade* grade = new Grade(i, a+b, a, b);
    c.push_back(grade);
  }
  int result = sort(c);
  for(int i = 0; i < c.size(); i++) {
    Grade* grade = c[i];
    cout << get<0>(*grade) << " " <<  get<1>(*grade) << " " <<  get<2>(*grade) << " " <<  get<3>(*grade) << endl;
  }
  cout << result << endl;
  return 0;
}
