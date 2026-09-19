#include <bits/stdc++.h>
using namespace std;

struct Event{
  long long t,x,y;
  bool operator<(const Event& b) const {
    return t < b.t;
  }
};

bool reachable(const Event& a, const Event& b){
  long long dx = a.x - b.x;
  long long dy = a.y - b.y;
  long long dt = a.t - b.t;
  return dt*dt >= dx*dx + dy*dy;
}

signed main(){
  long long g,n;
  cin >> g >> n;
  vector<Event> grazings;
  for (long long i = 0; i < g; i++){
    long long x,y,t;
    cin >> x >> y >> t;
    grazings.push_back({t,x,y});
  }

  sort(grazings.begin(), grazings.end());

  long long ans = 0;
  for (long long i = 0; i < n; i++){
    long long x,y,t;
    cin >> x >> y >> t;
    Event alibi = {t,x,y};

    long long pos = upper_bound(grazings.begin(), grazings.end(), alibi) - grazings.begin();

    bool innocent = false;
    for (long long j = pos - 1; j <= pos; j++){
      if (0 <= j && j < g){
        innocent |= !reachable(grazings[j], alibi);
      }
    }

    ans += innocent;
  }

  cout << ans << '\n';
}
