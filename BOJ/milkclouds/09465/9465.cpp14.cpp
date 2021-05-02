#include <iostream>
using namespace std;

int T,n;

int main()
{
	cin>>T;
	while(T--){
		cin>>n;
		int a[2][100000];
		int dp[2][100000];
		for(int i=0;i<2;i++)
			for(int j=0;j<n;j++)
				cin>>a[i][j];
		for(int i=0;i<n;i++){
			dp[0][i]=a[0][i]+max(dp[1][i-2],max(dp[0][i-2],dp[1][i-1]));
			dp[1][i]=a[1][i]+max(dp[0][i-2],max(dp[1][i-2],dp[0][i-1]));
		}
		int tt=n==1?0:max(dp[0][n-2],dp[1][n-2]);
		cout<<max(tt,max(dp[0][n-1],dp[1][n-1]))<<endl;
	}

	return 0;
}