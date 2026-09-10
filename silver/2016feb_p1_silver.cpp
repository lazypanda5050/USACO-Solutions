#include <bits/stdc++.h>
using namespace std;

int main(){
  freopen("cbarn.in", "r", stdin);
  freopen("cbarn.out", "w", stdout);
  int n;
  cin >> n;
  vector<int> c(n);
  for (int i = 0; i < n; i++){
    cin >> c[i];
  }

  // find the optimal starting room
  int start = 0;
  int cur = 0;
  int minCows = 0;
  for (int i = 0; i < n; i++){
    cur += c[i]-1;
    if (cur < minCows){
      minCows = cur;
      start = (i+1)%n;
    }
  }

  // greedily assign the cows
  queue<int> q;
  long long ans = 0;
  for (int i = 0; i < n; i++){
    cur = (start + i) % n;
    for (int j = 0; j < c[cur]; j++){
      q.push(i);
    }
    int cowStart = q.front(); q.pop();
    long long dist = i - cowStart;
    ans += dist*dist;
  }

  cout << ans << '\n';
}
