#include <bits/stdc++.h>
using namespace std;

signed main(){
  int T;
  cin >> T;
  while (T--){
    int n, x1;
    cin >> n >> x1;

    vector<pair<int, int>> rd, ru, o; // {y,x}
    vector<vector<int>> tar(n, vector<int>(3));
    int md = 2e9, mu = -2e9; // max down, min up
    for (int i = 0; i < n; i++){
      for (int j = 0; j < 3; j++){
        cin >> tar[i][j];
      }
      rd.push_back({tar[i][0],tar[i][2]});
      ru.push_back({tar[i][1],tar[i][2]});
      o.push_back({tar[i][0],x1});
      o.push_back({tar[i][1],x1});
      mu = max(mu,tar[i][1]);
      md = min(md,tar[i][0]);
    }

    sort(o.begin(), o.end());

    vector<int> neg, pos;
    vector<int> s(4 * n);
    for (int i = 0; i < 4 * n; i++){
      cin >> s[i];
      if (s[i] < 0){
        neg.push_back(s[i]);
      }
      else {
        pos.push_back(s[i]);
      }
    }

    if (neg.size() < n || pos.size() < n){
      cout << -1 << '\n';
      continue;
    }

    sort(neg.begin(), neg.end());
    sort(pos.begin(), pos.end());

    multiset<long long> outer_neg, outer_pos;
    for (int i = neg.size() - n; i < neg.size(); i++){
      outer_neg.insert(-neg[i]);
    }
    for (int i = 0; i < n; i++){
      outer_pos.insert(pos[i]);
    }

    auto valid1 = [&](long long h){
      multiset<long long> tmp = outer_pos;

      for (auto pt : rd){
        long long highest_slope = (pt.first - h) / pt.second;
        auto it = tmp.upper_bound(highest_slope);
        if (it == tmp.begin()){
          return false;
        }
        tmp.erase(tmp.find(*prev(it)));
      }
      return true;
    };

    long long l = -2e18, r = md - 1;
    while (l < r){
      long long m = (l + r + 1) / 2;
      if (valid1(m)){
        l = m;
      }
      else{
        r = m - 1;
      }
    }

    long long lowest = l;

    auto valid2 = [&](long long h){
      multiset<long long> tmp = outer_neg;

      for (auto pt : ru){
        long long highest_slope = ((h - pt.first) / pt.second);
        auto it = tmp.upper_bound(highest_slope);
        if (it == tmp.begin()){
          return false;
        }
        tmp.erase(tmp.find(*prev(it)));
      }
      return true;
    };

    // calculate highest value
    l = mu + 1, r = 2e18;
    while (l < r){
      long long m = (l + r) / 2;
      if (valid2(m)){
        r = m;
      }
      else{
        l = m + 1;
      }
    }

    long long highest = l;

    // calculate remaining
    vector<int> rem;
    for (int i = 0; i < neg.size() - n; i++){
      rem.push_back(neg[i]);
    }
    for (int i = n; i < pos.size(); i++){
      rem.push_back(pos[i]);
    }

    sort(rem.begin(), rem.end());

    long long cur_mn = 2e18, cur_mx = -2e18;
    for (int i = 0; i < 2 * n; i++){
      long long cur_ht = o[i].first - 1LL * rem[i] * o[i].second;
      cur_mn = min(cur_mn, cur_ht);
      cur_mx = max(cur_mx, cur_ht);
    }

    lowest = min(lowest, cur_mn);
    highest = max(highest, cur_mx);

    cout << highest - lowest << endl;
  }

  return 0;
}
