#include <bits/stdc++.h>
using namespace std;

int main(){
  freopen("mootube.in", "r", stdin);
  freopen("mootube.out", "w", stdout);
  int n,q;
  cin >> n >> q;

  vector<vector<pair<int, int>>> adj(n);
  for (int i = 0; i < n-1; i++){
    int a,b,r;
    cin >> a >> b >> r;
      a--,b--;
    adj[a].push_back({b,r});
    adj[b].push_back({a,r});
  }

  for (int i = 0; i < q; i++){
    int k,v;
    cin >> k >> v;
    v--;
    queue<int> q;
    unordered_set<int> visited;
    int seen = 0;
    q.push(v);
    visited.insert(v);
    while (!q.empty()){
      int cur = q.front(); q.pop();

      for (auto& [next, length] : adj[cur]){
        if (visited.find(next) == visited.end() && length >= k){
          // valid
          seen++;
          q.push(next);
          visited.insert(next);
        }
      }
    }

    cout << seen << '\n';
  }
}
