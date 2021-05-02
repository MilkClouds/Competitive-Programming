#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int INF=1e9;
int N,K,dp[101][100001];
pii obj[101];
int f(int cur,int weight){
	if(weight<0)return -INF;
	if(cur==N || weight==0)return 0;
	if(~dp[cur][weight])return dp[cur][weight];
	return dp[cur][weight]=max(f(cur+1,weight-obj[cur].first)+obj[cur].second,
		f(cur+1,weight));
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N>>K;
	for(int i=0;i<N;i++){
		cin>>obj[i].first>>obj[i].second;
	}
	fill(dp[0],dp[N+1],-1);
	cout<<f(0,K);
}