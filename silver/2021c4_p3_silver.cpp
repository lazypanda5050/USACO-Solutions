#include <bits/stdc++.h>
using namespace std;

bool check(long long h,const vector<long long>& c,long long k, long long l){
  long long total = k*l;
  long long s = 0;
  for (long long i = 0; i < c.size(); i++){
    // get the index of the top h papers
    if (c[i] <= h){
      s = i;
      break;
    }
  }

  for (long long i = 0; i < h-s; i++){
    // increase each paper
    long long dif = h-c[i+s];
    if (dif > k){
      return false;
    }

    total -= dif;
    if (total < 0){
      return false;
    }
  }

  return true;
}

int main(){
  long long n,k,l;
  cin >> n >> k >> l;

  vector<long long> c(n);
  for (long long i = 0; i < n; i++){
    cin >> c[i];
  }

  sort(c.rbegin(),c.rend());

  long long lo = 0, hi = n;
  while (lo <= hi){
    long long mid = (lo+hi) / 2;
    if (check(mid,c,k,l)){
      lo = mid+1;
    }
    else{
      hi = mid-1;
    }
  }

  cout << min(lo,hi) << '\n';
}
