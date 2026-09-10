/*
 * how to compute original T
 * sort a, first cow is least milk, last cow is most milk
 * for each query, 
 * if j > a_i, find the spot where it goes (to the right), then shift all the ones to the left
 * if j < a_i, find the spot where it goes (to the left), then shift all the ones to the right
 */

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  ll n;
  cin >> n;
  vector<ll> newPos(n);
  vector<pair<ll, ll>> v(n);
  for (ll i = 0; i < n; i++){
    cin >> v[i].first;
    v[i].second = i;
  }

  sort(v.begin(), v.end());

  for (ll i = 0; i < n; i++){
    newPos[v[i].second] = i;
  }

  vector<ll> a(n);
  for (ll i = 0; i < n; i++){
    a[i] = v[i].first;
  }

  vector<ll> pfx(n+1,0);
  vector<ll> pfxW(n+1,0);
  for (ll i = 1; i <= n; i++){
    pfx[i] = pfx[i-1] + a[i-1];
    pfxW[i] = pfxW[i-1] + i*a[i-1];
  }

  auto rangeTotal = [&](ll l, ll r, ll k){
    // 0 based query, [L, R)
    ll sum1 = pfx[r]-pfx[l];
    ll sum2 = pfxW[r]-pfxW[l];
    return sum2 + (k-l-1)*sum1;
  };

  ll Q;
  cin >> Q;
  while (Q--){
    ll idx,b;
    cin >> idx >> b;

    idx--;
    idx = newPos[idx];

    if (b == a[idx]) {
      cout << rangeTotal(0, n, 1) << '\n';
    } 
    else if (b > a[idx]) {
      ll newIdx = lower_bound(a.begin(), a.end(), b) - a.begin();
      long long ans = rangeTotal(0, idx, 1) 
        + rangeTotal(idx + 1, newIdx, idx + 1) 
        + b * newIdx 
        + rangeTotal(newIdx, n, newIdx + 1);
      cout << ans << '\n';
    } 
    else {
      ll newIdx = lower_bound(a.begin(), a.end(), b) - a.begin();
      long long ans = rangeTotal(0, newIdx, 1) 
        + b * (newIdx + 1) 
        + rangeTotal(newIdx, idx, newIdx + 2) 
        + rangeTotal(idx + 1, n, idx + 2);
      cout << ans << '\n';
    }
    // 1 3 5 7 9 11
    //         ^
    //         4
    //     ^
    //   newIdX
    //
  }
}
