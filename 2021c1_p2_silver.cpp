#include <bits/stdc++.h>
using namespace std;

int main(){
  int T;
  cin >> T;
  while (T--){
    int n,m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++){
      int a,b;
      cin >> a >> b;
      a--,b--;
      adj[a].emplace_back(b);
      adj[b].emplace_back(a);
    }

    vector<int> blobs(n, -1);
    int curId = 0;

    for (int i = 0; i < n; i++){
      if (blobs[i] != -1){
        continue;
      }
      queue<int> q;
      q.push(i);
      blobs[i] = curId;

      while (!q.empty()){
        int cur = q.front(); q.pop();
        
        for (int neighbor : adj[cur]){
          if (blobs[neighbor] != -1){
            continue;
          }

          blobs[neighbor] = curId;
          q.push(neighbor);
        }
      }
      curId++;
    }

    vector<vector<int>> blobNodes(curId); // blobNodes[i] stores all nodes with blobId i
    for (int i = 0; i < n; i++){
      blobNodes[blobs[i]].emplace_back(i);
    }

    vector<int> startBlob = blobNodes[blobs[0]];
    vector<int> endBlob = blobNodes[blobs[n-1]];

    vector<int> dist1(curId, INT_MAX);
    vector<int> dist2(curId, INT_MAX);

    // min distance to start blob
    int a = 0;
    for (int i = 0; i < n; i++){
      int dist = abs(startBlob[a]-i);
      while (a < startBlob.size() - 1 && abs(startBlob[a+1] - i) < dist){
        a++;
      }
      dist1[blobs[i]] = min(dist1[blobs[i]], dist);
    }

    // min distance to end blob
    int b = 0;
    for (int i = 0; i < n; i++){
      int dist = abs(endBlob[b]-i);
      while (a < endBlob.size() - 1 && abs(endBlob[b+1] - i) < dist){
        b++;
      }
      dist2[blobs[i]] = min(dist2[blobs[i]], dist);
    }

    // figure out which intermediate blob is the best
    long long ans = LLONG_MAX;
    for (int i = 0; i < curId; i++){
      ans = min(ans, (long long) dist1[i]*dist1[i] + (long long) dist2[i]*dist2[i]);
    }

    cout << ans << '\n';
  }
}
