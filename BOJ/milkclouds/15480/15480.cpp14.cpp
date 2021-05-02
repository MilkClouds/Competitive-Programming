#include <bits/stdc++.h>
#define rep(a,b,c) for(int a=b;a<c;a++)
#define x first
#define y second
#define all(x) x.begin(),x.end()
#define pb push_back
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
const int MAX=1e5+5;
int N,M,u,v,r,par[MAX][18],depth[MAX];
vector<int> adj[MAX];
void DFS(int u,int parent){
	par[u][0]=parent;
	depth[u]=depth[parent]+1;
	for(auto v:adj[u]) if(v^parent) DFS(v,u);
}
void build(){
	DFS(1,0);
	rep(k,1,18){
		rep(u,1,1+N){
			par[u][k]=par[par[u][k-1]][k-1];
		}
	}
}
int LCA(int u,int v){
	if(depth[u]^depth[v]){
		if(depth[u]>depth[v])swap(u,v); //v가 깊게
		int t=depth[v]-depth[u];
		rep(k,0,18){
			if(t&(1<<k)){
				v=par[v][k];
			}
		}
	}
	if(u==v)return u;
	rep(k,0,18){
		if(par[u][17-k]^par[v][17-k]){
			u=par[u][17-k];
			v=par[v][17-k];
		}
	}
	return par[u][0];
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N;
	rep(i,1,N){
		cin>>u>>v;
		adj[u].pb(v); adj[v].pb(u);
	}
	build();
	cin>>M;
	while(M--){
		cin>>r>>u>>v;
		int x[3]={LCA(u,v),LCA(r,u),LCA(r,v)};
		sort(x,x+3,[](int a,int b){return depth[a]>depth[b];});
		cout<<x[0]<<"\n";
	}
}
	