/*
   sweep line
   EOI
   Type 0 = Tree
   Type 1 = Interval

   Events:
   Type Start End Limit
   0    1
   0    2
   0    4
   0    6
   0    7
   0    8
   0    10

   1    2     9      3
   1    1     10     1

   Sorted:

   1 1 10 1
   0 1
   1 2 9 3
   0 2
   0 4
   0 6
   0 7
   0 8
   0 10

   Note: inrange means number of trees in interval

   Event 1:
   ans = 0
   pq = {{inrange-1+ans=6, 10}}

   Event 2:
   0 < 6 can cut
   ans = 1

   Event 3:
   ans = 1
   pq = {{inrange-3+ans = 3, 9}, {6, 10}}

   Event 4:
   1 < 3 can cut
   ans = 2

   Event 5:
   2 < 3 can cut
   ans = 3

   Event 6:
   3 < 3 cant cut
   ans = 3

   Event 7:
   3 < 3 cant cut
   ans = 3

   Event 8:
   3 < 3 cant cut
   ans = 3

   Event 9:
   10 > 9 pop pq
   pq = {{6, 10}}
   3 < 6 can cut
   ans = 4
   */

#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Event{
  ll type, start, end, limit, inrange;

  Event(ll type, ll start, ll end = -1, ll limit = -1, ll inrange = -1) :
    type(type), start(start), end(end), limit(limit), inrange(inrange) {}
};

void countFrequencies(vector<Event>& intervals, const vector<Event>& trees) {
  vector<Event> sortedTrees = trees;
  sort(sortedTrees.begin(), sortedTrees.end(), [](Event a, Event b){
      return a.start < b.start;
      });

  for (Event& interval : intervals) {
    auto left = lower_bound(sortedTrees.begin(), sortedTrees.end(), interval.start, [](const Event& a, int value){
        return a.start < value;
        });

    auto right = upper_bound(sortedTrees.begin(), sortedTrees.end(), interval.end, [](ll value, const Event& a){
        return value < a.start;
        });

    interval.inrange = distance(left, right);
  }
}

int main(){
  //cin.tie(0)->sync_with_stdio(false);
  //freopen("input.in", "r", stdin);
  //freopen("output.out", "w", stdout);
  ll T;
  cin >> T;
  while (T--){
    ll n, k;
    cin >> n >> k;

    vector<Event> trees;
    vector<Event> intervals;
    vector<ll> frequencies(k, 0); // how many trees are in each interval

    vector<Event> events;

    for (ll i = 0; i < n; i++){
      ll a;
      cin >> a;
      trees.push_back(Event(0, a));
    }

    for (ll i = 0; i < k; i++){
      ll a,b,c;
      cin >> a >> b >> c;
      intervals.push_back(Event(1,a,b,c,0));
    }

    countFrequencies(intervals, trees);

    for (ll i = 0; i < n; i++){
      events.push_back(trees[i]);
    }
    for (ll i = 0; i < k; i++){
      events.push_back(intervals[i]);
    }

    sort(events.begin(), events.end(), [](Event a, Event b){
        if (a.start == b.start){
        return a.type > b.type;
        }

        return a.start < b.start;
        });

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    ll ans = 0;

    for (Event event : events){
      if (event.type == 0){
        while (!pq.empty() && event.start > pq.top().second){
          pq.pop();
        }
        if (pq.empty() || ans < pq.top().first){
          ans++;
        }
      }
      else{
        // event.type == 1
        pq.push({event.inrange-event.limit+ans, event.end});
      }
    }

    cout << ans << endl;
  }
}
