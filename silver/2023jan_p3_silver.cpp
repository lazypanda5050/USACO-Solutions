#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }

  a.push_back(0);

  string ans = "";
  int i = 0;
  while (!(i == 0 && a[i] == 0)){
    while (a[i] > 0){
      ans += "R";
      a[i] -= 1;
      i++;
    }
    while (i > 0 && (a[i-1] > 1 || a[i] == 0)){
      ans += "L";
      i--;
      a[i]--;
    }
  }

  cout << ans << '\n';
}
