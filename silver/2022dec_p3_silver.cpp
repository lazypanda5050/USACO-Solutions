#include <bits/stdc++.h>
using namespace std;

int ranges[302][302];
int answer[302];
int n;

bool possible(int row) {
    int rolling_mini = 1e9 + 10;
    int rolling_maxi = -1e9 - 10;
    for (int i = 1; i <= n - row + 1; i++) {
        rolling_maxi = max(rolling_maxi, answer[row + i - 1]);
        rolling_mini = min(rolling_mini, answer[row + i - 1]);
        if (rolling_maxi - rolling_mini != ranges[row][i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    cin >> n;
    answer[n] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - i + 1; j++) {
            cin >> ranges[i][j];
        }
    }

    for (int i = n; i >= 1; i--) {
        answer[i] = answer[i + 1] + ranges[i][2];
        if (!possible(i)) {
            answer[i] = answer[i + 1] - ranges[i][2];
        }
    }
    int temp[n + 1];
    for (int i = 0; i < n; i++) {
        temp[i + 1] = answer[i + 1];
    }
    sort(temp, temp + n + 1);
    int addition = -1 * temp[0];
    for (int i = 1; i <= n; i++) {
        cout << answer[i] + addition;
        if (i < n) {
            cout << " ";
        }
    }
    return 0;
}
