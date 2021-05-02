#include <iostream>
using namespace std;

int n,m,t,dp[1001][1001],r;

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
		scanf("%1d",&t);
		if(t){
			dp[i][j]=min(min(dp[i-1][j-1],dp[i-1][j]),dp[i][j-1])+1;
			r=max(dp[i][j],r);
		}
	}
	cout<<r*r;
}