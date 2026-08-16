#include <bits/stdc++.h>
using namespace std;

int cur;

struct Point{
  int x,y,segId;
  bool operator<(const Point& other){
    return x == other.x ? y < other.y : x < other.x;
  }
};

struct Segment{
  int x1,y1,x2,y2;
  int idx;
};

int sign(int x){
  if (x == 0){
    return 0;
  }
  else{
    return x < 0 ? -1 : +1;
  }
}

double coordinate(Segment a){
  if (a.x1 == a.x2){
    return a.y1;
  }
  return a.y1 + (a.y2 - a.y1) * (cur - a.x1) / (a.x2 - a.x1);
}

int operator*(Point a, Point b){
  return sign(a.x*b.y - a.y*b.x);
}

Point operator-(Point a, Point b){
  Point p = {a.x-b.x, a.y-b.y};
  return p;
}

bool operator<(Segment a, Segment b){
  return a.idx != b.idx && coordinate(a) <= coordinate(b);
}

bool operator==(Segment a, Segment b){
  return a.idx == b.idx;
}



bool intersect(Segment a, Segment b){
  Point p1 = {a.x1, a.y1};
  Point q1 = {a.x2, a.y2};
  Point p2 = {b.x1, b.y1};
  Point q2 = {b.x2, b.y2};

  return ((q2 - p1) * (q1 - p1)) * ((q1 - p1) * (p2 - p1)) >= 0 &&
	       ((q1 - p2) * (q2 - p2)) * ((q2 - p2) * (p1 - p2)) >= 0;
}

long long orientation(Point a, Point b, Point c) {
	return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

int main(){
  freopen("cowjump.in", "r", stdin);
  freopen("cowjump.out", "w", stdout);

  int n;
  cin >> n;
  vector<Segment> segments;
  vector<Point> events;
  for (int i = 0; i < n; i++){
    int x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    segments.push_back({x1,y1,x2,y2,i});
    events.push_back({x1,y1,i});
    events.push_back({x2,y2,i});
  }

  sort(events.begin(), events.end());

  set<Segment> active;
  int first, second;
  for (int i = 0; i < 2*n; i++){
    first = events[i].segId;
    cur = events[i].x;

    auto it = active.find(segments[first]);

    if (it != active.end()){
      auto after = next(it), before = it;
      if (before != active.begin() && after != active.end()){
        before--;
        if (intersect(segments[before->idx], segments[after->idx])){
          first = before->idx;
          second = after->idx;
        }
      }
    }
    else{
      it = active.lower_bound(segments[first]);

      if (it != active.end() && intersect(segments[first], *it)){
        second = it->idx;
        break;
      }

      if (it != active.begin()){
        it--;
        if (intersect(segments[it->idx], segments[first])){
          second = it->idx;
          break;
        }
      }
      active.insert(segments[first]);
    }
  }

  if (first > second){
    swap(first,second);
  }

  int ans = 0;
  for (int i = 0; i < n; i++){
    if (i != second && intersect(segments[i], segments[second])){
      ans++;
    }
  }

  cout << (ans > 1 ? second + 1 : first + 1) << '\n';
}
