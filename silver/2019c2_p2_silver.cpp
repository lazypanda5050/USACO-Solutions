#include <bits/stdc++.h>
using namespace std;

int n;

bool isValid(int i, int j){
  if (i < 0 || i >= n || j < 0 || j >= n){
    return false;
  }

  return true;
}

const int dirX[4] = {1,-1,0,0};
const int dirY[4] = {0,0,1,-1};

int getNeighbors(int x, int y, const vector<vector<char>>& m){
  int neighbors = 0;
  for (int i = 0; i < 4; i++){
    if (isValid(x+dirX[i],y+dirY[i]) && m[x+dirX[i]][y+dirY[i]] == '#'){
      neighbors++;
    }
  }

  return neighbors;
}

void bfs(int i, int j, int curId, vector<vector<int>>& blobs, vector<pair<int, int>>& blobInfo, const vector<vector<char>>& m){
  queue<pair<int, int>> q;
  q.push({i,j});
  blobs[i][j] = curId;

  int area = 1;
  int perim = 4-getNeighbors(i,j,m);

  while (!q.empty()){
    pair<int, int> cur = q.front();
    q.pop();

    for (int i = 0; i < 4; i++){
      int newX = cur.first+dirX[i];
      int newY = cur.second+dirY[i];
      if (isValid(newX,newY) && m[newX][newY] == '#' && blobs[newX][newY] == -1){
        perim += (4-getNeighbors(newX,newY,m));
        area++;
        q.push({newX,newY});
        blobs[newX][newY] = curId;
      }
    }

  }

  blobInfo.push_back({area,perim});
}

int main(){
  freopen("perimeter.in", "r", stdin);
  freopen("perimeter.out","w",stdout);

  cin >> n;
  vector<vector<char>> m(n, vector<char>(n));
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      cin >> m[i][j];
    }
  }

  vector<vector<int>> blobs(n, vector<int>(n,-1));
  vector<pair<int,int>> blobInfo; // {area, perim}
  

  int curId = 0;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      if (blobs[i][j] == -1 && m[i][j] == '#'){
        // unvisited
        bfs(i, j, curId, blobs, blobInfo, m);
        curId++;
      }
    }
  }

  sort(blobInfo.begin(), blobInfo.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.first != b.first) {
            return a.first > b.first; 
        }
        return a.second < b.second;
    });

  cout << blobInfo[0].first << ' ' << blobInfo[0].second << '\n';
}
