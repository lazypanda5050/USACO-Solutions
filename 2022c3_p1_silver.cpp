#include <bits/stdc++.h>
using namespace std;

void dfs(const vector<vector<int>>& adj, vector<vector<bool>>& reachable, int start, int cur){
  if (reachable[start][cur]){
    return;
  }

  reachable[start][cur] = true;
  for (int neighbor : adj[cur]){
    dfs(adj, reachable, start, neighbor);
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  vector<vector<int>> gifts(n);
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      int a;
      cin >> a;
      a--;
      gifts[i].emplace_back(a);
    }
  }

  vector<vector<int>> adj(n);

  for (int i = 0; i < n; i++){
    for (int gift : gifts[i]) {
      adj[i].push_back(gift);
      if (gift == i) {
        break; 
      }
    }
  }

  vector<vector<bool>> reachable(n, vector<bool>(n, false));

  for (int i = 0; i < n; i++){
    dfs(adj, reachable, i, i);
  }

  for (int i = 0; i < n; i++){
    for (int gift : gifts[i]){
      if (reachable[gift][i]){
        cout << gift + 1 << '\n';
        break;
      }
    }
  }
}
