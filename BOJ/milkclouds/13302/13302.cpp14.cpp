#include <bits/stdc++.h>
using namespace std;

int N,M,a[102],x;
int dp[105][105];
int solution(int day,int coupon){
	if(day>N)return 0;
	if(~dp[day][coupon])return dp[day][coupon];
	if(a[day])return dp[day][coupon]=solution(day+1,coupon);
	return dp[day][coupon]=min({coupon>2?solution(day+1,coupon-3):solution(day+1,coupon)+10,
	solution(day+3,coupon+1)+25,
	solution(day+5,coupon+2)+37});
}
int main(){
	cin>>N>>M;
	for(int i=0;i<M;i++)cin>>x,a[x]=1;
	for(int i=0;i<=N;i++)fill(dp[i],dp[i]+100,-1);
	cout<<solution(1,0)*1000;
}
