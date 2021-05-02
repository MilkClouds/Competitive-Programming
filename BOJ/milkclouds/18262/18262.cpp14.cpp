# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#define rep(a,b,c) for(int a=b;a<c;a++)
#define rep2(a,b,c) for(ll a=b;a>c;a--)
#define pb push_back
#define x first
#define y second
#define all(x) x.begin(), x.end()
using namespace std;
using ll=long long;
using ti=tuple<ll,ll,ll>;
using pi=pair<ll,ll>;
const int MAX = 1e3 + 1;
const ll INF = 1e12;

struct Edge {
	ll u, v, c, f;
	Edge(): Edge(0,0,0,0){}
	Edge(ll u, ll v, ll c, ll f): u(u), v(v), c(c), f(f){}
} Edges[MAX];
ll N, M, u, v, c, f;
double ans;
vector<Edge> adj[MAX];

ll get_minimum_cost(ll S, ll E, ll limit){
	vector<ll> dist(N, INF);
	vector<bool> vis(N, 0);
	priority_queue<pi> pq;
	dist[S] = 0;
	pq.push({0, S});
	while(!pq.empty()){
		ll u;
		do {
			u = pq.top().y;
			pq.pop();
		} while (!pq.empty() && vis[u]);
		if(vis[u]) break;
		vis[u] = 1;
		for(auto &e : adj[u]){
			if(e.f < limit) continue;
			if(dist[e.v] > dist[u] + e.c){
				dist[e.v] = dist[u] + e.c;
				pq.push({-dist[e.v], e.v});
			}
		}
	}
	return dist[E];
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> N >> M;
	rep(i, 0, M) {
		cin >> u >> v >> c >> f; u--; v--;
		Edges[i] = {u, v, c, f};
		adj[u].pb({u, v, c, f});
		adj[v].pb({v, u, c, f});
	}
	rep(i, 0, M){
		u = Edges[i].u; v = Edges[i].v; c = Edges[i].c; f = Edges[i].f;
		ans = max(ans, 1.0 * f / (get_minimum_cost(0, u, f) + c + get_minimum_cost(v, N - 1, f)));
		swap(u, v);
		ans = max(ans, 1.0 * f / (get_minimum_cost(0, u, f) + c + get_minimum_cost(v, N - 1, f)));
	}
	cout << (ll) (ans * 1000000) << endl;
}