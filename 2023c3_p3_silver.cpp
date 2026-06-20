#include <bits/stdc++.h>
using namespace std;

struct Flight {
  int dep;
  int dest;
  int arrTime;

  bool operator<(const Flight& other) const {
    return dep < other.dep;
  }
};

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<Flight>> adj(n + 1);
  for (int i = 0; i < m; ++i) {
    int c,r,d,s;
    cin >> c >> r >> d >> s;
    adj[c].push_back({r,d,s});
  }

  vector<int> layover(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> layover[i];
  }
  layover[1] = 0; 

  for (int i = 1; i <= n; ++i) {
    sort(adj[i].begin(), adj[i].end());
  }

  vector<int> earliest(n + 1, INT_MAX);
  earliest[1] = 0;

  queue<pair<int, int>> q;
  q.push({1, 0});

  while (!q.empty()) {
    auto [curAir, arrTime] = q.front();
    q.pop();

    int minDep = arrTime + layover[curAir];

    while (!adj[curAir].empty() && adj[curAir].back().dep >= minDep) {
      Flight f = adj[curAir].back();
      adj[curAir].pop_back();

      if (f.arrTime < earliest[f.dest]) {
        earliest[f.dest] = f.arrTime;
        q.push({f.dest, f.arrTime});
      }
    }
  }

  for (int i = 1; i <= n; ++i) {
    if (earliest[i] == INT_MAX) {
      cout << -1 << "\n";
    } else {
      cout << earliest[i] << "\n";
    }
  }

  return 0;
}
