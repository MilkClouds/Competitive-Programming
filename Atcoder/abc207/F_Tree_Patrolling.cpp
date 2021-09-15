# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define rep2(i,a,b) for(int i = (b) - 1; i >= (a); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define pb push_back
#define eb emplace_back
#define em emplace
#define popcount __builtin_popcount
#define popcountll __builtin_popcountll
#define x first
#define y second
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using pl = pair<ll, ll>;
using tl = tuple<ll, ll, ll>;

// from 17:00
const int MAX = 3090, MOD = 1e9 + 7;
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

int N, u, v;
vector<array<mi<ll>, 3>> dp[MAX];
vector<int> adj[MAX];
void dfs(int u, int par){
    dp[u].resize(2);
    dp[u][0][0] = dp[u][1][2] = 1;
    for(auto& v: adj[u]){
        if(v == par) continue;
        dfs(v, u);
        int x = dp[u].size(), y = dp[v].size();
        vector<array<mi<ll>, 3>> cp(x + y);
        // 0: no-no
        // 1: yes-no
        // 2: yes-yes(chk)
        rep(i, 0, x) rep(j, 0, y){
            cp[i + j][0] += dp[u][i][0] * dp[v][j][0];
            cp[i + j][0] += dp[u][i][0] * dp[v][j][1];
            cp[i + j + 1][1] += dp[u][i][0] * dp[v][j][2];
            cp[i + j][1] += dp[u][i][1] * dp[v][j][0];
            cp[i + j][1] += dp[u][i][1] * dp[v][j][1];
            cp[i + j][1] += dp[u][i][1] * dp[v][j][2];
            cp[i + j + 1][2] += dp[u][i][2] * dp[v][j][0];
            cp[i + j][2] += dp[u][i][2] * dp[v][j][1];
            cp[i + j][2] += dp[u][i][2] * dp[v][j][2];
        }
        cp.pop_back();
        dp[u] = cp;
    }
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N;
    rep(i, 1, N){
        cin >> u >> v;
        adj[u].eb(v);
        adj[v].eb(u);
    }
    dfs(1, 0);
    for(auto& v: dp[1]){
        cout << (v[0] + v[1] + v[2]).val << '\n';
    }
}
