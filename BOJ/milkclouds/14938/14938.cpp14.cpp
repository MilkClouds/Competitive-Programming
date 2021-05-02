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

ll N, M, R, T[101], u, v, d, ans;
vector<pi> adj[101];

ll query(ll S){
	ll ans = 0;
	vector<bool> vis(N, 0);
	vector<ll> dist(N, 1e9);
	priority_queue<pi> Q;
	dist[S] = 0;
	Q.push({0, S});
	while(!Q.empty()){
		ll u = Q.top().y; Q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(auto [v, d]: adj[u]){
			if(dist[u] + d < dist[v]){
				dist[v] = dist[u] + d;
				Q.push({-dist[v], v});
			}
		}
	}
	rep(i, 0, N) ans += dist[i] <= M ? T[i] : 0;
	return ans;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> N >> M >> R;
	rep(i, 0, N) cin >> T[i];
	rep(i, 0, R) {
		cin >> u >> v >> d; u--; v--;
		adj[u].pb({v, d});
		adj[v].pb({u, d});
	}
	rep(i, 0, N) ans = max(ans, query(i));
	cout << ans << endl;
}