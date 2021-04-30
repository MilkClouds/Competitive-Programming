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
const ll S = 0, E = 1, L = 2, R = 1002, MM = 2002, MAX = 3e3;

ll N, M, K, temp, u, v, f[MAX][MAX], c[MAX][MAX];
vector<ll> adj[MAX];

ll NetworkFlow(){
	ll F = 0;
	while(1){
		vector<ll> prev(MAX, -1);
		vector<bool> vis(MAX, 0);
		queue<ll> Q;
		Q.push(S); vis[S] = 1;

		while(!Q.empty() && prev[E] == -1){
			u = Q.front(); Q.pop();
			for(auto v: adj[u]){
				if(vis[v] || (c[u][v] - f[u][v]) <= 0) continue;
				vis[v] = 1;
				Q.push(v);
				prev[v] = u;
			}
		}
		if(prev[E] == -1) break;
		for(ll u = E; u ^ S; u = prev[u]) {
			f[prev[u]][u]++;
			f[u][prev[u]]--;
		}
		F++;
	}
	return F;
}
void build(ll u, ll v, ll C){
	adj[u].pb(v); adj[v].pb(u); c[u][v] = C;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> N >> M >> K;
	rep(i, 0, N) build(S, L + i, 1);
	rep(i, 0, M) build(R + i, E, 1);
	rep(i, 0, N) build(MM, L + i, 1);
	build(S, MM, K);

	rep(u, 0, N){
		cin >> temp;
		rep(_, 0, temp){
			cin >> v; v--;
			build(L + u, R + v, 1);
		}
	}
	cout << NetworkFlow();
}