#include <bits/stdc++.h>
using namespace std;

int main(){
  freopen("berries.in", "r", stdin);
  freopen("berries.out", "w", stdout);
  int n,k;
  cin >> n >> k;

  vector<int> B(n);
  int maxB = -1;
  for (int i = 0; i < n; i++){
    cin >> B[i];
    maxB = max(maxB, B[i]);
  }

  int ans = -1;
  for (int tar = 1; tar <= maxB; tar++){
    int full = 0;
    for (int i = 0; i < n; i++){
      full += B[i] / tar;
    }

    if (full < (k/2)){
      // not optimal
      continue;
    }

    if (full >= k){
      ans = max(ans, (k/2)*tar);
      continue;
    }

    int bessieLeft = (k/2)-(full - k/2);
    int curBessie = (full - k/2)*tar;

    vector<int> remaining;
    for (int i = 0; i < n; i++){
      remaining.push_back(B[i]%tar);
    }
    
    sort(remaining.rbegin(), remaining.rend());

    for (int i = 0; i < bessieLeft && i < remaining.size(); i++){
      curBessie += remaining[i];
    }

    ans = max(ans, curBessie);
  }

  cout << ans << '\n';
}
