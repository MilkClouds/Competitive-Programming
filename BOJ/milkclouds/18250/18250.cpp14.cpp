#include <bits/stdc++.h>
#define rep(a,b,c) for(ll a=b;a<c;a++)
#define pb push_back
using namespace std;
using ll = long long;
const ll MAX = 2e5 + 1;

ll N, M, u, v, indeg[MAX], ans, vis[MAX], odd, cnt;

vector<ll> adj[MAX];

bool dfs(ll u){
	if(vis[u]) return 0;
	vis[u] = ++cnt;
	odd += indeg[u] & 1;
	for(auto& v: adj[u]) {
		dfs(v);
	}

	return 1;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	rep(i, 0, M){
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
		indeg[u]++; indeg[v]++;
	}
	rep(i, 1, N + 1) {
		odd = cnt = 0;
		if(dfs(i)){
			if(odd) ans += odd / 2;
			else ans += cnt > 1;
		}
	}
	cout << ans << endl;
}