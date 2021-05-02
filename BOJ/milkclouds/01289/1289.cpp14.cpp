#include <bits/stdc++.h>
using namespace std;

const int MOD=1e9+7;
typedef pair<int,int> pii;
typedef long long ll;
int V,E,u,v,d;
vector<pii> adj[100001];
ll D[100001];
bool dfsn[100001];
ll cost;
void dfs(int u){
	dfsn[u]=1;
	ll subtree_sum=0,add_cost=0;
	for(auto [v,d]:adj[u]){
		if(dfsn[v])continue;
		dfs(v);
		ll temp=(D[v]+1)*d%MOD;
		subtree_sum=(subtree_sum+temp)%MOD;
		add_cost=(add_cost-(temp*temp%MOD)+MOD)%MOD;
	}
	add_cost=(add_cost+(subtree_sum*subtree_sum%MOD))%MOD;
	if(add_cost%2==0)
		cost=(cost+add_cost/2)%MOD;
	else
		cost=(cost+(add_cost+MOD)/2)%MOD;
	D[u]=subtree_sum%MOD;
	cost=(cost+D[u])%MOD;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>V;
	for(int i=1;i<V;i++){
		cin>>u>>v>>d;
		adj[u].push_back({v,d});
		adj[v].push_back({u,d});
	}
	dfs(1);
	cout<<cost;
}