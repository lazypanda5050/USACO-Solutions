#include <bits/stdc++.h>
using namespace std;

vector<vector<bool>> connected;
vector<bool> visited;

int reachableCows(int c) {
	visited[c] = true;
	// we can always reach the initial cow c
	int reached = 1;
	for (int nc = 0; nc < connected.size(); nc++) {
		// make sure we can connect to this cow & it hasn't been reached yet
		if (!visited[nc] && connected[c][nc]) {
			visited[nc] = true;
			reached += reachableCows(nc);
		}
	}
	return reached;
}

int main() {
	freopen("moocast.in", "r", stdin);
	freopen("moocast.out", "w", stdout);

	int n;
	cin >> n;
	vector<int> x(n), y(n);
	vector<int> power(n);
	for (int c = 0; c < n; c++) { cin >> x[c] >> y[c] >> power[c]; }

	connected = vector<vector<bool>>(n, vector<bool>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int distSquared =
			    ((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
			connected[i][j] = distSquared <= power[i] * power[i];
		}
	}

	int ans = 0;
	for (int c = 0; c < n; c++) {
		visited.assign(n, false);
		ans = max(ans, reachableCows(c));
	}

	cout << ans << endl;
}
