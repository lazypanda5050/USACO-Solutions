#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> adj;
vector<int> clocks;
int sum0, sum1, nodes0, nodes1;

void dfs(int cur, int color, int par){
  if (color == 0){
    nodes0++;
    sum0 += clocks[cur];
  }
  else{
    nodes1++;
    sum1 += clocks[cur];
  }

  for (int neighbor : adj[cur]){
    if (neighbor != par){
      // different group
      dfs(neighbor, 1-color, cur);
    }
  }
}

int main(){
  freopen("clocktree.in", "r", stdin);
  freopen("clocktree.out", "w", stdout);
  cin >> n;
  for (int i = 0; i < n; i++){
    int a;
    cin >> a;
    clocks.push_back(a);
  }

  adj.resize(n);
  for (int i = 0; i < n-1; i++){
    int a,b;
    cin >> a >> b;
    a--,b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  dfs(0,0,-1);

  if ((sum0%12) == (sum1%12)){
    cout << n << '\n';
  }
  else if ((sum0+1)%12==(sum1%12)){
    cout << nodes1 << '\n';
  }
  else if((sum0%12)==(sum1+1)%12){
    cout << nodes0 << '\n';
  }
  else{
    cout << 0 << '\n';
  }
}
