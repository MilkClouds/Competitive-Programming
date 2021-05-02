#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
int V,E,u,v,d;
vector<pii> adj[100001];
bool dfsn[100001];
ll ans,far;
void dfs(int u,int dist){
	if(dist>ans){
		far=u;
		ans=dist;
	}
	dfsn[u]=1;
	for(auto [v,d]:adj[u]){
		if(dfsn[v])continue;
		dfs(v,dist+d);
	}
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>V;
	for(int i=0;i<V;i++){
		cin>>u;
		while(1){
			cin>>v;
			if(v==-1)break;
			cin>>d;
			adj[u].push_back({v,d});
			adj[v].push_back({u,d});
		}
	}
	dfs(1,0);
	memset(dfsn,0,sizeof(bool)*(V+1));ans=0;
	dfs(far,0);
	cout<<ans;
}