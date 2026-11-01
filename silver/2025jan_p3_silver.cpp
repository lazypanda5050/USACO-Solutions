#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> pLex(const vector<vector<int>>& m1, const vector<vector<int>>& m2, const int& n){
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      if (m1[i][j] < m2[i][j]){
        return m1;
      }
      else if (m1[i][j] > m2[i][j]){
        return m2;
      }
    }
  }
  return m1;
}

int main(){
  int n;
  cin >> n;
  if (n == 1){
    int a;
    cin >> a;
    cout << a << '\n';
    return 0;
  }

  vector<pair<int, pair<int, int>>> af(n*2+1); // frequencies of each number {frequency, {{i : j, ...}, {j : i, ...}}
  vector<vector<int>> a(n, vector<int>(n));
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      cin >> a[i][j];
      af[a[i][j]].first++;
      af[a[i][j]].second = {i, j};
    }
  }

  vector<int> ifreq(2*n+1);
  for (int i = 2; i <= 2*n; i++) {
    if (i <= n + 1){
      ifreq[i] = i-1;
    }
    else{
      ifreq[i] = 2*n - i + 1;
    }
  }

  int fSing=-1; // first single occurence
  int sSing=-1;
  for (int i = 2; i <= 2*n; i++){
    if (af[i].first == 1){
      if (fSing == -1){
        fSing = i;
      }
      else{
        sSing = i;
      }
    }
  }

  if (af[fSing].second > af[sSing].second){
    swap(fSing, sSing);
  }

  // case 1: first occurence of freq=1 is 2
  vector<int> rowPerm(n);
  vector<int> colPerm(n);

  int rowNum = af[fSing].second.first;
  for (int j = 0; j < n; j++){
    rowPerm[af[a[rowNum][j]].first-1] = j;
  }

  int colNum = af[fSing].second.second;
  for (int j = 0; j < n; j++){
    colPerm[af[a[j][colNum]].first-1] = j;
  }

  vector<vector<int>> m1(n, vector<int>(n));
  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= n; j++){
      m1[colPerm[j-1]][rowPerm[i-1]] = i+j;
    }
  }

  // case 2: second occurence of freq=1 is 2
  rowNum = af[sSing].second.first;
  for (int j = 0; j < n; j++){
    rowPerm[af[a[rowNum][j]].first-1] = j;
  }

  colNum = af[sSing].second.second;
  for (int j = 0; j < n; j++){
    colPerm[af[a[j][colNum]].first-1] = j;
  }

  vector<vector<int>> m2(n, vector<int>(n));
  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= n; j++){
      m2[colPerm[j-1]][rowPerm[i-1]] = i+j;
    }
  }

  vector<vector<int>> ans = pLex(m1, m2, n);
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      cout << ans[i][j];
      if (j != n-1){
        cout << ' ';
      }
    }
    cout << '\n';
  }
}
