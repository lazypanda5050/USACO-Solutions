#include <bits/stdc++.h>
#define ll long long
using namespace std;

signed main(){
  ll n;
  cin >> n;
  set<ll> a;
  for (ll i = 0; i < n; i++){
    ll t;
    cin >> t;
    a.insert(t);
  }

  vector<ll> a_i(a.begin(), a.end());

  ll u = a_i[0]/4;
  for (ll x : a_i){
    if (x/4 < u){
      u = x/4;
    }
  }

  ll ans;
  if (a_i.size() < 4){
    ans = u*(u+1) / 2;
    cout << ans << '\n';
    return 0;
  }

  set<ll> r;
  ll limit = min((ll)a_i.size(), 1LL*5);
  for (ll i = 0; i < limit; i++){
    for (ll j = i + 1; j < limit; j++){ 
      ll diff = abs(a_i[i]-a_i[j]);
      for (ll t = 1; t * t <= diff; t++){
        if (diff % t == 0){
          if (t <= u) r.insert(t);
          if (diff/t <= u) r.insert(diff/t);
        }
      }
    }
  }

  auto test = [&](ll L) {
    if (L > u){
      return false;
    }
    set<ll> mods;
    for (ll i : a_i){
      mods.insert(i%L);
      if (mods.size() >= 4){
        return false;
      }
    }
    return true;
  };

  ans = 0;
  for (ll L : r){
    if (test(L)){
      ans += L;
    }
  }

  cout << ans << '\n';
}
