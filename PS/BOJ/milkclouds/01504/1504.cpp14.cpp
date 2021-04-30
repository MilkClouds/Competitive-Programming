#include <bits/stdc++.h>
#define pb push_back
#define rep(a,b,c) for(int a=b;a<c;a++)
#define x first
#define y second
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const int MAX = 1e3, INF=1e9;

int V,E,a,b;
vector<pi> adj[MAX];

ll SPFA(int S,int E){
	vector<ll> dist(V+1, INF), inQueue(V+1, 0);
	queue<int> Q;
	Q.push(S); dist[S] = 0;
	while(!Q.empty()){
		int u = Q.front();
		Q.pop();
		inQueue[u] = 0;
		for(auto [v, d] : adj[u]){
			if(dist[v] > dist[u] + d){
				dist[v] = dist[u] + d;
				if(!inQueue[v]){Q.push(v); inQueue[v]=1;}
			}
		}
	}
	return dist[E];
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> V >> E;
	rep(i, 0, E){
		int u,v,d;
		cin >> u >> v >> d;
		adj[u].pb({v,d});
		adj[v].pb({u,d});
	}
	cin >> a >> b;
	ll ret = SPFA(a, b) + min(SPFA(1, a) + SPFA(b, V), SPFA(1, b) + SPFA(a, V));
	cout << (ret >= INF ? -1 : ret);
}