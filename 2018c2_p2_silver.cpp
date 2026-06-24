#include <bits/stdc++.h>
using namespace std;

int main(){
  freopen("rental.in", "r", stdin);
  freopen("rental.out", "w", stdout);
  int n,m,r;
  cin >> n >> m >> r;

  vector<int> c(n);
  for (int i = 0; i < n; i++){
    cin >> c[i];
  }

  vector<pair<int, int>> sell(m); // {price, up to}
  for (int i = 0; i < m; i++){
    cin >> sell[i].second >> sell[i].first;
  }

  vector<int> rent(r);
  for (int i = 0; i < r; i++){
    cin >> rent[i];
  }

  sort(c.begin(), c.end(), greater<int>());
  sort(sell.begin(), sell.end(), greater<pair<int, int>>());
  sort(rent.begin(), rent.end(), greater<int>());
  
  int curShop = 0;
  int curRent = 0;
  int curCow = 0;
  long long ans = 0;
  while (curCow < n){
    int cur = c[curCow];
    int money = 0;
    int shop = curShop;
    int last = 0;

    while (shop < m){
      // if we sell the milk
      int sold = min(cur, sell[shop].second); // the most milk we can sell

      money += sell[shop].first*sold;
      cur -= sold;

      if (cur == 0){
        last = sold;
        break;
      }
      else{
        shop++;
      }
    }

    if (curRent >= r || money > rent[curRent]){
      ans += money;
      curShop = shop;
      if (curShop < m){
        sell[curShop].second -= last;
      }
      curCow++;
    }
    else{
      ans += rent[curRent];
      n--; // instead of renting the current cow, we rent the last cow
      curRent++;
    }
  }

  cout << ans << '\n';
}
