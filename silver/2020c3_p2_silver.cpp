/*
 * When taking input, store in a hashmap<long long, vector<long long>> the y values for each x, and the x values for each y
 * For each set of x-coords, sort them and use prefix sums to get the sum of height for each fence in the set from set[0]
 * Repeat for the y-coords
 *
 * For each fence post,
 * s += (Sum of height)*(sum of width)
*/

#include <bits/stdc++.h>
using namespace std;

const long long coordOffset = 1e4;
const long long MOD = 1e9 + 7;

struct Fence{
  long long x, y;
  long long sHeight; // sum of all heights with this as anchr
  long long sWidth;
};

int main(){
  freopen("triangles.in", "r", stdin);
  freopen("triangles.out", "w", stdout);
  long long n;
  cin >> n;
  vector<Fence> fences(n);
  
  unordered_map<long long, vector<pair<long long, long long>>> xcoords;
  unordered_map<long long, vector<pair<long long, long long>>> ycoords;

  for (long long i = 0; i < n; i++){
    cin >> fences[i].x >> fences[i].y;

    xcoords[fences[i].x + coordOffset].push_back({fences[i].y,i});
    ycoords[fences[i].y + coordOffset].push_back({fences[i].x,i});
  }

  for (auto& [x, vec] : xcoords){
    long long cur = 0;
    sort(vec.begin(), vec.end());

    for (long long i = 1; i < vec.size(); i++){
      cur += vec[i].first - vec[0].first;
    }

    fences[vec[0].second].sHeight = cur;

    for (long long i = 1; i < vec.size(); i++){
      cur += (2*i - vec.size()) * (vec[i].first - vec[i-1].first);
      fences[vec[i].second].sHeight = cur;
    }
  }

  for (auto& [y, vec] : ycoords){
    long long cur = 0;
    sort(vec.begin(), vec.end());

    for (long long i = 1; i < vec.size(); i++){
      cur += vec[i].first - vec[0].first;
    }

    fences[vec[0].second].sWidth = cur;

    for (long long i = 1; i < vec.size(); i++){
      cur += (2*i - vec.size()) * (vec[i].first - vec[i-1].first);
      fences[vec[i].second].sWidth = cur;
    }
  }

  long long ans = 0;

  for (long long i = 0; i < n; i++){
    ans += fences[i].sHeight * fences[i].sWidth % MOD;
    ans %= MOD;
  }

  cout << ans << '\n';
}
