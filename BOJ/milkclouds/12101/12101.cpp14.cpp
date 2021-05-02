#include <bits/stdc++.h>
#define rep(a,b,c) for(int a=b;a<c;a++)
using namespace std;

int NN,KK,dp[12],flag;

int build(int N){
	if(N<0)return 0;
	if(N==0)return 1;
	if(dp[N])return dp[N];
	return dp[N]=build(N-1)+build(N-2)+build(N-3);
}

string solve(int N,int K){
	if(N==1 && K==1)return "1";
	if(flag)return "";
	int t=0,k=1;
	for(;k<=3;k++){
		if(t+dp[N-k]>=K)break;
		if(k==3){
			flag=1;
			return "";
		}
		t+=dp[N-k];
	}
	if(N-k==0)return to_string(k);
	return to_string(k)+"+"+solve(N-k,K-t);
} 

int main(){
	cin>>NN>>KK; dp[0]=1;
	build(NN);
	string t=solve(NN,KK);
	cout<<(flag?"-1":t);
}