#include <bits/stdc++.h>
using namespace std;

struct Cow{
  long long seniority, a, t;
  bool operator>(const Cow& other) const {
    return seniority > other.seniority;
  }
};

int main(){
  freopen("convention2.in", "r", stdin);
  freopen("convention2.out", "w", stdout);
  long long n;
  cin >> n;

  vector<Cow> cows;
  for (long long i = 0; i < n; i++){
    long long a,t;
    cin >> a >> t;
    cows.push_back({i,a,t});
  }

  sort(cows.begin(), cows.end(), [](const Cow& a, const Cow& b){
      return a.a < b.a;
      });

  long long time = 0;
  long long cur = 0;
  long long ans = 0;

  priority_queue<Cow, vector<Cow>, greater<Cow>> waiting;
  while (cur < n || !waiting.empty()){
    if (cur < n && cows[cur].a <= time){
      waiting.push(cows[cur]);
      cur++;
    }
    else if (waiting.empty()){
      time = cows[cur].a+cows[cur].t;
      cur++;
    }
    else{
      Cow next = waiting.top();
      ans = max(ans, time-next.a);

      time += next.t;
      waiting.pop();
    }
  }

  cout << ans << '\n';
}
