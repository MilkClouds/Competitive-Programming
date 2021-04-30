#include <bits/stdc++.h>
#define rep(a,b,c) for(ll a = b; a < c; a++)
#define pb push_back

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
const int MAX = 1e5 + 3;

ll N, A[MAX], p, chk[MAX], chk2[MAX], ans;
vector<ll> adj[MAX], divisor[MAX];

void eratos() {
	rep(i, 1, MAX) {
		for (ll j = i; j < MAX; j += i) {
			divisor[j].pb(i);
		}
	}
}

void dfs(ll u) {
	for (auto v : divisor[A[u]]) ans += chk[v];
	ans += chk2[A[u]];
	ans -= chk[A[u]];
	chk[A[u]]++;
	for (auto v : divisor[A[u]]) chk2[v]++;
	for (auto v : adj[u]) dfs(v);
	chk[A[u]]--;
	for (auto v : divisor[A[u]]) chk2[v]--;
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> N;
	rep(i, 0, N) cin >> A[i];
	rep(i, 1, N) {
		cin >> p; p--;
		adj[p].pb(i);
	}
	eratos();
	dfs(0);
	cout << ans << endl;
}