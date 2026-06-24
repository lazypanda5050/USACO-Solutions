/*
 * lets say a farm has x uninfected neighbors
 * And there is one cow at the farm
 * So there are required ceil(log2(x+1)) superspreader events
 * Then another x events to spread those cows and keep one at the farm
 * In total there are ceil(log2(x+1))+x operations per farm
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<vector<int>> adj(n);

  for (int i = 0; i < n-1; i++){
    int a,b;
    cin >> a >> b;
    adj[--a].emplace_back(--b);
    adj[b].emplace_back(a);
  }

  int ans = 0;

  vector<bool> visited(n);
  queue<int> q;
  q.push(0);
  visited[0] = true;

  while (!q.empty()){
    int cur = q.front(); q.pop();

    int x = 0;

    for (int neighbor : adj[cur]){
      if (!visited[neighbor]){
        x++;
        visited[neighbor] = true;
        q.push(neighbor);
      }
    }

    ans += ceil(log2(x+1))+x;
  }

  cout << ans << '\n';
}
