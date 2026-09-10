#include <bits/stdc++.h>
using namespace std;

int main(){
  freopen("herding.in", "r", stdin);
  freopen("herding.out", "w", stdout);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }

  sort(a.begin(), a.end());

  int ansMin = INT_MAX;
  if (a[n-2] - a[0] == n-2 && a[n-1] - a[n-2] > 2){
    ansMin = 2;
  }
  else if (a[n-1] - a[1] == n-2 && a[1] - a[0] > 2){
    ansMin = 2;
  }
  else{
    int farthest = 0;
    for (int i = 0; i < n; i++){
      while (farthest + 1 < n && a[farthest+1] - a[i] < n){
        farthest++;
      }
      ansMin = min(ansMin, n - (farthest - i + 1));
    }
  }

  int gap = 0;
  for (int i = 1; i < n; i++){
    gap += a[i] - a[i-1] - 1;
  }

  int ansMax = max(gap - (a[1] - a[0] - 1), gap - (a[n-1] - a[n-2] - 1));

  cout << ansMin << '\n' << ansMax << '\n';
}
