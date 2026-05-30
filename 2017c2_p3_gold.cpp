#include <bits/stdc++.h>
using namespace std;

const int maxN = 20;
int dist[maxN][maxN][4][maxN][maxN][4];

struct State{
    int x1,y1,d1,x2,y2,d2; // 0 = up, 1 = right, 2 = down, 3 = left

    State(int x1, int y1, int d1, int x2, int y2, int d2) : x1(x1), y1(y1), d1(d1), x2(x2), y2(y2), d2(d2) {}
    State() : x1(-1),y1(-1),d1(-1),x2(-1),y2(-1),d2(-1) {}
};

vector<State> getMoves(int n, State cur, const vector<vector<int>>& matrix){
    int x1=cur.x1,y1=cur.y1,d1=cur.d1,x2=cur.x2,y2=cur.y2,d2=cur.d2;
    vector<State> ans;
    State t = cur;

    // forward
    if (cur.d1 == 0){
        // up
        t.x1++;
    }
    else if (cur.d1 == 1){
        // right
        t.y1++;
    }
    else if (cur.d1 == 2){
        // down
        t.x1--;
    }
    else if (cur.d1 == 3){
        // left
        t.y1--;
    }

    if (t.x1 < 0 || t.x1 >= n || t.y1 < 0 || t.y1 >= n || matrix[t.x1][t.y1] == 1 || (x1 == n-1 && y1 == n-1)){
        // reverse the change
        t.x1 = x1;
        t.y1 = y1;
    }

    if (cur.d2 == 0){
        // up
        t.x2++;
    }
    else if (cur.d2 == 1){
        // right
        t.y2++;
    }
    else if (cur.d2 == 2){
        // down
        t.x2--;
    }
    else if (cur.d2 == 3){
        // left
        t.y2--;
    }

    if (t.x2 < 0 || t.x2 >= n || t.y2 < 0 || t.y2 >= n || matrix[t.x2][t.y2] == 1 || (x2 == n-1 && y2 == n-1)){
        // reverse the change
        t.x2 = x2;
        t.y2 = y2;
    }

    ans.push_back(t);
    t = cur;

    // turn left
    t.d1 = (d1-1+4) % 4;
    t.d2 = (d2-1+4) % 4;

    ans.push_back(t);
    t = cur;

    // turn right
    t.d1 = (d1+1+4) % 4;
    t.d2 = (d2+1+4) % 4;

    ans.push_back(t);

    return ans;
}

int main(){
    freopen("cownav.in", "r", stdin);
    freopen("cownav.out", "w", stdout);
    int n;
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));

    for (int i = n - 1; i >= 0; i--){
        for (int j = 0; j < n; j++){
            char c;
            cin >> c;
            if (c == 'E') matrix[i][j] = 0;
            else matrix[i][j] = 1;
        }
    }

    queue<State> q;
    q.push(State(0,0,0,0,0,1));
    dist[0][0][0][0][0][1] = 0;

    while (!q.empty()){
        State cur = q.front();
        auto [x1,y1,d1,x2,y2,d2] = cur;
        int curDist = dist[x1][y1][d1][x2][y2][d2];
        q.pop();

        if (x1 == n-1 && y1 == n-1 && x2 == n-1 && y2 == n-1) {
            // at end
            cout << dist[x1][y1][d1][x2][y2][d2] << '\n';
            return 0;
        }

        for (State move : getMoves(n, cur, matrix)){
            auto [newx1,newy1,newd1,newx2,newy2,newd2] = move;
            if (dist[newx1][newy1][newd1][newx2][newy2][newd2] == -1){
                // unvisited
                dist[newx1][newy1][newd1][newx2][newy2][newd2] = curDist+1;
                q.push(move);
            }
        }
    }
}