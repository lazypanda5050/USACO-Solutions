#include <bits/stdc++.h>
using namespace std;

// set origin to 2000 2000 to avoid negative coords
// each fence occupies 2 cells

const int LIMIT = 4005;
bool fenced[LIMIT][LIMIT];
int blobs[LIMIT][LIMIT];
int dirR[4] = {0,0,1,-1};
int dirC[4] = {1,-1,0,0};

int main(){
  freopen("gates.in", "r", stdin);
  freopen("gates.out", "w", stdout);
  int n;
  cin >> n;
  
  string path;
  cin >> path;
  
  // starting position
  int curR = 2000;
  int curC = 2000;
  for (int i = 0; i < n; i++){
    char nextMove = path[i];

    switch (nextMove){
      case 'N':
        fenced[curR][curC] = true;
        fenced[curR-1][curC] = true;
        curR -= 2;
        break;
      case 'E':
        fenced[curR][curC] = true;
        fenced[curR][curC+1] = true;
        curC += 2;
        break;
      case 'S':
        fenced[curR][curC] = true;
        fenced[curR+1][curC] = true;
        curR += 2;
        break;
      case 'W':
        fenced[curR][curC] = true;
        fenced[curR][curC-1] = true;
        curC -= 2;
        break;
    }
  }

  fill(&blobs[0][0], &blobs[0][0]+(LIMIT*LIMIT), -1);
  int curId = 0; // curId is also the number of blobs total
  for (int i = 0; i < LIMIT; i++){
    for (int j = 0; j < LIMIT; j++){
      if (blobs[i][j] == -1 && !fenced[i][j]){
        // unvisited and not a fence
        blobs[i][j] = curId;
        queue<pair<int, int>> q;
        q.push({i,j});
        while (!q.empty()){
          pair<int, int> cur = q.front(); q.pop();

          for (int dir = 0; dir < 4; dir++){
            int newR = cur.first+dirR[dir];
            int newC = cur.second+dirC[dir];

            if (newR >= 0 && newR < LIMIT && newC >= 0 && newC < LIMIT && blobs[newR][newC] == -1 && !fenced[newR][newC]){
              blobs[newR][newC] = curId;
              q.push({newR,newC});
            }
          }
        }

        curId++;
      }
    }
  }

  cout << curId - 1 << '\n';
}
