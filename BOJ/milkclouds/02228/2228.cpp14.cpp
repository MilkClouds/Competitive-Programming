#include <bits/stdc++.h>
#define rep(a,b,c) for(int a=b;a<c;a++)
#define x first
#define y second
using namespace std;
using ll=long long;
using pii=pair<int,int>;

const int INF=1e9;

int N,M,A[105],sum[105],dp[105][52];

int solve(int n,int m){
	if(m==0)return 0;
	if(n>N)return -INF;
	if(dp[n][m]!=INF)return dp[n][m];
	int ret=solve(n+1,m);
	rep(i,n,N+1){
		ret=max(ret,sum[i]-sum[n-1]+solve(i+2,m-1));
	}
	return dp[n][m]=ret;
}


int main(){
	cin>>N>>M;
	rep(i,1,N+1){cin>>A[i];sum[i]=A[i]+sum[i-1];}
	fill(dp[0],dp[N+2],INF);
	cout<<solve(1,M);
}