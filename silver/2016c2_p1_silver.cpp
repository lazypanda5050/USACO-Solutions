#include <bits/stdc++.h>
using namespace std;

long long n,k;

bool check(long long r, const vector<long long>& cows){
  // check if you can clear the scene with K deletions of length 2*R+1
  // O(n) check function works

  long long cur = 0; // index of the leftmost bale
  long long used = 0;
  while (cur < n){
    used++;
    long long start = cows[cur];
    long long end = start+(2*r);
    while (cur < n && cows[cur] <= end){
      cur++;
    }

    if (used > k){
      return false;
    }
  }

  return true;
}

int main(){
  freopen("angry.in", "r", stdin);
  freopen("angry.out", "w", stdout);
  cin >> n >> k;
  vector<long long> cows(n);
  for (long long i = 0; i < n; i++){
    cin >> cows[i];
  }

  sort(cows.begin(), cows.end());

  long long l = 0;
  long long r = 500000000; // half of the upper bound of range

  while (l < r){
    long long mid = l+(r-l)/2;

    if (check(mid, cows)){
      r = mid;
    }
    else{
      l = mid+1;
    }
  }

  cout << l << '\n';
}
