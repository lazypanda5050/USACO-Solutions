#include <bits/stdc++.h>
using namespace std;

int main(){
  freopen("moobuzz.in", "r", stdin);
  freopen("moobuzz.out", "w", stdout);

  // every 15 numbers there are 8 numbers
  int n;
  cin >> n;

  int first8[8] = {14,1,2,4,7,8,11,13}; // 14 is first because 8 % 8 = 0

  int ans = (n-1) / 8; // which group its in
  ans *= 15; // distance from first 8
  ans += first8[n%8]; // add the element

  cout << ans << '\n';
}
