#include <bits/stdc++.h>
using namespace std;
long long N,a[101][101],dp[101][101];
inline bool can(int x,int y){
	return x<N && y<N;
}
int main()
{
	cin>>N;
	for(int i=0;i<N;i++)for(int j=0;j<N;j++)cin>>a[i][j];
	dp[0][0]=1;
	for(int i=0;i<N;i++)for(int j=0;j<N;j++){
		if(i==N-1&&j==N-1)break;
		int x=i+a[i][j],y=j+a[i][j];
		if(can(x,j))dp[x][j]+=dp[i][j];
		if(can(i,y))dp[i][y]+=dp[i][j];
	}
	cout<<dp[N-1][N-1];
	return 0;
}