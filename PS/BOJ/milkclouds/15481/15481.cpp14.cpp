# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#define rep(a,b,c) for(ll a=b;a<c;a++)
#define x first
#define y second
#define pb push_back
using namespace std;
using ll=long long;
using ti=tuple<ll,ll,ll>;
using pi=pair<ll,ll>;
const int MAX=2e5+5;

priority_queue<ti> Edges;
ti E[MAX];
ll N,M,u,v,w,root,ans;
vector<pi> adj[MAX];

int par[MAX],depth[MAX];
pi tree_parent[MAX][19];
int find(int u){return u ^ par[u] ? par[u] = find(par[u]) : u;}
bool merge(int u, int v){
	u=find(u); v=find(v);
	if(u ^ v){
		if(rand()&1) swap(u, v);
		par[u] = v;
		return 1;
	}
	return 0;
}

ll MST(){
	rep(i,1,N+1) par[i] = i;
	ll ret = 0, cnt = 1;
	while(!Edges.empty()) {
		tie(w,u,v) = Edges.top(); Edges.pop(); w=-w;
		if(merge(u, v)){
			ret += w;
			adj[u].pb({v, w});
			adj[v].pb({u, w});
			root = u;
			if(++cnt == N) break;
		}
	}
	return ret;
}
void DFS(int u,int par){
	rep(i,1,19){
		auto temp = tree_parent[u][i-1];
		tree_parent[u][i] = {tree_parent[temp.x][i-1].x, max(temp.y, tree_parent[temp.x][i-1].y)};
	}
	for(auto [v,w]: adj[u]){
		if(v == par)continue;
		tree_parent[v][0].x = u;
		tree_parent[v][0].y = w;
		depth[v] = depth[u] + 1;
		DFS(v, u);
	}
}
ll LCA(int u,int v){
	ll ret=0;
	if(depth[u] ^ depth[v]){
		if(depth[u] > depth[v]) swap(u, v);
		int t = depth[v] - depth[u];
		for(int i = 0; (1 << i) <= t; i++){
			if(t & (1<<i)) {
				ret = max(ret, tree_parent[v][i].y);
				v = tree_parent[v][i].x;
			}
		}
	}
	if(u^v){
		for(int i=18;~i;i--){
			if(!tree_parent[u][i].x) continue;
			if(tree_parent[u][i].x == tree_parent[v][i].x) continue;
			ret = max(ret, tree_parent[u][i].y);
			ret = max(ret, tree_parent[v][i].y);
			u = tree_parent[u][i].x;
			v = tree_parent[v][i].x;
		}
		return max({ret, tree_parent[u][0].y, tree_parent[v][0].y});
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>N>>M;
	rep(i,0,M){
		cin>>u>>v>>w;
		Edges.push({-w, u, v});
		E[i] = {u, v, w};
	}
	ans = MST();
	DFS(root, -1);
	rep(i,0,M){
		tie(u,v,w) = E[i];
		cout << (ans - LCA(u, v) + w) << "\n";
	}
}