#include <bits/stdc++.h>
using namespace std;

int n, k;
const int m = 10;

int dirR[4] = {1,-1,0,0};
int dirC[4] = {0,0,1,-1};

vector<string> grid;

pair<bool, vector<pair<int, int>>> findRemovable(){
  vector<vector<bool>> visited(n, vector<bool>(m, false));
  vector<pair<int, int>> ret;
  bool found = false;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == '0' || visited[i][j]) continue;

      char curColor = grid[i][j];
      vector<pair<int, int>> curBlob;
      queue<pair<int, int>> q;

      q.push({i, j});
      visited[i][j] = true;

      while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();
        curBlob.push_back({r, c});

        for (int d = 0; d < 4; d++) {
          int nr = r + dirR[d];
          int nc = c + dirC[d];

          if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
            if (!visited[nr][nc] && grid[nr][nc] == curColor) {
              visited[nr][nc] = true;
              q.push({nr, nc});
            }
          }
        }
      }

      if (curBlob.size() >= k) {
        found = true;
        for (const auto& coord : curBlob) {
          ret.push_back(coord);
        }
      }
    }
  }

  return {found, ret};
}

void removeRegions(vector<pair<int, int>> toRemove){
  for (const auto& coord : toRemove){
    grid[coord.first][coord.second] = '0';
  }
}

void applyGravity(){
  for (int c = 0; c < m; c++){
    int moveTo = n - 1;
    for (int r = n - 1; r >= 0; r--){
      if (grid[r][c] != '0') {
        char t = grid[r][c];
        grid[r][c] = '0';
        grid[moveTo][c] = t;
        moveTo--;
      }
    }
  }
}

int main(){
  freopen("mooyomooyo.in", "r", stdin);
  freopen("mooyomooyo.out", "w", stdout);
  cin >> n >> k;
  for (int i = 0; i < n; i++){
    string s;
    cin >> s;
    grid.push_back(s);
  }

  while (true){
    pair<bool, vector<pair<int, int>>> removableRegions = findRemovable();
    // found any    list of coords
    if (removableRegions.first == false){
      break;
    }

    removeRegions(removableRegions.second);
    applyGravity();
  }

  for (string s : grid){
    cout << s << '\n';
  }
}
