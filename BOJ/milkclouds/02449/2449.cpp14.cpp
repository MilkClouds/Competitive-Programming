#include <bits/stdc++.h>
using namespace std;
int N,K,a[201],dp[201][201];
int solve(int i,int j){
	if(~dp[i][j])return dp[i][j];
	int ret=12345678;
	for(int k=i;k<j;k++)ret=min(ret,solve(i,k)+solve(k+1,j)+(a[i]!=a[k+1]));
	return dp[i][j]=ret;
}
int main()
{
	cin>>N>>K;
	for(int i=0;i<N;i++)cin>>a[i];
	for(int i=0;i<N;i++)for(int j=0;j<N;j++)if(i^j)dp[i][j]=-1;
	solve(0,N-1);
	cout<<dp[0][N-1];
	return 0;
}