#include <iostream>
using namespace std;

int N,dp[100005][2][2];
int main(){
	cin>>N;
	dp[0][0][0]=1;
	for(int i=1;i<=N;i++){
		dp[i][0][1]=dp[i-1][0][0]+dp[i-1][1][0];
		dp[i][0][1]%=9901;
		dp[i][1][0]=dp[i-1][0][0]+dp[i-1][0][1];
		dp[i][1][0]%=9901;
		dp[i][0][0]=dp[i][0][1]+dp[i-1][0][1]+dp[i-1][1][1];
		dp[i][0][0]%=9901;
	}
	cout<<(dp[N][0][0]+dp[N][0][1]+dp[N][1][0])%9901;
}