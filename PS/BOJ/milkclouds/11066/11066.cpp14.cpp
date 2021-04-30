#include <bits/stdc++.h>

using namespace std;

int T,K;

int main(){
	cin.tie(0);ios_base::sync_with_stdio(0);
	cin>>T;
	while(T--){
		cin>>K;
		int temp,preSum[510]={0};
		int dp[510][510];
		for(int i=1;i<=K;i++){
			cin>>temp;
			preSum[i]=preSum[i-1]+temp;
		}
		for(int m=1;m <=K;m++)
		{
			for(int i=1;i+m<=K;i++)
			{
				int j=i+m;dp[i][j]=1e9;
				for(int k=i;k<j;k++)
					dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+preSum[j]-preSum[i-1]);
			}
		}
		cout<<dp[1][K]<<"\n";
	}
}