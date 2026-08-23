#include <bits/stdc++.h>
using namespace std;

int main(){
  freopen("cereal.in", "r", stdin);
  freopen("cereal.out", "w", stdout);
  int n,m;
  cin >> n >> m;
  vector<int> f(n), s(n), ans(n), whichCow(m);
  for (int i = 0; i < n; i++){
    cin >> f[i] >> s[i];
    f[i]--, s[i]--;
  }

  int count = 0;
  for (int i = n-1; i >= 0; i--){
    int j = i;
    int cur = f[i];
    while (true){
      if (whichCow[cur] == 0){
        // nobody took it
        whichCow[cur] = j;
        count++;
        break;
      }
      else if (whichCow[cur] < j){
        // somebody already took it
        break;
      }
      else{
        // j stole it from k
        int k = whichCow[cur];
        whichCow[cur] = j;
        if (cur == s[k]){
          break;
        }

        j = k;
        cur = s[k];
      }
    }
    ans[i] = count;
  }

  for (int i = 0; i < n; i++){
    cout << ans[i] << '\n';
  }
}
