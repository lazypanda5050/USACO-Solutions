#include <bits/stdc++.h>
using namespace std;

int main(){
  freopen("teleport.in", "r", stdin);
  freopen("teleport.out", "w", stdout);
  int n;
  cin >> n;
  vector<pair<int, int>> a(n+1);
  map<int, long long> slope;

  slope[0] = 0;

  long long total = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first >> a[i].second;
    if (slope.find(a[i].first) == slope.end()) {
      slope[a[i].first] = 0;
    }
    if (slope.find(a[i].second) == slope.end()) {
      slope[a[i].second] = 0;
    }
    int dist = abs(a[i].first - a[i].second);
    total += dist;
    int dist2 = abs(a[i].first);
    if (dist2 < dist) {
      slope[a[i].second - (dist - dist2) + 1]--;
      slope[a[i].second + 1] += 2;
      slope[a[i].second + (dist - dist2) + 1]--;
    }
  }
  long long ans = total;
  long long sumslopes = 0;
  long long delta = 0;
  int prv = -(1<<30);
  for (auto x : slope) {
    if (prv != -(1<<30)) {
      sumslopes += delta * (x.first - prv);
    }
    delta += x.second;
    prv = x.first;

    ans = min(ans, total + sumslopes);
  }

  cout << ans << '\n';
  return 0;
}
