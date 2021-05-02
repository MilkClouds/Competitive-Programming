#include <bits/stdc++.h>
#define rep(a,b,c) for(ll a = b; a < c; a++)
#define pb push_back
 
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
const int MAX = 2e5 + 1, INF = 1e9;

vector<int> adj[MAX], dp[2], d;
vector<bool> vis;

int dfs(int u, int flag){
	if(dp[flag][u] ^ INF) return dp[flag][u];
	int ret = d[u];
	for(auto v: adj[u]){
		if(!flag){
			if(d[v] <= d[u]) ret = min(ret, dfs(v, 1));
			else ret = min(ret, dfs(v, 0));
		} else if (d[v] > d[u]) ret = min(ret, dfs(v, 1));
	}
	return dp[flag][u] = ret;
}

void solve(){
	int n, m, u, v;
	cin >> n >> m;
	rep(i, 0, n) adj[i].clear();
	d.resize(n, INF);
	vis.resize(n, 0);
	dp[0].resize(n, INF); dp[1].resize(n, INF);
	rep(i, 0, m){
		cin >> u >> v; u--; v--;
		adj[u].pb(v);
	}
	queue<int> Q;
	Q.push(0); d[0] = 0; vis[0] = 0;
	while(!Q.empty()){
		int u = Q.front(); Q.pop();
		for(auto v: adj[u]){
			if(vis[v]) continue;
			d[v] = min(d[v], d[u] + 1);
			vis[v] = 1;
			Q.push(v);
		}
	}
	rep(i, 0, n) cout << dfs(i, 0) << " " ;
	cout << "\n";
}

int main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
	int TC;
	cin >> TC;
	while(TC--){
		solve();
	}
}