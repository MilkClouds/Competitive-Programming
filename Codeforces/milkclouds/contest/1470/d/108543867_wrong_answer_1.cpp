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


void solve() {
	int N, M, u, v, d, cnt = 0;
	cin >> N >> M;
	vector<vector<int> > adj(N);
	queue<pi> Q;
	vector<bool> vis(N);
	vector<int> ans;
	rep(i, 0, M) {
		cin >> u >> v; u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	Q.push({ 0, 0 }); vis[0] = 1;
	while (!Q.empty()) {
		tie(u, d) = Q.front(); Q.pop();
		if (d % 2 == 0) ans.pb(u);
		cnt++;
		for (auto v : adj[u]) {
			if (vis[v])continue;
			vis[v] = 1;
			Q.push({ v, d + 1 });
		}
	}
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
