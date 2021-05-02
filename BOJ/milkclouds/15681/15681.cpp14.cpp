#include <bits/stdc++.h>
#define pb push_back
using namespace std;
const int MAX=1e5+5;
int N,R,Q,u,v,dp[MAX];
vector<int> adj[MAX];
int dfs(int u,int par){
	for(auto v:adj[u]){
		if(v^par){
			dp[u]+=dfs(v,u);
		}
	}
	return ++dp[u];
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N>>R>>Q;
	for(int i=1;i<N;i++){
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(R,0);
	while(Q--){
		cin>>u;
		cout<<dp[u]<<"\n";
	}
}