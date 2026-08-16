/*
 * You can rearrange the string so only the frequencies matter
 * if c+w and c+o are odd, then its valid, otherwise invalid
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  int n = s.size();

  vector<int> c(n+1,0);
  vector<int> o(n+1,0);
  vector<int> w(n+1,0);

  for (int i = 1; i <= n; i++){
    char l = s[i-1];
    c[i] = c[i-1];
    o[i] = o[i-1];
    w[i] = w[i-1];
    if (l == 'C'){
      c[i]++;
    }
    else if (l == 'O'){
      o[i]++;
    }
    else{
      w[i]++;
    }
  }

  int q;
  cin >> q;
  for (int i = 0; i < q; i++){
    int a,b;
    cin >> a >> b;
    int C = c[b]-c[a-1];
    int O = o[b]-o[a-1];
    int W = w[b]-w[a-1];
    // cout << C << O << W << '\n';
    if ((C+O) % 2 == 1 && (C+W) % 2 == 1){
      cout << 'Y';
    }
    else{
      cout << 'N';
    }
  }

  cout << '\n';
}
