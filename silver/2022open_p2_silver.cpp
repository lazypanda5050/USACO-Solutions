#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  string t;
  cin >> s >> t;
  vector<int> counts(18), countt(18);
  vector<vector<int>> pairss(18,vector<int>(18)), pairst(18,vector<int>(18));
  for (int i = 0; i < s.length(); i++){
    int cur = s[i] - 'a';
    for (int j = 0; j < 18; j++){
      pairss[cur][j] += counts[j];
    }
    counts[cur]++;
  }
  
  for (int i = 0; i < t.length(); i++){
    int cur = t[i] - 'a';
    for (int j = 0; j < 18; j++){
      pairst[cur][j] += countt[j];
    }
    countt[cur]++;
  }

  int q;
  cin >> q;
  while (q--){
    string query;
    cin >> query;

    bool works = true;
    for (int i = 0; i < query.length(); i++){
      for (int j = i; j < query.length(); j++){
        char c1 = query[i] - 'a', c2 = query[j] - 'a';
        if ((pairss[c1][c2] != pairst[c1][c2]) || (pairss[c2][c1] != pairst[c2][c1])){
          works = false;
          goto exitLoop;
        }
      }
    }
exitLoop:

    cout << ((works) ? 'Y' : 'N');
  }
  cout << '\n';
}
