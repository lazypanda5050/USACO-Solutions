#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<vector<int>> grid(n, vector<int>(n));
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      cin >> grid[i][j];
    }
  }

  int rowAns = 0;
  int colAns = 0;

  for (int i = 0; i < n; i++){
    int sum[2] = {0,0};

    for (int j = 0; j < n; j++){
      sum[j%2] += grid[i][j];
    }

    rowAns += max(sum[0], sum[1]);
  }

  for (int i = 0; i < n; i++){
    int sum[2] = {0,0};

    for (int j = 0; j < n; j++){
      sum[j%2] += grid[j][i];
    }

    colAns += max(sum[0], sum[1]);
  }

  cout << max(rowAns, colAns) << '\n';
}
