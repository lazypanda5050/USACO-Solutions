#include <bits/stdc++.h>
#define ll long long
using namespace std;

signed main(){
  ll n;
  cin >> n;
  vector<ll> position;
  for (ll i = 0; i < n; i++){
    ll t;
    cin >> t;
    position.push_back(t-1);
  }

  vector<ll> ideal;

  for (ll i = 0; i < n; i++){
    ll t;
    cin >> t;
    ideal.push_back(t-1);
  }

  unordered_map<ll, vector<ll>> edge;
  for (ll i = 0; i < n; i++){
    if (edge.find(ideal[i]) == edge.end()){
      vector<ll> newE = {min(i+1,n-i)};
      edge.insert({ideal[i],newE});
    }
    else{
      edge.at(ideal[i]).push_back(min(i+1,n-i));
    }
  }

  unordered_map<ll, vector<ll>> pre;
  for (auto& [species, edgePos] : edge){
    sort(edgePos.begin(), edgePos.end());

    vector<ll> newP = {0};
    for (ll& pos : edgePos){
      newP.push_back(newP.back()+pos);
    }

    pre.insert({species,newP});
  }

  ll ans = 0;
  for (ll i = 0; i < n; i++){
    if (edge.find(position[i]) == edge.end()){
      continue;
    }

    if (position[i] == ideal[i]){
      ans += ((i+1)*i)/2;
      ans += (n-i-1)*(n-i)/2;
    }

    ll cur = min(i+1,n-i);

    ll idx = upper_bound(edge.at(position[i]).begin(), edge.at(position[i]).end(), cur) - edge.at(position[i]).begin();
    ans += pre.at(position[i])[idx];
    ans += cur*(edge.at(position[i]).size() - idx);
  }

  cout << ans << '\n';
}
