#include <bits/stdc++.h>
#define rep(a,b,c) for(ll a = b; a < c; a++)
#define rep2(a,b,c) for(ll a = c - 1; a >=b; a--)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define x first
#define y second
using namespace std;
using ll = long long;
using tll = tuple<ll, ll, ll>;
using pl = pair<ll, ll>;
using pi = pair<int, int>;

const int MAX = 1e4 + 1;
ll N, cost[MAX], u, v, k, deg[MAX];
vector<ll> adj[MAX];
priority_queue<pl> pq;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> N;
	rep(v, 1, N + 1) {
		cin >> cost[v] >> k;
		rep(_, 0, k) {
			cin >> u;
			adj[u].pb(v);
			deg[v]++;
		}
	}
	rep(u, 1, N + 1) {
		if (deg[u] == 0) pq.push({ -cost[u], u });
	}
	rep(i, 1, N + 1){
		auto [t, u] = pq.top(); pq.pop();
		if (i == N) {
			cout << -t;
		}
		for (auto v : adj[u]) {
			deg[v]--;
			if (deg[v] == 0) {
				pq.push({ t - cost[v], v });
			}
		}
	}
}