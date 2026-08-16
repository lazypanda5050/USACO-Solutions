#include <bits/stdc++.h>
using namespace std;

int main(){
  freopen("shuffle.in", "r", stdin);
  freopen("shuffle.out", "w", stdout);

  long long n;
  cin >> n;
  vector<long long> shuffle(n);
  vector<long long> afterShuffle(n);
  for (int i = 0; i < n; i++){
    cin >> shuffle[i];
    shuffle[i]--;
    afterShuffle[shuffle[i]]++;
  }

  long long ans = n;
  queue<long long> emptySpots;

  for (int i = 0; i < n; i++){
    if (afterShuffle[i] == 0){
      emptySpots.push(i);
      ans--;
    }
  }

  while (!emptySpots.empty()){
    long long cur = emptySpots.front(); emptySpots.pop();

    if (--afterShuffle[shuffle[cur]] == 0){
      emptySpots.push(shuffle[cur]);
      ans--;
    }
  }

  cout << ans << '\n';
}
