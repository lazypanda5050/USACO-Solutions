#include <bits/stdc++.h>
using namespace std;

const int maxA = 5 * 1e6;
int minTurns[maxA] = {0,1};
bool composite[maxA] = {false};
int maxMod4[4] = {2,1,2,3};

int main(){
  for (int i = 2; i < maxA; i++){
    if (!composite[i]){
      for (int j = i; j < maxA; j+= i){
        composite[j] = true;
      }
      maxMod4[i%4] = i;
    }
    minTurns[i] = (i - maxMod4[i%4])/2+1;
  }

  int T; cin >> T;
  while (T--){
    int n; cin >> n;
    int ans = maxA;
    for (int i = 0; i < n; i++){
      int ai; cin >> ai;
      if (minTurns[ai] / 2 < ans / 2){
        ans = minTurns[ai];
      }
    }
    if (ans & 1){
      cout << "Farmer John\n";
    }
    else{
      cout << "Farmer Nhoj\n";
    }
  }
}
