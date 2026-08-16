#include <bits/stdc++.h>
using namespace std;

int main(){
  freopen("haybales.in", "r", stdin);
  freopen("haybales.out", "w", stdout);
  int n,q;
  cin >> n >> q;
  vector<int> nums(n);
  for (int i = 0; i < n; i++){
    cin >> nums[i];
  }

  sort(nums.begin(), nums.end());

  for (int i = 0; i < q; i++){
    int a,b;
    cin >> a >> b;
    
    auto l = lower_bound(nums.begin(), nums.end(), a);
    auto r = upper_bound(nums.begin(), nums.end(), b);

    cout << r-l << '\n';
  }
}
