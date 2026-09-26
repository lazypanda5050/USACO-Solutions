#include <bits/stdc++.h>
using namespace std;

vector<int> spawns;
vector<vector<int>> adj;
vector<int> ok;
vector<int> is;
vector<int> cntt;
vector<int> vx;
int ans = 0;
int n;
int leafs = 0;

void dfs(int p, int node){

  while (ok[node]){
    is[node]++;
    vx.push_back(node);
    ok[node]--;
  }

  bool leaf = true;
  for (int i = 0; i < adj[node].size(); i++){
    int nxt = adj[node][i];
    if (nxt == p){
      continue;
    }
    dfs(node, nxt);
    leaf = false;
  }

  if (leaf == 1 && !vx.empty()){
    is[vx.back()]--;
    vx.pop_back();
    ans++;
  }

  while (is[node]){
    is[vx.back()]--;
    vx.pop_back();
  }
}

signed main(){
  cin >> n;

  spawns.resize(n);
  adj.resize(n);
  ok.resize(n);
  is.resize(n);
  cntt.resize(n);
  for (int i = 0; i < n; i++){
    int a;
    cin >> a;
    a--;
    spawns[i] = a;
  }

  for (int i = 0; i < n-1; i++){
    int a,b;
    cin >> a >> b;
    a--;
    b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  for (int i = 1; i < n; i++){
    if (adj[i].size() == 1){
      leafs++;
    }
  }

  for (int i = 0; i < leafs; i++){
    ok[spawns[i]]++;
  }

  dfs(-1,0);
  cout << ans << '\n';
}
