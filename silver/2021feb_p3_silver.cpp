#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<vector<int>> g(n+1, vector<int>(n+1));
  vector<int> r(n+1);

  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= n; j++){
      cin >> g[i][j];
    }
  }

  long long ans = 0;
  for (int i1 = 1; i1 <= n; i1++){
    for (int j = 1; j <= n; j++){
      r[j] = 1;
    }

    for (int i2 = i1; i2 <= n; i2++){
      int lastz = 0;
      int lastn = 0;

      for (int j = 1; j <= n; j++){
        if (g[i2][j] < 100){
          r[j] = -1;
        }
        if (g[i2][j] == 100 && r[j] != -1){
          r[j] = 0;
        }

        if (r[j] == 0){
          lastz = j;
        }
        if (r[j] == -1){
          lastn = j;
        }

        if (r[j] == 0 || r[j] == 1){
          ans += max(0, lastz - lastn);
        }
      }
    }
  }

  cout << ans << '\n';
}
