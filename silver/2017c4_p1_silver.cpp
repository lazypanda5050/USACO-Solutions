/*
keep map of values : number of cows with that values
keep sorted vector of values
remove min(smallest time, largest time)
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("pairup.in", "r", stdin);
    freopen("pairup.out", "w", stdout);
    int n;
    cin >> n;
    unordered_map<int, int> cows; // milk amount : # of cows
    vector<int> values;

    int x,y;
    for (int i = 0; i < n; i++){
        cin >> x >> y;
        cows[y] = x;
        values.emplace_back(y);
    }

    sort(values.begin(), values.end());

    // pointers to the smallest and largest values
    int smallPointer = 0;
    int bigPointer = n-1;

    int ans = -1;

    while (smallPointer <= bigPointer){
        ans = max(ans, values[smallPointer]+values[bigPointer]);
        int smallValue = values[smallPointer];
        int bigValue = values[bigPointer];

        if (cows[smallValue] < cows[bigValue]){
            // remove ones from small pointer
            cows[bigValue] -= cows[smallValue];
            smallPointer++;
        }
        else if (cows[smallValue] > cows[bigValue]){
            // remove ones from big pointer
            cows[smallValue] -= cows[bigValue];
            bigPointer--;
        }
        else{
            // cows are equal in amount
            smallPointer++;
            bigPointer--;
        }
    }

    cout << ans << '\n';
}
