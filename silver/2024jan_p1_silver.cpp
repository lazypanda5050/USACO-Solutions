#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n,q,c;
  cin >> n >> q >> c;

  vector<int> scores(n);

  for (int& x : scores) {
    cin >> x;
  }

  vector<int> h(q);
  vector<int> states(n);

  for (int i = 0; i < q; ++i) {
    int a = 0;
    cin >> a >> h[i];
    a--;
    h[i]--;
    states[a+1]++;
    states[h[i]]--;
  }

  partial_sum(begin(states), end(states), begin(states));

  for (int& x : states) {
    x = x ? 1 : 0;
  }

  bool is_val = true;

  for (int x : h) {
    is_val &= exchange(states[x], 2) != 1;
  }

  int pfx_mx = 0;
  int ptr = -1;

  for (int i = 0; i < n && is_val; ++i) {
    if (states[i] == 1) {
      if (scores[i] == 0) {
        scores[i] = 1;
      } else if (scores[i] > pfx_mx && ptr != -1) {
        scores[ptr] = scores[i];
      }
    } else if (scores[i] == 0) {
      scores[i] = states[i] == 0 ? 1 : pfx_mx + 1;
      ptr = i;
    }
    pfx_mx = max(pfx_mx, scores[i]);
  }

  is_val &= pfx_mx <= c;

  pfx_mx = 0;

  for (int i = 0; i < n && is_val; ++i) {
    if (states[i] == 1) {
      is_val &= scores[i] <= pfx_mx;
    } else if (states[i] == 2) {
      is_val &= scores[i] > pfx_mx;
    }
    pfx_mx = max(pfx_mx, scores[i]);
  }

  if (!is_val) {
    cout << -1 << '\n';
    return;
  }

  for (int i = 0; i < n; ++i) {
    cout << scores[i] << (i < n - 1 ? ' ' : '\n');
  }

}

int main() {
  int T;
  cin >> T;
  while (T--){
    solve();
  }

  return 0;

}
