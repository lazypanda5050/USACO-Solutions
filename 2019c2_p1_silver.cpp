#include <bits/stdc++.h>
using namespace std;

bool solvable(int g, const int maxDeg){
  // is it possible to g-color the graph
  if (g >= maxDeg+1){
    return true;
  }

  return false;
}

int main(){
  freopen("planting.in", "r", stdin);
  freopen("planting.out", "w", stdout);
  int n;
  cin >> n;
  vector<vector<int>> adj(n);
  vector<int> deg(n,0);
  for (int i = 0; i < n-1; i++){
    int a,b;
    cin >> a >> b;
    a--,b--;
    adj[a].emplace_back(b);
    adj[b].emplace_back(a);
    deg[a]++;
    deg[b]++;
  }
  int maxDeg = -1;
  for (int i = 0; i < n; i++){
    maxDeg = max(maxDeg, deg[i]);
  }

  for (int i = 1; i <= n; i++){
    if (solvable(i, maxDeg)){
      cout << i << '\n';
      return 0;
    }
  }
}
// 1 2 3 4
// 0 0 1 1
//
// 1 2 3 4 5 6
// 0 0 0 0 1 1
