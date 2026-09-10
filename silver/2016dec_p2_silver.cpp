#include <bits/stdc++.h>
using namespace std;

int main(){
  freopen("citystate.in", "r", stdin);
  freopen("citystate.out", "w", stdout);
  int n;
  cin >> n;

  vector<pair<string, string>> pairs;

  for (int i = 0; i < n; i++){
    string city,state;
    cin >> city >> state;
    city = city.substr(0,2);
    pairs.push_back({city,state});
  }

  unordered_map<string, int> seen;
  long long total = 0;
  for (const auto& [c,s] : pairs){
    if (c != s){
      total += seen[s+c];
    }
    seen[c+s]++;
  }

  cout << total << '\n';
}
