#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  // R = 0, D = 1
  vector<vector<int>> grid(n + 1, vector<int>(n + 1));
  for (int i = 0; i < n; i++) {
    string s;
    int last;
    cin >> s >> last;
    grid[i][n] = last;
    for (int j = 0; j < n; j++) {
      grid[i][j] = (s[j] == 'R') ? 0 : 1;
    }
  }

  for (int i = 0; i < n; i++) {
    cin >> grid[n][i];
  }

  vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      dp[i][j] = 1;
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      dp[i + grid[i][j]][j + (grid[i][j] ^ 1)] += dp[i][j];
    }
  }

  int ans = 0;
  for (int i = 0; i < n; i++){
    ans += dp[i][n] * grid[i][n];
  }

  for (int j = 0; j < n; j++){
    ans += dp[n][j] * grid[n][j];
  }

  cout << ans << '\n';

  int Q;
  cin >> Q;
  while (Q--) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;

    int val = dp[a][b];

    int i = a + grid[a][b];
    int j = b + abs(1 - grid[a][b]);
    while (true) {
      dp[i][j] -= val;
      if (i == n || j == n){
        break;
      }

      int ni = i + grid[i][j];
      int nj = j + abs(1 - grid[i][j]);
      i = ni;
      j = nj;
    }

    grid[a][b] ^= 1;

    i = a + grid[a][b];
    j = b + (grid[a][b] ^ 1);
    while (true) {
      dp[i][j] += val;
      if (i == n || j == n){
        break;
      }
      int ni = i + grid[i][j];
      int nj = j + abs(1 - grid[i][j]);
      i = ni;
      j = nj;
    }

    int ans = 0;

    // get vertical vats
    for (int i = 0; i < n; i++) {
      ans += dp[i][n] * grid[i][n];
    }

    // get horizontal vats
    for (int j = 0; j < n; j++) {
      ans += dp[n][j] * grid[n][j];
    }

    cout << ans << '\n';
  }
}
