#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i < b; i++)
using namespace std;
typedef long long ll;

int n;
ll dp[36];
ll f(int n){
	if(dp[n])return dp[n];
	ll ret=0;
	rep(i,0,n)ret+=f(i)*f(n-i-1);
	return dp[n]=ret;
}
int main(){dp[0]=1;cin>>n;cout<<f(n);}