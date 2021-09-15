# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define rep2(i,a,b) for(int i = (b) - 1; i >= (a); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())  
#define pb push_back
#define x first
#define y second
using namespace std;
using ll = long long;
using tl = tuple<ll, ll, ll, ll>;
using pl = pair<ll, ll>;
using pi = pair<int, int>;
using ld = long double;


int dfs(int u, vector<int>& vis, vector<vector<int> >& adj) {
	if (vis[u]) return 0;
	vis[u] = 1;
	int ans = 1;
	for (auto v : adj[u]) ans += dfs(v, vis, adj);
	return ans;
}
void process(int u, vector<int>& vis, vector<vector<int> >& adj) {
	vis[u] = 1;
	for (auto v : adj[u]) {
		vis[v] = 2; 
	}
	for(auto v : adj[u]) for (auto j : adj[v]) if (vis[j] == 0) process(j, vis, adj);
}

void solve() {
	int N, M, u, v, d, cnt = 0;
	cin >> N >> M;
	vector<vector<int> > adj(N);
	queue<pi> Q;
	vector<int> vis(N);
	vector<int> ans;
	rep(i, 0, M) {
		cin >> u >> v; u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	cnt = dfs(0, vis, adj);
	vis.assign(N, 0);
	process(0, vis, adj);
	rep(i, 0, N) if (vis[i] == 1) ans.push_back(i);
	if (cnt == N) {
		cout << "YES\n";
		cout << ans.size() << "\n";
		for (auto i : ans) cout << i + 1 << " ";
		cout << "\n";
	}
	else {
		cout << "NO\n";
	}
}


int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	int TC;
	cin >> TC;
	while (TC--) solve();
}
