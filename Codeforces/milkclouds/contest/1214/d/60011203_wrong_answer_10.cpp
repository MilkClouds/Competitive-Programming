#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<string> s;
vector<vector<int> > dp;
int f(int x){
	return x?(x==3?2:1):0;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	s.resize(n);
	dp.resize(n);
	for(int i=0;i<n;i++)dp[i].resize(m,0);
	for(int i=0;i<n;i++)cin>>s[i];

	if(n==1||m==1){
		bool flag=1;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)if(s[i][j]=='#')flag=0;
		cout<<flag;
		return 0;
	}

	dp[0][1]=s[0][1]=='.';dp[1][0]=s[1][0]=='.'?2:0;
	if(n==2&&m==2){
		cout<<(s[0][1]=='.')+(s[1][0]=='.');
		return 0;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(i==0&&j==0)continue;
			if((i==0&&j==1)||(i==1&&j==0))continue;
			if(s[i][j]=='#')continue;
			if(i==0)dp[i][j]=dp[i][j-1];
			else if(j==0)dp[i][j]=dp[i-1][j];
			else dp[i][j]=dp[i-1][j]|dp[i][j-1];
		}
	}
	//for(int i=0;i<n;i++){for(int j=0;j<m;j++)cout<<dp[i][j]<<" ";cout<<endl;}
	
	int a=dp[n-2][m-1];
	int b=dp[n-1][m-2];
	if(a==3 && b==3) cout<<2;
	else if ((a==3 && b) || (a&&b==3)) cout<<2;
	else if ((a==3 && b==0) || (a==0&&b==3)) cout<<1;
	else if (!(a==0 || b==0) && (a^b)) cout<<2;
	else if (!(a==0 || b==0) && (a==b)) cout<<1;
	else cout<<0;
}