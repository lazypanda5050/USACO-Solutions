#include <bits/stdc++.h>
using namespace std;

const long long maxCards = 1e5;
int main(){
  freopen("highcard.in","r",stdin);
  freopen("highcard.out","w",stdout);

  long long n;
  cin >> n;
  
  vector<bool> elsieHas(2*n+1, false);
  for (long long i = 0; i < n; i++){
    long long card;
    cin >> card;
    elsieHas[card] = true;
  }

  vector<long long> elsie;
  vector<long long> bessie;
  for (long long i = 1; i <= n*2; i++){
    if (elsieHas[i]){
      elsie.emplace_back(i);
    }
    else{
      bessie.emplace_back(i);
    }
  }

  long long polong longs = 0, bessieI = 0, elsieI = 0;

  while (bessieI < n && elsieI < n){
    if (bessie[bessieI] > elsie[elsieI]){
      polong longs++;
      bessieI++;
      elsieI++;
    }
    else{
      bessieI++;
    }
  }
  
  cout << polong longs << '\n';
}
