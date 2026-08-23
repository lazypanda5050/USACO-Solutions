#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define f first
#define s second
#define pb push_back

int32_t main() {
  int t;
  cin >> t;

  while (t--) {
    int n, tc, tm;
    cin >> n >> tc >> tm;

    vector<int> a(n), b(n), c(n);

    for (int i = 0; i < n; i++) {
      cin >> a[i] >> b[i] >> c[i];
    }

    vector<int> need(n);
    for (int i = 0; i < n; i++) {
      need[i] = max(0ll, (a[i] * tc) + (b[i] * tm) - c[i]);
    }

    function<bool(int)> check = [&](int mid) {
      // x + y <= mid
      // a[i] * x + b[i] * y >= need[i]
      // x < tc
      // y < tm

      int mnx = 0, mny = 0;

      for (int i = 0; i < n; i++) {
        if (a[i] > b[i]) {
          mnx = max(mnx, (((need[i] - (mid * b[i])) + (a[i] - b[i] - 1)) / (a[i] - b[i])));
        } else if (a[i] < b[i]) {
          mny = max(mny, (((need[i] - (mid * a[i])) + (b[i] - a[i] - 1)) / (b[i] - a[i])));
        } else {
          if (a[i] * mid < need[i]) {
            return false;
          }
        }
      }

      if (mnx >= tc || mny >= tm) {
        return false;
      }

      if (mnx + mny > mid) {
        return false;
      }

      return true;
    };

    int lo = 0, hi = 2e9 + 69, ind = -1;
    while (lo <= hi) {
      int mid = (lo + hi) / 2;
      if (check(mid)) {
        ind = mid;
        hi = mid - 1;
      } else lo = mid + 1;
    }
    cout << ind << '\n';
  }
}
