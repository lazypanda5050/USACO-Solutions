#include <bits/stdc++.h>
using namespace std;

int main(){
  long long n, m, k;
  cin >> n >> m >> k;
  
  vector<pair<long long, long long>> cows(n);
  for (long long i = 0; i < n; i++){
    long long w,a;
    cin >> w >> a;
    cows[i] = {w,a};
  }

  sort(cows.rbegin(), cows.rend());
  deque<pair<long long, long long>> towers;
  long long ans = 0;
  towers.push_back({LLONG_MAX,m});

  for (auto& [w,a] : cows){
    long long remaining = a;
    while (towers.size() > 0 && remaining > 0 && w+k <= towers[0].first){
      if (towers[0].second > remaining){
        towers[0].second -= remaining;
        remaining = 0;
      }
      else{
        remaining -= towers[0].second;
        towers.pop_front();
      }
    }

    long long cnt = a- remaining;
    if (cnt > 0){
      towers.push_back({w,cnt});
      ans += cnt;
    }
  }

  cout << ans << '\n';
}
