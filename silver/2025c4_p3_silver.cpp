#include <algorithm>
#include <iostream>
#include <vector>
 
using namespace std;
 
int main() {
    int N; 
    cin >> N;
    int p[N], d[N], e[N];
 
    for (int i = 1; i < N; i++) {
        cin >> p[i] >> d[i] >> e[i];
        p[i]--;
    }
 
    long long E[N];
    E[0] = 0;
    for (int i = 1; i < N; i++) {
        E[i] = E[p[i]] + e[i];
    }
 
    vector<int> difficulties[N], top_11[N];
    // pad with -1s, so that paths with k < 11 weights will
    // have their remaining 11-k elements filled with -1
    difficulties[0] = vector<int>(11, -1);
    top_11[0] = vector<int>(11, -1);
    for (int i = 1; i < N; i++) {
        difficulties[i] = difficulties[p[i]];
        difficulties[i].push_back(d[i]);
        top_11[i] = difficulties[i];
        sort(top_11[i].begin(), top_11[i].end(), greater<int>());
        top_11[i].resize(11);
    }
 
    int M;
    cin >> M;
 
    for (int i = 0; i < M; i++) {
        int S, C;
        cin >> S >> C;
        long long ans = 0;
        for (int j = 0; j < N; j++) {
            if (top_11[j][C] <= S) {
                ans = max(ans, E[j]);
            }
        }
        cout << ans << "\n";
    }
}
