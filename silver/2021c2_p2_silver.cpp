#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,q;
  cin >> n >> q;
  string fence;
  cin >> fence;

  vector<int> pref(n+1);

  stack<char> active;
  for (int i = 0; i < n; i++){
    pref[i+1] = pref[i];
    while (!active.empty() && active.top() > fence[i]){
      active.pop();
    }
    if (active.empty() || active.top() < fence[i]){
      active.push(fence[i]);
      pref[i+1]++;
    }
  }

  stack<char> empty;
  active.swap(empty); // efficient way to clear the stack

  vector<int> suff(n+1);
  reverse(fence.begin(), fence.end());

  for (int i = 0; i < n; i++){
    suff[i+1] = suff[i];
    while (!active.empty() && active.top() > fence[i]){
      active.pop();
    }
    if (active.empty() || active.top() < fence[i]){
      active.push(fence[i]);
      suff[i+1]++;
    }
  }

  for (int i = 0; i < q; i++){
    int a,b;
    cin >> a >> b;
    cout << pref[a-1] + suff[n-b] << '\n';
  }
}
