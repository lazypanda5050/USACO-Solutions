#include <bits/stdc++.h>
using namespace std;

long long solve(long long a, long long b){
  if (a == b){
    return 0;
  }
  else if (a > b){
    long long isOdd = a%2;
    // divide until a <= b, add 1 if its odd so you can divide
    return 1 + isOdd + solve((a+isOdd) / 2, b);
  }
  else{
    // compare just adding one repeatedly (subtracting from b), or multiply (dividing b)
    long long isOdd = b%2;
    return min(b-a, 1+isOdd+solve(a,b/2));
  }
}

int main(){
  long long n;
  cin >> n;
  for (long long i = 0; i < n; i++){
    long long a,b;
    cin >> a >> b;
    cout << solve(a,b) << '\n';
  }
}
