#include <bits/stdc++.h>
using namespace std;

int main(){
  long long n,m;
  cin >> n >> m;

  vector<long long> startCnt(m+1);
  vector<long long> endCnt(m+1);
  for (long long i = 0; i < n; i++){
    long long a,b;
    cin >> a >> b;
    startCnt[a]++;
    endCnt[b]++;
  }

  vector<long long> pfx(2*m+1);
  for (long long i = 0; i <= m; i++){
    for (long long j = 0; j <= m; j++){
      pfx[i+j] += startCnt[i]*startCnt[j];
      pfx[i+j+1] -= endCnt[i]*endCnt[j];
    }
  }

  long long cur = 0;
  for (long long i = 0; i <= 2*m; i++){
    cur += pfx[i];
    pfx[i] = cur;
  }

  for (long long i = 0; i <= 2*m; i++){
    cout << pfx[i] << '\n';
  }
}
