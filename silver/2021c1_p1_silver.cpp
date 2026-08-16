#include <bits/stdc++.h>
using namespace std;

int main(){
  int k,m,n;
  cin >> k >> m >> n;
  vector<pair<int, int>> patches(k+m);
  for (int i = 0; i < k; i++){
    cin >> patches[i].first >> patches[i].second;
  }

  for (int i = 0; i < m; i++){
    cin >> patches[i+k].first;
    patches[i+k].second = -1; // mark as a nhoj cow
  }
  sort(patches.begin(), patches.end());

  vector<long long> candidates;
  long long rangeSum = 0;
  int last = -1;

  for (int i = 0; i < patches.size(); i++){
    if (patches[i].second == -1){
      if (last == -1){
        // leftmost interval
        candidates.push_back(rangeSum);
      }
      else{
        long long len = patches[i].first - patches[last].first;

        long long cur = 0, best = 0;
        int r = last;
        for (int j = last + 1; j < i; j++){
          while (r+1 < i && (patches[r+1].first - patches[j].first)*2 < len){
            // increase the sliding window
            r++;
            cur += patches[r].second;
          }
          best = max(best, cur);
          cur -= patches[j].second; // remove the first element from the window
        }

        candidates.push_back(best); // one cow
        candidates.push_back(rangeSum - best); // two cows
      }
      last = i;
      rangeSum = 0;
    }
    else{
      rangeSum += patches[i].second;
    }
  }

  candidates.push_back(rangeSum); // right interval
  sort(candidates.rbegin(), candidates.rend());

  // take the top n
  long long ans = 0;
  for (int i = 0; i < min(n, (int) candidates.size()); i++){
    ans += candidates[i];
  }

  cout << ans << '\n';
}

