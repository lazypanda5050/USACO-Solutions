#include <bits/stdc++.h>
using namespace std;

int conv(char c){
  if (c <= 'Z'){
    return c -'A';
  }
  return 26 + (c - 'a');
}

int solve(){
  string s,t;
  cin >> s >> t;
  int n = s.size();

  if (s == t){
    return 0;
  }

  vector<int> adj(52,-1);
  vector<int> in_deg(52, 0);
  set<char> used;
  for (int i = 0; i < n; i++){
    int u = conv(s[i]);
    int v = conv(t[i]);
    used.insert(t[i]);
    if (adj[u] != -1 && adj[u] != v){
      return -1;
    }
    adj[u] = v;
  }

  if (used.size() == 52){
    return -1;
  }

  int ans = 0;
  for (int i = 0; i < 52; i++){
    if (adj[i] != -1 && adj[i] != i){
      ans++;
      in_deg[adj[i]]++;
    }
  }

  vector<int> visited(52,0);
  int cycles = 0;

  for (int i = 0; i < 52; i++){
    if (visited[i] == 0 && adj[i] != -1 && adj[i] != i){
      vector<int> path;
      int cur = i;

      while (cur != -1 && adj[cur] != cur && visited[cur] == 0){
        visited[cur] = 1;
        path.push_back(cur);
        cur = adj[cur];
      }

      if (cur != -1 && adj[cur] != cur && visited[cur] == 1){
        bool pure = true;
        int cycle_node = cur;
        do {
          if (in_deg[cycle_node] > 1) {
            pure = false;
            break;
          }
          cycle_node = adj[cycle_node];
        } while (cycle_node != cur);

        if (pure) {
          cycles++;
        }
      }

      for (int node : path){
        visited[node] = 2;
      }
    }
  }

  return ans + cycles;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T--){
    cout << solve() << '\n';
  }
}
