#include <bits/stdc++.h>
using namespace std;
int dp[21][21][21],a,b,c;
int w(int a,int b,int c){
	if(a<=0 or b<=0 or c<=0)return 1;
	if(a>20 or b>20 or c>20)return w(20,20,20);
	if(dp[a][b][c])return dp[a][b][c];
	if(a<b and b<c)return dp[a][b][c]=w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
	return dp[a][b][c]=w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
}
int main(){
	while(1){
		cin>>a>>b>>c;
		if(a==-1&&b==-1&&c==-1)break;
		printf("w(%d, %d, %d) = %d\n",a,b,c,w(a,b,c));
	}
}