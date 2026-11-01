#include <bits/stdc++.h>
using namespace std;

vector<int> f,s,d;
int ans = INT_MAX,N,B;
vector<vector<bool>> visited;

void dfs(int t,int b){
  if (visited[t][b]){
    return;
  }
  visited[t][b] = true;

  if (t == N-1){
    ans = min(ans, b);
    return;
  }

  for (int i = t+1; i < N && i-t <= d[b]; i++){
    if (f[i] <= s[b]){
      dfs(i,b);
    }
  }

  for (int i = b+1; i < B; i++){
    if (f[t] <= s[i]){
      dfs(t,i);
    }
  }
}

signed main(){
  freopen("snowboots.in", "r", stdin);
  freopen("snowboots.out", "w", stdout);
  cin >> N >> B;
  f.resize(N);
  s.resize(B);
  d.resize(B);
  visited.resize(N, vector<bool>(B, false));

  for (int i = 0; i < N; i++){
    cin >> f[i];
  }

  for (int i = 0; i < B; i++){
    cin >> s[i] >> d[i];
  }

  dfs(0,0);

  cout << ans << '\n';
}
