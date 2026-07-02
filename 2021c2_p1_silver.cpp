#include <bits/stdc++.h>
using namespace std;

class DSU{
  private:
    vector<int> parent;
    vector<int> size;
 
  public:
    DSU(int n) : parent(n), size(n, 1) {
      for (int i = 0; i < n; i++){
        parent[i] = i;
      }
    }
 
    int find(int x){
      return parent[x] == x ? x : (parent[x] = find(parent[x]));
    }
 
    bool unite(int x, int y){
      int rootX = find(x);
      int rootY = find(y);
      if (rootX == rootY){
        return false;
      }
 
      if (size[rootX] < size[rootY]){
        swap(rootX, rootY);
      }
      size[rootX] += size[rootY];
      parent[rootY] = rootX;
      return true;
    }
 
    bool connected(int x, int y){
      return find(x) == find(y);
    }
};

int main(){
  int n,k;
  cin >> n >> k;
  vector<int> suc(n);
  vector<unordered_set<int>> visited(n);
  vector<unordered_set<int>> blobs(n);
  for (int i = 0; i < n; i++){
    suc[i] = i;
    visited[i].insert(i);
  }

  for (int i = 0; i < k; i++){
    int a,b;
    cin >> a >> b;
    a--,b--;

    visited[suc[a]].insert(b);
    visited[suc[b]].insert(a);
    swap(suc[a], suc[b]);
  }

  DSU dsu(n);

  for (int i = 0; i < n; i++){
    dsu.unite(i, suc[i]);
  }
  for (int i = 0; i < n; i++){
    for (int t : visited[i]){
      blobs[dsu.find(i)].insert(t);
    }
  }

  for (int i = 0; i < n; i++){
    cout << blobs[dsu.find(i)].size() << '\n';
  }
}
