# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#define rep(a,b,c) for(ll a=b;a<c;a++)
#define x first
#define y second
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll=long long;
using ti=tuple<ll,ll,ll>;
using pi=pair<ll,ll>;
const int MAX = 5e4+5;
const ll INF = 3e9;

struct dual{
	ll a,b;
	dual():dual(-INF,-INF){}
	dual(ll a,ll b):a(a),b(b){}
};

dual f(dual x,dual y){
	vector<ll> v={x.a, x.b, y.a, y.b};
	sort(all(v), greater<ll>());
	v.erase(unique(all(v)), v.end());
	return {v[0],v[1]};
}

priority_queue<ti> Edges;
vector<ti> E;
ll N,M,u,v,w,root,ans=INF,cost;
vector<pi> adj[MAX];

int par[MAX],depth[MAX];
pair<ll,dual> tree_parent[MAX][17];
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
		else E.pb({u,v,w});
	}
	while(!Edges.empty()) {
		tie(w,u,v) = Edges.top(); Edges.pop(); w=-w;
		E.pb({u,v,w});
	}
	if(cnt < N) return -1;
	return ret;
}
void DFS(int u,int par){
	rep(i,1,17){
		auto temp = tree_parent[u][i-1];
		tree_parent[u][i] = {tree_parent[temp.x][i-1].x, f(temp.y, tree_parent[temp.x][i-1].y)};
	}
	for(auto [v,w]: adj[u]){
		if(v == par)continue;
		tree_parent[v][0].x = u;
		tree_parent[v][0].y = {w, -INF};
		depth[v] = depth[u] + 1;
		DFS(v, u);
	}
}
dual LCA(int u,int v){
	dual ret;
	if(depth[u] ^ depth[v]){
		if(depth[u] > depth[v]) swap(u, v);
		int t = depth[v] - depth[u];
		for(int i = 0; (1 << i) <= t; i++){
			if(t & (1<<i)) {
				ret = f(ret, tree_parent[v][i].y);
				v = tree_parent[v][i].x;
			}
		}
	}
	if(u^v){
		for(int i=16;~i;i--){
			if(!tree_parent[u][i].x) continue;
			if(tree_parent[u][i].x == tree_parent[v][i].x) continue;
			ret = f(ret, tree_parent[u][i].y);
			ret = f(ret, tree_parent[v][i].y);
			u = tree_parent[u][i].x;
			v = tree_parent[v][i].x;
		}
		return f(f(ret, tree_parent[u][0].y), tree_parent[v][0].y);
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	rep(i,0,M){
		cin >> u >> v >> w;
		Edges.push({-w, u, v});
	}
	cost = MST();
	if(cost == -1){
		cout << -1;
		return 0;
	}
	DFS(root, -1); 
	for(auto i : E){
		tie(u, v, w) = i;
		auto t = LCA(u, v);
		if(t.a == w) ans = min(ans, cost - t.b + w);
		else ans = min(ans, cost - t.a + w);
	}
	cout << (ans >= INF ? -1 : ans);
}