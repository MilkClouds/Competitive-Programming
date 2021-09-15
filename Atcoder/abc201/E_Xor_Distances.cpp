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

const int MAX = 2e5 + 1, MOD = 1e9 + 7;
int u[MAX], v[MAX], N, k, A[60], B[60];
ll w[MAX], dist[MAX], ans;
vector<pl> adj[MAX];

void dfs(int u, int par){
    for(auto [v, w]: adj[u]){
        if(v == par) continue;
		dist[v] = dist[u] ^ w;
        dfs(v, u);
    }
}

int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N;
    rep(i, 1, N){
        cin >> u[i] >> v[i] >> w[i];
        adj[u[i]].pb({v[i], w[i]}); adj[v[i]].pb({u[i], w[i]});
    }
	dfs(1, 0);
	rep(j, 0, 60){
		rep(i, 1, N + 1){
			if(dist[i] & (1LL << j)) A[j]++;
			else B[j]++;
		}
		ans += (1LL * A[j] * B[j] % MOD) * ((1LL << j) % MOD);
		ans %= MOD;
	}
	cout << ans;
}
