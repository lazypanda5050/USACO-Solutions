#include <bits/stdc++.h>
using namespace std;

long long n;

bool check(const vector<pair<long long, long long>>& grass, long long D){
    long long lastPos = -1e18; 
    long long placed = 0;

    for (const auto& interval : grass) {
        long long start = interval.first;
        long long end = interval.second;

        while (true) {
            long long nextPos = max(lastPos + D, start);

            if (nextPos > end) {
                break;
            }

            lastPos = nextPos;
            placed++;

            if (placed >= n) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    ifstream cin("socdist.in");
    ofstream cout("socdist.out");

    long long m;
    cin >> n >> m;

    vector<pair<long long, long long>> grass(m);
    for (long long i = 0; i < m; i++) {
        cin >> grass[i].first >> grass[i].second;
    }

    sort(grass.begin(), grass.end());

    long long low = 1; 
    long long high = grass.back().second - grass.front().first; 
    long long best_D = -1;

    while (low <= high) {
        long long mid = low + (high - low) / 2;

        if (check(grass, mid)) {
            best_D = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << best_D << "\n";

    return 0;
}