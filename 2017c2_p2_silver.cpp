#include <bits/stdc++.h>
using namespace std;

int main(){
  freopen("hps.in", "r", stdin);
  freopen("hps.out", "w", stdout);

  int n;
  cin >> n;

  vector<char> moves(n);
  for (int i = 0; i < n; i++){
    cin >> moves[i];
  }

  vector<int> hp(n+1,0);
  vector<int> pp(n+1,0);
  vector<int> sp(n+1,0);
  for (int i = 1; i <= n; i++){
    char c = moves[i-1];
    hp[i] = hp[i-1];
    pp[i] = pp[i-1];
    sp[i] = sp[i-1];
    if (c == 'H'){
      hp[i]++;
    }
    else if (c == 'P'){
      pp[i]++;
    }
    else{
      sp[i]++;
    }
  }
  
  vector<int> hs(n+1,0);
  vector<int> ps(n+1,0);
  vector<int> ss(n+1,0);
  for (int i = n-1; i>=0; i--){
    hs[i]=hs[i+1];
    ps[i]=ps[i+1];
    ss[i]=ss[i+1];
    char c = moves[i];
    if (c == 'H'){
      hs[i]++;
    }
    else if (c == 'P'){
      ps[i]++;
    }
    else{
      ss[i]++;
    }
  }
  
  // for (int i = 0; i <= n; i++){
  //  cout << hs[i] << ' ' << ps[i] << ' ' << ss[i] << "\n";
  // }

  int ans = -1;
  for (int x = 0; x <= n; x++){
    int pref = max(hp[x],max(pp[x],sp[x]));
    int suf = max(hs[x],max(ps[x],ss[x]));

    ans = max(ans,pref+suf);
  }

  cout << ans << '\n';
}
