#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("lemonade.in", "r", stdin);
	freopen("lemonade.out", "w", stdout);
	int n;
	cin >> n;
	
	vector<int> cows(n);
	for (int i = 0; i < n; i++){
		cin >> cows[i];
	}

	sort(cows.rbegin(), cows.rend());

	for (int i = 0; i < n; i++){
		// i = how many cows already in line
		if (i > cows[i]){
			// goes away
			cout << i << '\n';
			return 0;
		}
		// joins line
	}
	// all cows joined
	cout << n << '\n';
	return 0;
}
