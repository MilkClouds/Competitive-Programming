#include <bits/stdc++.h>
#define rep(a,b,c) for(int a=b;a<c;a++)
#define x first
#define y second
#define all(x) x.begin(),x.end()
#define pb push_back
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
int N,K,A[105],dp[105][105][6];
int solve(int l,int r,int k){
	if(l>r)return 0;
	int& ret=dp[l][r][k];
	if(~ret)return ret;
	ret=K-k+solve(l+1,r,1);
	rep(i,l+1,r+1) if(A[i]==A[l])
		ret=min(ret, solve(i,r,min(K,k+1))+solve(l+1,i-1,1));
	return ret;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N>>K;
	rep(i,0,N)cin>>A[i];
	fill(dp[0][0],dp[N][N],-1);
	cout<<solve(0,N-1,1);
}
	