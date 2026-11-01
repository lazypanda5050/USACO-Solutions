#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;

  while (T--) {
    int N;
    cin >> N;

    vector<long long> A(N), pfx(N + 1, 0);
    for (int i = 0; i < N; i++) {
      cin >> A[i];
      pfx[i + 1] = pfx[i] + A[i];
    }

    long long ans = LLONG_MAX;
    int k = N / 2;

    for (int i = 0; i < N - k; i++) {
      long long val = pfx[i + k + 1] - pfx[i];
      ans = min(ans, val);
    }

    long long total = pfx[N];
    cout << ans << " " << (total - ans) << "\n";
  }

  return 0;
}
