#include <bits/stdc++.h>
using namespace std;

int n,m;

int main(){
  freopen("milkvisits.in", "r", stdin);
  freopen("milkvisits.out", "w", stdout);
  cin >> n >> m;

  string farms;
  cin >> farms;
  
  vector<vector<int>> adj(n, vector<int>(0));
  for (int i = 0; i < n-1; i++){
    int a,b;
    cin >> a >> b;
    a--,b--;
    adj[a].emplace_back(b);
    adj[b].emplace_back(a);
  }

  vector<int> blobs(n, -1); // the ith farm is part of what blob (id)
  vector<char> blobTypes; // the ith blobId is of type {G,H}

  int curId = 0;
  for (int i = 0; i < n; i++){
    if (blobs[i] == -1){
      // unvisited
      queue<int> q;
      q.push(i);

      blobs[i] = curId;
      blobTypes.emplace_back(farms[i]);

      while (!q.empty()){
        int cur = q.front(); q.pop();

        for (int neigh : adj[cur]){
          if (farms[neigh] == blobTypes[curId] && blobs[neigh] == -1){
            q.push(neigh);
            blobs[neigh] = curId;
          }
        }
      }
      
      curId++;
    }
  }
  for (int i = 0; i < m; i++){
    int a,b;
    char c;
    cin >> a >> b >> c;
    a--,b--;
    if (blobs[a] != blobs[b]){
      cout << 1;
    }
    else if (blobTypes[blobs[a]] == c){
      cout << 1;
    }
    else{
      cout << 0;
    }
  }

  cout << '\n';
}
