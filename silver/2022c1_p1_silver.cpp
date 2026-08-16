#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, av=0;
vector<ll> h;
vector<vector<ll>> adj;
vector<vector<ll>> orderFrom;
vector<vector<pair<ll, ll>>> orderTo;
vector<bool> visited;

ll ansNum = 0;

ll dfs(ll node, ll prev){
  ll toMove = h[node];
  for (ll i : adj[node]){
    if (i == prev){
      continue;
    }
    ll children = dfs(i, node);
    toMove += children;

    if (children > 0){
      orderFrom[node].emplace_back(i);
      orderTo[i].emplace_back(node, children);
      ansNum++;
    }
    else if (children < 0){
      orderFrom[i].emplace_back(node);
      orderTo[node].emplace_back(i, -children);
      ansNum++;
    }
  }
  return toMove;
}

void printOrders(ll node){
  visited[node] = true;
  for (ll i : orderFrom[node]){
    if (!visited[i]){
      printOrders(i);
    }
  }
  for (const pair<ll, ll>& i : orderTo[node]){
    cout << node+1 << ' ' << i.first+1 << ' ' << i.second << '\n';
  }
}

int main(){
  cin >> n;
  adj.resize(n);
  orderFrom.resize(n);
  orderTo.resize(n);
  visited.resize(n, false);
  for (ll i = 0; i < n; i++){
    ll a;
    cin >> a;
    h.emplace_back(a);
    av += a;
  }

  av /= n;

  for (ll i = 0; i < n; i++){
    h[i] -= av; // h[i] now represents the amount each barn has to change
  }

  for (ll i = 0; i < n-1; i++){
    ll a,b;
    cin >> a >> b;
    a--,b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  dfs(0,-1);
  cout << ansNum << '\n';

  for (ll i =0; i < n; i++){
    if (!visited[i]){
      printOrders(i);
    }
  }

  return 0;
}
