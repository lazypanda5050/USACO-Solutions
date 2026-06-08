#include <bits/stdc++.h>
using namespace std;

int N;
int litRooms = 1;
const int MAX_N = 100;
bool visited[MAX_N][MAX_N];
bool lit[MAX_N][MAX_N];
vector<pair<int, int>> switches[MAX_N][MAX_N];

int dirX[] = {-1, 0, 1, 0};
int dirY[] = {0, 1, 0, -1};

bool checkConnected(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int newX = x + dirX[i];
		int newY = y + dirY[i];

		if (newX < 0 || newY < 0 || newX > N - 1 || newY > N - 1) {
      continue; 
    }

		if (visited[newX][newY]) { return true; }
	}

	return false;
}

void floodfill(int x, int y) {
	if (x < 0 || y < 0 || x > N - 1 || y > N - 1 || visited[x][y] || !lit[x][y]) {
		return;
	}

	if (!checkConnected(x, y) && !(x == 0 && y == 0)) {
    return;
  }

	visited[x][y] = true;

	for (int i = 0; i < 4; i++) {
    floodfill(x + dirX[i], y + dirY[i])
  }

	for (int i = 0; i < switches[x][y].size(); i++) {
		int roomX = switches[x][y][i].first;
		int roomY = switches[x][y][i].second;

		if (!lit[roomX][roomY]) {
      litRooms++;
    }

		lit[roomX][roomY] = true;

		floodfill(roomX, roomY);
	}
}

int main() {
  freopen("lightson.in", "r", stdin);
  freopen("lightson.out", "w", stdout);
	int m;
	cin >> N >> m;

	for (int i = 0; i < m; i++) {
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		switches[x - 1][y - 1].push_back({a - 1, b - 1});
	}

	lit[0][0] = true;

	floodfill(0, 0);

	cout << litRooms << endl;
}
