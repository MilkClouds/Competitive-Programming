#include <iostream>
using namespace std;

typedef long long ll;
const ll MOD=1e9+7;
const int a=5000;
int T,L;
ll dp[a+1][a+1];

int main(){
	cin>>T;
	dp[0][0]=1;
	for(int i=1;i<=a;i++){
		for(int j=0;j<=i;j++){
		    dp[i][j]+=dp[i-1][j+1];
		    dp[i][j]+=dp[i-1][j-1];
		    dp[i][j]%=MOD;
		}
	}
	while(T--){
		cin>>L;
		cout<<dp[L][0]<<'\n';
	}
}