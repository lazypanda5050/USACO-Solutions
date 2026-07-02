#include <bits/stdc++.h>
#define ll long long
#define P pair<ll,ll>
using namespace std;

P operator+(const P& a, const P& b){
  return {a.first+b.first, a.second+b.second};
}
P operator-(const P& a, const P& b){
  return {a.first-b.first, a.second-b.second};
}

vector<pair<P, ll>> getSubsets(const vector<P>& dirs){
  vector<pair<P,ll>> v{{}};
  for (const P& d : dirs){
    v.resize(2*v.size());
    for (ll i = 0; i < v.size() / 2; i++){
      v[i+v.size()/2] = {v[i].first + d, v[i].second+1};
    }
  }

  sort(v.begin(), v.end());
  return v;
}

int main(){
  ll n;
  cin >> n;
  P goal;
  cin >> goal.first >> goal.second;
  vector<P> dirs(n);
  for (ll i = 0; i < n; i++){
    cin >> dirs[i].first >> dirs[i].second;
  }

  vector<pair<P, ll>> a = getSubsets(vector<P>(dirs.begin(), dirs.begin() + n/2));
  vector<pair<P, ll>> b = getSubsets(vector<P>(dirs.begin() + n/2, dirs.end()));
  reverse(b.begin(), b.end());

  vector<ll> ans(n+1);
  vector<ll> with;
  P restPrev = {LLONG_MAX, LLONG_MAX};

  ll ib = 0;
  for (const auto& [offset, num] : a){
    P rest = goal - offset;
    if (rest != restPrev){
      restPrev = rest;
      with = vector<ll>(n-n/2+1);
      for (; ib < b.size() && b[ib].first > rest; ib++); // advance ib to proper position
      for (; ib < b.size() && b[ib].first == rest; ib++){
        with[b[ib].second]++;
      }
    }
    for (ll i = 0; i < with.size(); i++){
      ans[i+num] += with[i];
    }
  }

  for (ll i = 1; i <= n; i++){
    cout << ans[i] << '\n';
  }
}
