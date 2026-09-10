#include <bits/stdc++.h>
using namespace std;

int n,m;

int nodesVisited = 0;
vector<bool> visited;
vector<vector<int>> adj;
vector<bool> closed;

void dfs(int cur){
  if (visited[cur] || closed[cur]){
    return;
  }
  nodesVisited++;
  visited[cur] = true;

  for (int neighbor : adj[cur]){
    dfs(neighbor);
  }
}

int main(){
  freopen("closing.in", "r", stdin);
  freopen("closing.out", "w", stdout);
  cin >> n >> m;
  adj.resize(n);
  visited.resize(n);
  closed.resize(n);

  for (int i = 0; i < m; i++){
    int a,b;
    cin >> a >> b;
    a--, b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  vector<int> order(n);
  for (int i = 0; i < n; i++){
    cin >> order[i];
    order[i]--;
  }
  
  dfs(0);
  if (nodesVisited == n){
    cout << "YES\n";
  }
  else{
    cout << "NO\n";
  }

  for (int i = 0; i < n-1; i++){
    nodesVisited = 0;
    closed[order[i]] = true;
    fill(visited.begin(), visited.end(), false);

    // start from a node that is guarenteed to be open
    dfs(order[n-1]);

    if (nodesVisited == n-i-1){
      cout << "YES\n";
    }
    else{
      cout << "NO\n";
    }
  }
}
