#include <bits/stdc++.h>
using namespace std;

int main(){
  freopen("sort.in", "r", stdin);
  freopen("sort.out", "w", stdout);
  int n;
  cin >> n;

  vector<pair<int, int>> a(n); // index, value
  for (int i = 0; i < n; i++){
    a[i].first = i;
    cin >> a[i].second;
  }
  
  sort(a.begin(), a.end(), [](pair<int, int> x, pair<int, int> y){
    return x.second < y.second || (x.second == y.second && x.first < y.first);
  });

  int ans = 0;
  for (int i = 0; i < n; i++){
    ans = max(ans, a[i].first-i);
  }

  cout << ans+1 << '\n';
}
