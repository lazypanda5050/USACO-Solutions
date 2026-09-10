// use 2 pointers
// Put l and r at index 0
// if current sum > M, ans = min(ans, minimum_el), move left pointer
// if current sum < M, right++
// calculate minimum_el w/ segtree

#include <bits/stdc++.h>
using namespace std;

class SegTree{
private:
    long long n;
    vector<long long> a; // array
    vector<long long> tree;
public:
    SegTree(vector<long long> arr, long long size){
        a = arr;
        n = size;
        tree.resize(4*n);
        build(1, 0, n-1);
    }

    void build(long long cur, long long l, long long r) {
        if (l == r) {
            tree[cur] = a[l]; // base case, leaf node
        }
        else {
            long long m = (l + r) / 2;
            build(cur*2, l, m);
            build(cur*2+1, m+1, r);
            tree[cur] = max(tree[cur*2],tree[cur*2+1]);
        }
    }

    long long query(long long cur, long long ql, long long qr, long long l, long long r) {
        if (l == ql && r == qr) {
            return tree[cur];
        }

        long long m = (l + r) / 2;

        if (qr <= m) {
            // entirely in left child
            return query(cur * 2, ql, qr, l, m);
        }
        else if (ql > m) {
            // entirely in right child
            return query(cur * 2 + 1, ql, qr, m + 1, r);
        }
        else {
            // split across both children
            long long left = query(cur * 2, ql, m, l, m);
            long long right = query(cur * 2 + 1, m + 1, qr, m + 1, r);
            return max(left, right);
        }
    }
};

int main(){
    freopen("hayfeast.in", "r", stdin);
    freopen("hayfeast.out", "w", stdout);
    
    long long n,m;
    cin >> n >> m;
    vector<long long> f(n);
    vector<long long> s(n);

    for (long long i = 0; i < n; i++){
        cin >> f[i] >> s[i];
    }

    SegTree seg = SegTree(s, n);

    long long l = 0;
    long long ans = LLONG_MAX;
    long long curSum = 0;

    for (long long r = 0; r < n; r++) {
        curSum += f[r];
        
        while (curSum >= m && l <= r) {
            ans = min(ans, seg.query(1, l, r, 0, n-1));
            
            // Remove the left element and shrink
            curSum -= f[l];
            l++;
        }
    }

    cout << ans << '\n';
}