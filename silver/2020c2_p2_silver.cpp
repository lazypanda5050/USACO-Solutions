#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool check(ll n, ll k, ll m, ll x){
  ll g = 0;
  while (k>0&&g<n){
    ll y = (n-g)/x;
    if (y < m){
      ll left = (n-g + m-1) / m;
      return left <= k;
    }
    ll max = n-x*y;
    ll days = (max-g)/y+1;
    if (days>k){
      days = k;
    }
    g+=y*days;
    k-=days;
  }
  return g>=n;
}

int main(){
  freopen("loan.in", "r", stdin);
  freopen("loan.out", "w", stdout);
  ll n,k,m;
  cin >> n >> k >> m;

  ll l = 1;
  ll r = n;
  while (l<r){
    ll mid = (l+r+1)/2;
    if (check(n,k,m,mid)){
      l = mid;
    }
    else{
      r = mid-1;
    }
  }

  cout << l << '\n';
}
