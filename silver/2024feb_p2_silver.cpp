#include <bits/stdc++.h>
using namespace std;

vector<int> toReducedList(const string& s) {
  vector<int> l;
  for (char ch : s) {
    int c = ch - '0';
    if (!l.empty() && l.back() == c) {
      continue;
    }
    l.push_back(c);
  }
  return l;
}

void solve() {
  int n, p;
  cin >> n >> p;

  vector<vector<int>> tubes(3);
  for (int i = 0; i < 2; ++i) {
    string s;
    cin >> s;
    tubes[i] = toReducedList(s);
  }

  if (tubes[0][0] == tubes[1][0]) {
    tubes[0].insert(tubes[0].begin(), tubes[0][0] ^ 3);
  }

  int ans = tubes[0].size() + tubes[1].size() - 2;
  if (ans > 1) {
    ans += 1;
  }

  cout << ans << "\n";
  if (p == 1) {
    return;
  }

  vector<pair<int, int>> moves;

  auto move = [&](int src, int dst) {
    moves.emplace_back(src, dst);
    if (tubes[dst].empty() || tubes[dst].back() != tubes[src].back()) {
      tubes[dst].push_back(tubes[src].back());
    }
    tubes[src].pop_back();
  };

  if (tubes[0].back() == tubes[1].back()) {
    if (tubes[0].size() > tubes[1].size()) {
      move(0, 1);
    } else {
      move(1, 0);
    }
  }

  for (int i = 0; i < 2; ++i) {
    if (tubes[i].size() > 1) {
      move(i, 2);

      int idxToEmpty = 0;
      if (tubes[idxToEmpty][0] == tubes[2][0]) {
        idxToEmpty ^= 1;
      }
      while (tubes[idxToEmpty].size() > 1) {
        if (tubes[idxToEmpty].back() == tubes[2][0]) {
          move(idxToEmpty, 2);
        } else {
          move(idxToEmpty, idxToEmpty ^ 1);
        }
      }

      idxToEmpty ^= 1;
      while (tubes[idxToEmpty].size() > 1) {
        if (tubes[idxToEmpty].back() == tubes[2][0]) {
          move(idxToEmpty, 2);
        } else {
          move(idxToEmpty, idxToEmpty ^ 1);
        }
      }

      move(2, idxToEmpty); 
      break;
    }
  }

  for (const auto& [a, b] : moves) {
    cout << 1 + a << " " << 1 + b << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int T;
  if (cin >> T) {
    while (T--) {
      solve();
    }
  }
  return 0;
}
