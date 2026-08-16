#include <bits/stdc++.h>
using namespace std;

int main() {
	int cow_num;
	cin >> cow_num;

	set<int> seen_x, seen_y;
	vector<pair<int, int>> cows(cow_num);
	for (pair<int, int>& c : cows) {
		cin >> c.first >> c.second;
		seen_x.insert(c.first);
		seen_y.insert(c.second);
	}

	// coordinate compression
	sort(cows.begin(), cows.end());  // sort by x
	map<int, int> reduced_x;
	for (int c = 0; c < cow_num; c++) {
    reduced_x[cows[c].first] = c;
  }

	auto cmp = [&](const pair<int, int>& c1, const pair<int, int>& c2) {
      return c1.second < c2.second;
		};

	sort(cows.begin(), cows.end(), cmp);  // sort by y
	map<int, int> reduced_y;
	for (int c = 0; c < cow_num; c++) {
    reduced_y[cows[c].second] = c;
  }

	for (auto& [x, y] : cows) {
		x = reduced_x[x];
		y = reduced_y[y];
	}

	sort(cows.begin(), cows.end());

	vector<vector<int>> lt_y(cow_num, vector<int>(cow_num + 1)); // less than y-value
	vector<vector<int>> gt_y(cow_num, vector<int>(cow_num + 1)); // greater than y value
	for (int c = 0; c < cow_num; c++) {
		int curr_y = cows[c].second;
		for (int x = 1; x <= cow_num; x++) {
			lt_y[curr_y][x] = (lt_y[curr_y][x - 1] + (cows[x - 1].second < curr_y));
			gt_y[curr_y][x] = (gt_y[curr_y][x - 1] + (cows[x - 1].second > curr_y));
		}
	}

	long long total = 0;
	for (int c1 = 0; c1 < cow_num; c1++) {
		for (int c2 = c1 + 1; c2 < cow_num; c2++) {
			int bottom = min(cows[c1].second, cows[c2].second);
			int top = max(cows[c1].second, cows[c2].second);

			int bottom_total = 1 + lt_y[bottom][c2 + 1] - lt_y[bottom][c1];
			int top_total = 1 + gt_y[top][c2 + 1] - gt_y[top][c1];
			total += (long long)bottom_total * top_total;
		}
	}

	total += cow_num + 1;

	cout << total << endl;
}
