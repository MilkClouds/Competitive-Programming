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
int u[MAX], v[MAX], N, k, deg[MAX];
ll w[MAX];
vector<pl> adj[MAX];

template<class T> struct mi {
	T val;
	mi() { val = 0; }
	mi(const ll& v) {
		val = (-MOD <= v && v <= MOD) ? v : v % MOD;
		if (val < 0) val += MOD;
	}
	mi operator + (const mi& m) {
		T tmp = (val + m.val) % MOD;
		return tmp + (tmp < 0 ? MOD : 0);
	}
	mi operator - (const mi& m) {
		T tmp = (val - m.val) % MOD;
		return tmp + (tmp < 0 ? MOD : 0);
	}
	mi operator * (const mi& m) {
		T tmp = (val * m.val) % MOD;
		return tmp;
	}
	mi& operator += (const mi& m) {
		if ((val += m.val) >= MOD) val -= MOD;
		return *this;
	}
	mi& operator -= (const mi& m) {
		if ((val -= m.val) < 0) val += MOD;
		return *this;
	}
	mi& operator *= (const mi& m) {
		val = (val * m.val) % MOD;
		return *this;
	}
};
mi<ll> ans[MAX], ret;

void dfs(int u, int par){
    for(auto [v, w]: adj[u]){
        if(v == par) continue;
        dfs(v, u);
        ans[u] += (ans[v].val ^ w);
    }
}

int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N;
    rep(i, 1, N){
        cin >> u[i] >> v[i] >> w[i];
        adj[u[i]].pb({v[i], w[i]}); adj[v[i]].pb({u[i], w[i]});
        deg[u[i]]++; deg[v[i]]++;
    }
    rep(i, 1, N + 1) if(deg[i] == 1) k = i;
    dfs(k, 0);
    rep(i, 1, N + 1) ret += ans[i];
    cout << k << endl;
    rep(i, 1, N + 1) cout << ans[i].val << endl;
    cout << ret.val;
}
