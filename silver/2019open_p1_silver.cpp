#include <bits/stdc++.h>
using namespace std;

int count(const vector<vector<int>>& grid, int i1, int j1, int i2, int j2, int l){
  int ret = 0;
  for (int i = i1; i <= i2; i++){
    for (int j = j1; j <= j2; j++){
      if (grid[i][j] == l){
        ret++;
      }
    }
  }

  return ret;
}

int main(){
  freopen("leftout.in", "r", stdin);
  freopen("leftout.out", "w", stdout);
  int n;
  cin >> n;

  vector<vector<int>> grid(n, vector<int>(n));
  char c;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      cin >> c;
      grid[i][j] = (c == 'L');
    }
  }

  for (int i = 1; i < n; i++){
    grid[i][0] = grid[i][0] ^ grid[0][0];
    for (int j = 1; j < n; j++){
      grid[i][j] = grid[i][j] ^ grid[0][j] ^ grid[i][0];
    }
  }

  if (count(grid,1,1,n-1,n-1,0) == 0){
    cout << "1 1\n";
    return 0;
  }
  else if (count(grid,1,1,n-1,n-1,1) == n-1){
    for (int j = 1; j < n; j++){
      if (count(grid,1,j,n-1,j,1) == n-1){
        cout << "1 " << j+1 << '\n';
        return 0;
      }
    }
    for (int i = 1; i < n; i++){
      if (count(grid,i,1,i,n-1,1) == n-1){
        cout << i+1 << " 1\n";
        return 0;
      }
    }
    cout << "-1\n";
    return 0;
  }
  else if (count(grid,1,1,n-1,n-1,1) != 1){
    cout << "-1\n";
    return 0;
  }
  for (int i = 1; i < n; i++){
    for (int j = 1; j < n; j++){
      if (grid[i][j] == 1){
        cout << i+1 << ' ' << j+1 << '\n';
      }
    }
  }

  return 0;
}
