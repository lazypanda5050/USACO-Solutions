#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> image;

struct PCL{
  int i1,j1,i2,j2;
};

bool isPCL(int r1, int c1, int r2, int c2) {
  set<char> uniqueColors;
  for (int r = r1; r <= r2; ++r) {
    for (int c = c1; c <= c2; ++c) {
      uniqueColors.insert(image[r][c]);
    }
  }

  if (uniqueColors.size() != 2) {
    return false;
  }

  int totalRows = r2 - r1 + 1;
  int totalCols = c2 - c1 + 1;
  vector<vector<bool>> visited(totalRows, vector<bool>(totalCols, false));

  map<char, int> colorCounts;
  for (char color : uniqueColors) {
    colorCounts[color] = 0;
  }

  int dirR[4] = {-1, 1, 0, 0};
  int dirC[4] = {0, 0, -1, 1};

  for (int r = r1; r <= r2; ++r) {
    for (int c = c1; c <= c2; ++c) {
      int localRow = r - r1;
      int localCol = c - c1;

      if (!visited[localRow][localCol]) {
        char curColor = image[r][c];
        colorCounts[curColor]++;

        queue<pair<int, int>> q;
        q.push({r, c});
        visited[localRow][localCol] = true;

        while (!q.empty()) {
          auto [curRow, curCol] = q.front();
          q.pop();

          for (int i = 0; i < 4; ++i) {
            int newR = curRow + dirR[i];
            int newC = curCol + dirC[i];

            if (newR >= r1 && newR <= r2 && newC >= c1 && newC <= c2) {

              int localNewR = newR - r1;
              int localNewC = newC - c1;

              if (!visited[localNewR][localNewC] && 
                  image[newR][newC] == curColor) {

                visited[localNewR][localNewC] = true;
                q.push({newR, newC});
              }
            }
          }
        }
      }
    }
  }

  auto colorIterator = uniqueColors.begin();
  char firstColor = *colorIterator;
  char secondColor = *(++colorIterator);

  int firstColorCount = colorCounts[firstColor];
  int secondColorCount = colorCounts[secondColor];

  return (firstColorCount == 1 && secondColorCount >= 2) || (secondColorCount == 1 && firstColorCount >= 2);
}

bool isInside(PCL a, PCL b){
  return (a.i1 >= b.i1 && a.i2 <= b.i2 && a.j1 >= b.j1 && a.j2 <= b.j2);
}

int main(){
  freopen("where.in", "r", stdin);
  freopen("where.out", "w", stdout);
  int n;
  cin >> n;

  for (int i = 0; i < n; i++){
    string s;
    cin >> s;
    image.push_back(s);
  }

  vector<PCL> candidates;
  for (int i1 = 0; i1 < n; i1++){
    for (int j1 = 0; j1 < n; j1++){
      // top left corner
      for (int i2 = i1; i2 < n; i2++){
        for (int j2 = j1; j2 < n; j2++){
          // bottom right corner
          if (isPCL(i1,j1,i2,j2)){
            candidates.push_back({i1,j1,i2,j2});
          }
        }
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < candidates.size(); i++){
    bool inside = false;
    for (int j = 0; j < candidates.size(); j++){
      if (i == j) continue;

      if (isInside(candidates[i],candidates[j])){
        inside = true;
        break;
      }
    }
    if (!inside){
      ans++;
    }
  }

  cout << ans << '\n';
}
