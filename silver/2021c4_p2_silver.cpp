#include <bits/stdc++.h>
using namespace std;

vector<int> x;
set<multiset<int>> sols;

void check(int sum, int b, int c){
  int a = sum-b-c;
  set<int> s{0,a,b,c,a+b,b+c,c+a,a+b+c};
  for (int t : x){
    if (!s.count(t)){
      return;
    }
  }
  sols.insert({a,b,c});
}

void test(int sum){
  set<int> candidates;
  for (int t : x){
    if (t > sum){
      return;
    }
    if (t == 0 || t == sum){
      continue;
    }
    candidates.insert(min(t,sum-t));
  }

  int a = *candidates.begin();
  int b = *next(candidates.begin());
  check(sum,a,b);
  check(sum,a,sum-b);
}

int main(){
  int T;
  cin >> T;
  while (T--){
    int n;
    cin >> n;
    x.resize(n);
    sols.clear();

    for (int i = 0; i < n; i++){
      cin >> x[i];
    }
    x.push_back(0);

    for (int i = 0; i < n+1; i++){
      for (int j = i+1; j < n+1; j++){
        test(x[i]+x[j]);
      }
    }

    cout << sols.size() << '\n';
  }
}
