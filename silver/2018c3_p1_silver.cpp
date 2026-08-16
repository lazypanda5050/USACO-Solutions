#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("reststops.in", "r", stdin);
  freopen("reststops.out", "w", stdout);

  long long l, n, rf, rb;
  cin >> l >> n >> rf >> rb;
  vector<pair<long long, long long>> stops(n);
  vector<bool> isOptimal(n, false);

  for (long long i = 0; i < n; i++) {
    cin >> stops[i].first >> stops[i].second;
  }

  long long maximum = 0;
  for (long long i = n - 1; i >= 0; i--) {
    if (stops[i].second > maximum) {
      maximum = stops[i].second;
      isOptimal[i] = true;
    }
  }

  long long pos = 0;
  long long tastiness = 0;
  long long timeF = 0;
  long long timeB = 0;
  for (long long i = 0; i < n; i++) {
    if (!isOptimal[i]) {
      continue;
    }
    pair<long long, long long> stop = stops[i];
    long long newPos = stop.first;
    timeF += (newPos - pos) * rf;
    timeB += (newPos - pos) * rb;

    tastiness += stop.second * (timeF - timeB);
    pos = newPos;
    timeB = timeF;
  }

  cout << tastiness << '\n';

  return 0;
}

