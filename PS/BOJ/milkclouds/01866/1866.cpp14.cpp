#include <bits/stdc++.h>

using namespace std;
int N,c,h,a[3000],pSum[3001],dp[3000];
int main(){
	ios_base::sync_with_stdio(0);
	cin>>N;
	for(int i=0;i<N;i++)cin>>a[i];
	cin>>c>>h;
	sort(a,a+N);
	for(int i=1;i<=N;i++)pSum[i]=pSum[i-1]+a[i-1];
	for(int i=0;i<N;i++){
		dp[i]=dp[i-1]+a[i]*c;
		for(int j=0;j<=i;j++){
			int mid=(i+j)/2;
			int temp=0;
			temp=a[mid]*(mid-j)-(pSum[mid]-pSum[j]);
			temp+=pSum[i+1]-pSum[mid+1]-a[mid]*(i-mid);
			dp[i]=min(dp[i],dp[j-1]+temp*c+h);
		}
	}
	cout<<dp[N-1];
}