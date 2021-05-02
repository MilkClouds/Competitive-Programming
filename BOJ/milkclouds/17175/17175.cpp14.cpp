#include <bits/stdc++.h>
using namespace std;
long long dp[51],N;
long long fibonacci(int n) {
  if(dp[n])return dp[n];
  if (n < 2) {
    return 1;
  }  
  return dp[n] = (fibonacci(n-2) + fibonacci(n-1) + 1 ) % 1000000007;
}
int main(){
	cin>>N;
	cout<<fibonacci(N);
}