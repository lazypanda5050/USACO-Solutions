#include <bits/stdc++.h>
using namespace std;

int main(){
  freopen("mountains.in", "r", stdin);
  freopen("mountains.out", "w", stdout);
  int n;
  cin >> n;
  vector<int> x(n), y(n), pos(n), neg(n), ids(n);
  for (int i = 0; i < n; i++){
    cin >> x[i] >> y[i];
    pos[i] = x[i]+y[i];
    neg[i] = x[i]-y[i];
    ids[i] = i;
  }
  
  sort(ids.begin(), ids.end(), [&](int a, int b){
    if (neg[a] == neg[b]){
      return pos[a] > pos[b];
    }
    return neg[a] < neg[b];
  });

  int last = -1;
  int ans = 0;
  for (int i = 0; i < n; i++){
    if (pos[ids[i]] > last){
      ans++;
      last = pos[ids[i]];
    }
  }

  cout << ans << '\n';
}
