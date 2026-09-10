#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  long long ans = 0;
  int dp[7] = {0, 0, 0, 0, 0, 0, 0};
  long long n = s.size();
  string target = "bessie";

  for (char c : s) {
    dp[0]++;
    for (int d = 5; d >= 0; d--) {
      if (c == target[d]) {
        dp[d + 1] += dp[d];
        dp[d] = 0;
      }
    }
    ans += dp[6] * n;
    dp[0] += dp[6];
    dp[6] = 0;
    n--;
  }
  cout << ans << "\n";
}
