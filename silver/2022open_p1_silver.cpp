#include <bits/stdc++.h>
using namespace std;

vector<int> a,v;
vector<vector<int>> adjRev;
vector<bool> visited;

void mv(int cur){
  if (visited[cur]){
    return;
  }

  visited[cur] = true;
  for (int next : adjRev[cur]){
    mv(next);
  }
}

int minCycle(int start){
  int s = a[start];
  int f = a[s];

  while (s != f){
    s = a[s];
    f = a[a[f]];
  }

  int minEl = v[s];
  s = a[s];

  while (s != f){
    // iterate through cycle
    minEl = min(minEl, v[s]);
    s = a[s];
  }

  // mark as visited
  mv(s);

  return minEl;
}

int main(){
  int n;
  cin >> n;

  adjRev.resize(n);
  a.resize(n);
  v.resize(n);
  visited.resize(n);

  long long ans = 0;
  for (int i = 0; i < n; i++){
    cin >> a[i] >> v[i];
    a[i]--;

    adjRev[a[i]].push_back(i);
    ans += v[i]; // start with all cows mooing, then remove the ones that can't
  }

  for (int i = 0; i < n; i++){
    if (!visited[i]){
      ans -= minCycle(i);
    }
  }

  cout << ans << '\n';
}
