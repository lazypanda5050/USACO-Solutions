#include <bits/stdc++.h>
using namespace std;

struct Cow {
  int weight;
  int pos;
  int speed;
};

int main() {
  ifstream read("meetings.in");

  int cow_num;
  int barn_pos;
  read >> cow_num >> barn_pos;

  vector<Cow> cows(cow_num);
  int total_weight = 0;
  for (Cow &c : cows) {
    read >> c.weight >> c.pos >> c.speed;
    total_weight += c.weight;
  }

  sort(cows.begin(), cows.end(),
      [](const Cow &c1, const Cow &c2) { return c1.pos < c2.pos; });

  vector<Cow> left;
  vector<Cow> right;
  for (const Cow &c : cows) {
    if (c.speed == -1) {
      left.push_back(c);
    } else if (c.speed == 1) {
      right.push_back(c);
    }
  }

  vector<pair<int, int>> weight_times;
  for (int c = 0; c < left.size(); c++) {
    weight_times.push_back({left[c].pos, cows[c].weight});
  }
  for (int c = 0; c < right.size(); c++) {
    weight_times.push_back({barn_pos - right[c].pos, cows[left.size() + c].weight});
  }

  sort(weight_times.begin(), weight_times.end(),
      [](const pair<int, int> &a, const pair<int, int> &b) {
      return a.first < b.first;
      });

  int endTime = -1;
  for (const auto &[time, weight] : weight_times) {
    total_weight -= 2 * weight;
    if (total_weight <= 0) {
      endTime = time;
      break;
    }
  }

  int meeting_num = 0;
  queue<int> leftSide;
  for (int c = 0; c < cow_num; c++) {
    if (cows[c].speed == 1) {
      leftSide.push(cows[c].pos);
    } else if (cows[c].speed == -1) {
      while (!leftSide.empty() && leftSide.front() + 2 * endTime < cows[c].pos) {
        leftSide.pop();
      }
      meeting_num += leftSide.size();
    }
  }

  ofstream("meetings.out") << meeting_num << endl;
}
