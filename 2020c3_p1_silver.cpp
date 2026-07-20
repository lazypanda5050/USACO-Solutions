#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
int n,m,k;
int adj[MAXN];
bool visited[MAXN];
vector<int> cycle;
int ans[MAXN];

void dfs(int node){
  if (visited[node]){
    return;
  }

  visited[node] = true;
  cycle.push_back(node);
  dfs(adj[node]);
}

int main(){
  freopen("swap.in", "r", stdin);
  freopen("swap.out","w", stdout);
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++){
    adj[i] = i;
  }
  for (int i = 1; i <= m; i++){
    int l,r;
    cin >> l >> r;
    reverse(adj+l,adj+r+1);
  }
  for (int i = 1; i <= n; i++){
    if (visited[i]){
      continue;
    }

    cycle.clear();
    dfs(i);
    int len = cycle.size();
    int shift = k % len;
    for (int j = 0; j < len; j++){
      ans[cycle[j]] = cycle[(j+shift)%len];
    }
  }
  for (int i = 1; i <= n; i++){
    cout << ans[i] << '\n';
  }
}
