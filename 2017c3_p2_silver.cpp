#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("maxcross.in", "r", stdin);
    //freopen("maxcross.out", "w", stdout);
    // make vector of length N
    // sliding window of length K
    // find minimum number of broken signals
    int n,k,b;
    cin >> n >> k >> b;
    vector<int> v(n, 0);
    for (int i = 0; i < b; i++){
        int x;
        cin >> x;
        v[x-1] = 1;
    }
    //for (int i= 0; i < n; i++){
    //    cout << v[i] << " ";
    //}
    //cout << endl;
    int cur = 0;
    int ans = INT_MAX;
    // first window
    for (int i = 0; i < k; i++){
        cur += v[i];
    }
    //cout << cur << endl;
    ans = min(ans, cur);

    // start from second
    for (int i = 1; i < n-k+1; i++){
        // remove first element and add new element
        cur = cur - v[i-1] + v[i+k-1];
        //cout << cur << endl;
        ans = min(ans, cur);
    }

    cout << ans << endl;
}