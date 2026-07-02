#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> h(n);
  for (int i = 0; i < n; i++) cin >> h[i];

  long long ans = 0;
  // h_j > h_i
  stack<int> s;
  for (int i = n-1; i >= 0; i--){
    while (!s.empty() && h[s.top()] < h[i]){
      s.pop();
    }

    if (!s.empty()){
      ans += s.top()-i+1;
    }
    s.push(i);
  }

  // h_j < h_i
  reverse(h.begin(), h.end());
  stack<int> sr;
  for (int i = n-1; i >= 0; i--){
    while (!sr.empty() && h[sr.top()] < h[i]){
      sr.pop();
    }
    if (!sr.empty()){
      ans += sr.top()-i+1;
    }
    sr.push(i);
  }

  cout << ans << '\n';
}
