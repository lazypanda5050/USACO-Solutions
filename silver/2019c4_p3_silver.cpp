/*
 * loop through all the cows and build blobs, store smallest/biggest x and y coords of each blob
*/

#include <bits/stdc++.h>
using namespace std;

struct Blob{
  int smallX,smallY,bigX,bigY;
  Blob() : smallX(INT_MAX), smallY(INT_MAX), bigX(-1),bigY(-1) {}
};

int main(){
  freopen("fenceplan.in", "r", stdin);
  freopen("fenceplan.out", "w", stdout);
  int n,m;
  cin >> n >> m;

  vector<pair<int, int>> cows(n);
  for (int i = 0; i < n; i++){
    cin >> cows[i].first >> cows[i].second;
  }

  vector<vector<int>> adj(n);
  for (int i = 0; i < m; i++){
    int a,b;
    cin >> a >> b;
    a--,b--;

    adj[a].emplace_back(b);
    adj[b].emplace_back(a);
  }

  vector<int> blobs(n, -1); // the ith cow belongs to which blob
  vector<Blob> blobInfo; // the info for each blob ID

  int curId = 0;
  for (int i = 0; i < n; i++){
    if (blobs[i] == -1){
      // unvisited
      queue<int> q;

      blobInfo.push_back(Blob());
      blobs[i] = curId;
      blobInfo[curId].smallX = min(blobInfo[curId].smallX, cows[i].first);
      blobInfo[curId].smallY = min(blobInfo[curId].smallY, cows[i].second);
      blobInfo[curId].bigX = max(blobInfo[curId].bigX, cows[i].first);
      blobInfo[curId].bigY = max(blobInfo[curId].bigY, cows[i].second);
      q.push(i);

      while (!q.empty()){
        int cur = q.front(); q.pop();

        for (int neighbor : adj[cur]){
          if (blobs[neighbor] == -1){
            blobs[neighbor] = curId;
            blobInfo[curId].smallX = min(blobInfo[curId].smallX, cows[neighbor].first);
            blobInfo[curId].smallY = min(blobInfo[curId].smallY, cows[neighbor].second);
            blobInfo[curId].bigX = max(blobInfo[curId].bigX, cows[neighbor].first);
            blobInfo[curId].bigY = max(blobInfo[curId].bigY, cows[neighbor].second);
            q.push(neighbor);
          }
        }
      }
      curId++;
    }
  }

  int ans = INT_MAX;
  for (Blob blob : blobInfo){
    ans = min(ans, 2*(blob.bigX-blob.smallX)+2*(blob.bigY-blob.smallY));
  }

  cout << ans << '\n';
}
