#include <bits/stdc++.h>
using namespace std;

class DSU {
private:
	vector<int> parent;
	vector<int> size;

public:
	DSU(int size) : parent(size), size(size, 1) {
		for (int i = 0; i < size; i++) { parent[i] = i; }
	}

	int getRoot(int n) {
    return parent[n] == n ? n : (parent[n] = getRoot(parent[n]));
  }

	bool join(int n1, int n2) {
		n1 = getRoot(n1);
		n2 = getRoot(n2);
		if (n1 == n2) {
      return false;
    }
		if (size[n2] > size[n1]) {
      return join(n2, n1);
    }
		parent[n2] = n1;
		size[n1] += size[n2];
		return true;
	}
};

struct Wormhole{
  int c1,c2;

  int width;
};

bool operator<(const Wormhole& a, const Wormhole& b){
  return a.width < b.width;
}

int main(){
  freopen("wormsort.in", "r", stdin);
  freopen("wormsort.out", "w", stdout);
  int n,m;
  cin >> n >> m;

  vector<int> cows(n);
  for (int i = 0; i < n; i++){
    cin >> cows[i]; cows[i]--;
  }

  vector<Wormhole> wormholes(m);
  for (int i = 0; i < m; i++){
    cin >> wormholes[i].c1 >> wormholes[i].c2 >> wormholes[i].width;
    wormholes[i].c1--;
    wormholes[i].c2--;
  }

  sort(wormholes.begin(), wormholes.end());

  int remaining = m;
  DSU dsu(n);
  for (int i = 0; i < n; i++){
    while (dsu.getRoot(i) != dsu.getRoot(cows[i])){
      // add another wormhole
      remaining--;
      dsu.join(wormholes[remaining].c1, wormholes[remaining].c2);
    }
  }
  int ans;
  if (remaining == m){
    ans = -1;
  }
  else{
    ans = wormholes[remaining].width;
  }
  cout << ans << '\n';
}
