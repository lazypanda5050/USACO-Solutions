#include <bits/stdc++.h>
using namespace std;

const int MAXK = 101;
bool visited[MAXK][MAXK][MAXK];

int x,y,k,m,ans=INT_MAX;

void floodfill(int curX, int curY, int moves){
  if (visited[curX][curY][moves] || moves > k){
    return;
  }
  visited[curX][curY][moves] = true;

  ans = min(ans, abs(m-(curX+curY)));

  // empty a pail
  floodfill(0,curY,moves+1);
  floodfill(curX,0,moves+1);
  
  // fill to top
  floodfill(x,curY,moves+1);
  floodfill(curX,y,moves+1);

  // pour contents
  int amountX = min(curX, y-curY);
  int amountY = min(curY, x-curX);

  floodfill(curX-amountX,curY+amountX,moves+1);
  floodfill(curX+amountY,curY-amountY,moves+1);
}

int main(){
  freopen("pails.in", "r", stdin);
  freopen("pails.out", "w", stdout);
  cin >> x >> y >> k >> m;

  floodfill(0,0,0);
  
  cout << ans << '\n';
}
