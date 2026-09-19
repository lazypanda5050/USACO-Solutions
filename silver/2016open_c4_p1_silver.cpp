#include <bits/stdc++.h>
using namespace std;

signed main() {
  freopen("reduce.in", "r", stdin);
  freopen("reduce.out", "w", stdout);

  long long n;
  cin >> n;

  vector<pair<long long, long long>> cows(n);
  vector<pair<long long, long long>> x(n), y(n);

  for (long long i = 0; i < n; i++) {
    cin >> cows[i].first >> cows[i].second;
    x[i] = {cows[i].first, i};
    y[i] = {cows[i].second, i};
  }

  sort(x.begin(), x.end());
  sort(y.begin(), y.end());

  vector<long long> candidates;
  for (long long i = 0; i < 4; i++) {
    candidates.push_back(x[i].second);
    candidates.push_back(x[n - 1 - i].second);
    candidates.push_back(y[i].second);
    candidates.push_back(y[n - 1 - i].second);
  }

  sort(candidates.begin(), candidates.end());
  candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());

  long long k = candidates.size();
  long long ans = LLONG_MAX;

  for (long long i = 0; i < k; i++) {
    for (long long j = i + 1; j < k; j++) {
      for (long long l = j + 1; l < k; l++) {
        long long r1 = candidates[i], r2 = candidates[j], r3 = candidates[l];

        long long minX = 0, maxX = 0, minY = 0, maxY = 0;

        for (long long p = 0; p < n; p++) {
          if (x[p].second != r1 && x[p].second != r2 && x[p].second != r3) {
            minX = x[p].first;
            break;
          }
        }
        for (long long p = n - 1; p >= 0; p--) {
          if (x[p].second != r1 && x[p].second != r2 && x[p].second != r3) {
            maxX = x[p].first;
            break;
          }
        }
        for (long long p = 0; p < n; p++) {
          if (y[p].second != r1 && y[p].second != r2 && y[p].second != r3) {
            minY = y[p].first;
            break;
          }
        }
        for (long long p = n - 1; p >= 0; p--) {
          if (y[p].second != r1 && y[p].second != r2 && y[p].second != r3) {
            maxY = y[p].first;
            break;
          }
        }

        ans = min(ans, (maxX - minX) * (maxY - minY));
      }
    }
  }

  cout << ans << '\n';
  return 0;
}
