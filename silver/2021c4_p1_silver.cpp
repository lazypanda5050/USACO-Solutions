#include <bits/stdc++.h>
using namespace std;

int pow3[9];
int dir[4][2] = {
  {0,1},
  {0,-1},
  {1,0},
  {-1,0}
};

void initPow(){
  pow3[0] = 1;
  for (int i = 1; i < 9; i++){
    pow3[i] = pow3[i-1]*3;
  }
}

int getC(int mask, int pos){
  // 0 = empty, 1 = M, 2 = O
  return (mask / pow3[pos]) % 3;
}

int addC(int mask, int pos, int c){
  return mask + (c - ((mask / pow3[pos]) % 3)) * pow3[pos];
}

bool isWin(int mask){
  if ((getC(mask,0) == 1 && getC(mask,1) == 2 && getC(mask,2) == 2) ||
      (getC(mask,0) == 2 && getC(mask,1) == 2 && getC(mask,2) == 1) ||
      (getC(mask,3) == 1 && getC(mask,4) == 2 && getC(mask,5) == 2) ||
      (getC(mask,3) == 2 && getC(mask,4) == 2 && getC(mask,5) == 1) ||
      (getC(mask,6) == 1 && getC(mask,7) == 2 && getC(mask,8) == 2) ||
      (getC(mask,6) == 2 && getC(mask,7) == 2 && getC(mask,8) == 1) ||
      (getC(mask,0) == 1 && getC(mask,3) == 2 && getC(mask,6) == 2) ||
      (getC(mask,0) == 2 && getC(mask,3) == 2 && getC(mask,6) == 1) ||
      (getC(mask,1) == 1 && getC(mask,4) == 2 && getC(mask,7) == 2) ||
      (getC(mask,1) == 2 && getC(mask,4) == 2 && getC(mask,7) == 1) ||
      (getC(mask,2) == 1 && getC(mask,5) == 2 && getC(mask,8) == 2) ||
      (getC(mask,2) == 2 && getC(mask,5) == 2 && getC(mask,8) == 1) ||
      (getC(mask,0) == 1 && getC(mask,4) == 2 && getC(mask,8) == 2) ||
      (getC(mask,0) == 2 && getC(mask,4) == 2 && getC(mask,8) == 1) ||
      (getC(mask,6) == 1 && getC(mask,4) == 2 && getC(mask,2) == 2) ||
      (getC(mask,6) == 2 && getC(mask,4) == 2 && getC(mask,2) == 1) ){
    return true;
  }
  return false;
}

int main(){
  initPow();

  int n;
  cin >> n;
  vector<vector<string>> maze(n, vector<string>(n));
  vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(n, vector<bool>(59053,false))); // 3^10-1 (+5 for safety)
  int startR;
  int startC;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      char a,b,c;
      cin >> a >> b >> c;
      if (a == 'B'){
        startR = i;
        startC = j;
        maze[i][j] = "...";
      }
      else{
        maze[i][j] = string({a,b,c});
      }
    }
  }


  unordered_set<int> ans;
  queue<pair<pair<int, int>, int>> q; // {{r,c}, board}
  visited[startR][startC][0] = true;
  q.push({{startR,startC}, 0});

  while (!q.empty()){
    auto [pos, board] = q.front();
    q.pop();
    if (isWin(board)){
      ans.insert(board);
      continue;
    }

    for (const auto& d : dir){
      int newR = pos.first + d[0];
      int newC = pos.second + d[1];

      if (newR < n && newR >= 0 && newC < n && newC >= 0 && maze[newR][newC] != "###"){
        // valid
        int newBoard = board;
        if (maze[newR][newC] != "..."){
          // board change
          string move = maze[newR][newC];
          if (getC(board, (move[1]-'0'-1) * 3 + move[2]-'0'-1) == 0){
            newBoard = addC(board, (move[1]-'0'-1) * 3 + move[2]-'0'-1, (move[0] == 'M') ? 1 : 2);
          }
        }

        if (visited[newR][newC][newBoard]){
          continue;
        }
        else{
          visited[newR][newC][newBoard] = true;
          q.push({{newR,newC},newBoard});
        }
      }
    }
  }

  cout << ans.size() << '\n';
}
