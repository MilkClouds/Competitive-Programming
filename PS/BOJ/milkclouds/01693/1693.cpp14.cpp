#include <bits/stdc++.h>
#define pb push_back
using namespace std;
using ll=long long;
const int MAX=1e5+5;
int N,u,v,dp[MAX][18],last;
vector<int> adj[MAX];
ll dfs(int u,int par,int pc){
	ll m=1e10;
	if(dp[u][pc])return dp[u][pc];
	for(int c=1;c<18;c++){
		if(c==pc)continue;
		ll ret=c;
		for(auto v:adj[u]){
			if(v^par){
				ret+=dfs(v,u,c);
			}
		}
		if(ret<m)
			m=ret;
	}
	return dp[u][pc]=m;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N;
	for(int i=1;i<N;i++){
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	cout<<dfs(1,0,0);
}