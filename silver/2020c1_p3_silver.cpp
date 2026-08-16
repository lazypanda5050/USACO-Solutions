#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> xcoords(n);
  vector<int> ycoords(n);
  vector<int> eastCows;
  vector<int> northCows;

  for (int i = 0; i < n; i++){
    char dir;
    int x,y;
    cin >> dir >> x >> y;
    if (dir == 'E'){
      eastCows.emplace_back(i);
    }
    else{
      northCows.emplace_back(i);
    }
    xcoords[i] = x;
    ycoords[i] = y;
  }

  sort(eastCows.begin(), eastCows.end(), [&](int& a, int& b){
      return ycoords[a] < ycoords[b];
      });
  sort(northCows.begin(), northCows.end(), [&](int&a, int& b){
      return xcoords[a] < xcoords[b];
      });

  vector<bool> stopped(n);
  vector<int> blame(n);

  for (int east : eastCows){
    for (int north : northCows){
      if (!stopped[east] && !stopped[north]
          && xcoords[north] > xcoords[east]
          && ycoords[east] > ycoords[north]){
        // collision
        if (xcoords[north]-xcoords[east] > ycoords[east]-ycoords[north]){
          // north stops east
          stopped[east] = true;
          blame[north]++;
          blame[north] += blame[east]; // gains all the blame by transitivity
        }
        else if (xcoords[north]-xcoords[east] < ycoords[east]-ycoords[north]){
          // east stops north
          stopped[north] = true;
          blame[east]++;
          blame[east] += blame[north];
        }
      }
    }
  }

  for (int b : blame){
    cout << b << '\n';
  }
}
