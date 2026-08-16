#include <bits/stdc++.h>
using namespace std;

int main(){
  int T;
  cin >> T;
  while (T--){
    int n,m,k;
    cin >> n >> m >> k;

    vector<int> even(m);
    vector<int> odd(m);
    vector<int> needed(m+1);
    vector<int> amount(m+1);
    needed[m] = 1;
    amount[0] = n;

    for (int i = 0; i < m; i++){
      // i represents the row
      int row[4] = {-1,-1,-1,-1};
      int maxEven = -1;
      int minEven = INT_MAX;
      int maxOdd = -1;
      int minOdd = INT_MAX;
      for (int j = 0; j < k; j++){
        cin >> row[j];
        if (row[j] % 2 == 0){
          maxEven = max(maxEven, row[j]);
          minEven = min(minEven, row[j]);
        }
        else{
          maxOdd = max(maxOdd, row[j]);
          minOdd = min(minOdd, row[j]);
        }
      }

      if (maxEven == -1){
        // all odd numbers
        even[i] = -maxOdd;
        odd[i] = minOdd;
      }
      else if (maxOdd == -1){
        // all even numbers
        odd[i] = -maxEven;
        even[i] = minEven;
      }
      else{
        // mix
        even[i] = -maxOdd;
        odd[i] = -maxEven;
      }
    }

    for (int i = m-1; i >= 0; i--){
      needed[i] = max(1, needed[i+1]-max(even[i],odd[i]));
    }

    if (n < needed[0]){
      cout << -1 << '\n';
      continue;
    }

    for (int i = 1; i <= m; i++){
      int row = i-1;
      if (amount[i-1] + even[row] >= needed[i]){ 
        // take even
        cout << "Even";
        amount[i] = amount[i-1] + even[row];
        if (i != m){
          cout << ' ';
        }
      }
      else{
        // take odd
        cout << "Odd";
        amount[i] = amount[i-1] + odd[row];
        if (i != m){
          cout << ' ';
        }
      }
    }

    cout << '\n';
  }
}
