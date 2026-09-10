#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,k;
  cin >> n >> k;
  vector<int> a(k), b(k);
  vector<int> posA(n+1, -1), posB(n+1,-1);
  for (int i = 0; i < k; i++){
    cin >> a[i];
    posA[a[i]] = i;
  }
  for (int i = 0; i < k; i++){
    cin >> b[i];
    posB[b[i]] = i;
  }

  int free = 0;
  for (int i = 1; i <= n; i++){
    if (posA[i] == -1 && posB[i] == -1){
      free++;
    }
  }
  
  vector<int> countf(k,0); // count forward
  vector<int> countb(k,0); // count backwards

  for (int i = 1; i <= n; i++){
    if (posA[i] != -1 && posB[i] != -1){
      int shiftf = (posB[i] - posA[i] + k) % k;
      countf[shiftf]++;
      
      int shiftB = (posB[i] + posA[i]) % k;
      countb[shiftB]++;
    }
  }

  int ans = 0;
  for (int i = 0; i < k; i++){
    ans = max(ans, max(countf[i], countb[i]));
  }

  cout << free + ans << '\n';
}
