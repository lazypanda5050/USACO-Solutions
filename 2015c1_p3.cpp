#include <bits/stdc++.h>
#define vi vector<int>
#define pii pair<int, int>
using namespace std;

int main(){
    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);
    int n, q;
    cin >> n >> q;

    vector<vi> pfx(3, vi(n+1, 0));

    int t;
    for (int i = 1; i <= n; i++){
        cin >> t;
        t--;
        pfx[0][i] = pfx[0][i-1];
        pfx[1][i] = pfx[1][i-1];
        pfx[2][i] = pfx[2][i-1];

        pfx[t][i] += 1;
    }

    int a,b;
    while (q--){
        cin >> a >> b;
        cout << pfx[0][b] - pfx[0][a-1] << ' ' << pfx[1][b] - pfx[1][a-1] << ' ' << pfx[2][b] - pfx[2][a-1] << '\n';
    }
}