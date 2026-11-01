#include <bits/stdc++.h>
using namespace std;

struct Block {
    int start;
    int end;
    int value;
};

vector<int> solve(const vector<int>& a) {
  vector<int> ret;
  int maximum = 0;
  for (int i = a.size() - 1; i >= 0; --i) {
    if (a[i] >= maximum) {
      maximum = a[i];
      ret.push_back(a[i]);
    }
  }
  reverse(ret.begin(), ret.end());
  return ret;
}

int main(){
  cin.tie(0)->sync_with_stdio(false);

  int T;
  cin >> T;
  while (T--){
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> lastPos(n + 1, -1);
    for (int i = 0; i < n; i++){
      cin >> a[i];
      lastPos[a[i]] = i;
    }

    vector<int> suffixMax(n + 1, 0);
    for (int i = n - 1; i >= 0; --i) {
      suffixMax[i] = max(suffixMax[i + 1], a[i]);
    }

    vector<Block> blocks;
    for (int start = 0; start < n; ) {
      int value = suffixMax[start];
      int end = lastPos[value];
      blocks.push_back({start, end, value});
      start = end + 1;
    }

    int chosenStart = -1;
    int chosenEnd = -1;
    for (int bi = 0; bi < (int)blocks.size(); ++bi) {
      const auto [start, end, value] = blocks[bi];
      const int nextMax = (bi + 1 < (int)blocks.size()) ? blocks[bi + 1].value : 0;

      int maxBetween = -1;
      for (int i = end - 1; i >= start; --i) {
        if (a[i] == value){
          break; // previous occurrence of value inside this block
        }
        maxBetween = max(maxBetween, a[i]);
      }

      if (maxBetween >= nextMax) {
        chosenStart = start;
        chosenEnd = end;
        break; // earliest improving block is always optimal
      }
    }

    if (chosenStart != -1) {
      rotate(a.begin() + chosenStart, a.begin() + chosenEnd, a.begin() + chosenEnd + 1);
    }

    const vector<int> b = solve(a);
    for (int i = 0; i < b.size(); ++i) {
      if (i){
        cout << ' ';
      }
      cout << b[i];
    }

    cout << '\n';
  }
}
