#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int to;
  int cow;
  bool first;
};

int n, m;
vector<vector<Edge>> adj;
vector<bool> visitedCereal;
vector<bool> visitedCow;

int ans = 0;
vector<int> order;

int findCycle(int u, int p_cow) {
  visitedCereal[u] = true;
  for (auto& edge : adj[u]) {
    if (edge.cow == p_cow) continue;
    if (visitedCereal[edge.to]) {
      return edge.cow;
    }
    int res = findCycle(edge.to, edge.cow);
    if (res != -1) return res;
  }
  return -1;
}

void dfs(int u) {
  visitedCereal[u] = true;
  for (auto& edge : adj[u]) {
    if (!visitedCow[edge.cow]) {
      visitedCow[edge.cow] = true;
      order.push_back(edge.cow);
      dfs(edge.to);
    }
  }
}

int main() {
  cin >> n >> m;
  adj.resize(m + 1);

  vector<pair<int, int>> choices(n + 1);
  for (int i = 1; i <= n; i++) {
    int a, b;
    cin >> a >> b;
    choices[i] = {a, b};
    adj[a].push_back({b, i, true});
    adj[b].push_back({a, i, false});
  }

  visitedCereal.assign(m + 1, false);
  visitedCow.assign(n + 1, false);

  for (int i = 1; i <= m; i++) {
    if (!visitedCereal[i] && !adj[i].empty()) {
      int start = findCycle(i, -1);

      if (start != -1) {
        visitedCow[start] = true;
        order.push_back(start);
      }
    }
  }

  visitedCereal.assign(m + 1, false);

  for (int i = 1; i <= n; i++) {
    if (visitedCow[i]) {
      dfs(choices[i].first);
      dfs(choices[i].second);
    }
  }

  for (int i = 1; i <= m; i++) {
    if (!visitedCereal[i]) {
      dfs(i);
    }
  }

  for (int i = 1; i <= n; i++) {
    if (!visitedCow[i]) {
      ans++;
      order.push_back(i);
    }
  }

  cout << ans << '\n';
  for (int cow : order) {
    cout << cow << '\n';
  }

  return 0;
}
