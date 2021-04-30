#include <iostream>
#include <cmath>
using namespace std;
int dp[100000+1]={1,1,2,2,3};
const int m=1e9+9;
int main(){
	for(int i=5;i<100000+1;i++){
		dp[i]=((long)dp[i-2]+dp[i-4]+dp[i-6])%m;
	}
	int T,m;
	cin>>T;
	while(T--){
		cin>>m;
		cout<<dp[m]<<endl;
	}
	return 0;
}