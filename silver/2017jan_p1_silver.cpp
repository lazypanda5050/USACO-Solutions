#include <bits/stdc++.h>
using namespace std;

bool check(int k, int t, int n, const vector<int>& cows){
  int time = 0, cur = 0;
  int size = 0;
  priority_queue<int> pq;

  while (size < k && cur < n){
    pq.push(-cows[cur]);
    size++;
    cur++;
  }

  while (!pq.empty()){
    time += max(0, -pq.top() - time);
    pq.pop();
    if (cur < n){
      pq.push(-(cows[cur]+time));
      cur++;
    }
  }

  if (time > t){
    return false;
  }
  else{
    return true;
  }
}

int main(){
  freopen("cowdance.in", "r", stdin);
  freopen("cowdance.out", "w", stdout);
  int n,t;
  cin >> n >> t;
  vector<int> cows(n);
  for (int i = 0; i < n; i++){
    cin >> cows[i];
  }
  
  int l = 1;
  int r = n;
  int ans = n;

  while (l <= r){
    int mid = l + (r-l)/2;

    if (check(mid,t,n,cows)){
      ans = min(ans, mid);
      r = mid-1;
    }
    else{
      l = mid+1;
    }
  }

  cout << ans << '\n';
}
