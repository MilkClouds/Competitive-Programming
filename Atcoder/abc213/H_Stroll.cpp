# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#include <atcoder/convolution>
#include <atcoder/modint>
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
using namespace atcoder;
using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using pl = pair<ll, ll>;
using tl = tuple<ll, ll, ll>;
using mint = modint998244353;

int N, M, T, u, v, x;
vector<mint> d[11], p[11][11];
vector<pi> es;
vector<mint> get_vec(const vector<mint>& v, int l, int r){
	return {begin(v) + l, begin(v) + r};
}
void online_convolution(int l, int r){
	if(r - l == 1) return;
	int m = l + r >> 1;
	online_convolution(l, m);
	for(auto& [a, b]: es){
		auto pab = get_vec(p[a][b], 0, r - l);

		auto da = get_vec(d[a], l, m);
		auto ra = convolution(da, pab);
		rep(i, m, r) d[b][i] += ra[i - l];

		auto db = get_vec(d[b], l, m);
		auto rb = convolution(db, pab);
		rep(i, m, r) d[a][i] += rb[i - l];
	}
	online_convolution(m, r);
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N >> M >> T;
    rep(i, 0, M){
        cin >> u >> v; u--; v--;
        es.eb(u, v);
        p[u][v].assign(T + 1, 0);
        rep(j, 0, T) cin >> x, p[u][v][j + 1] = x;
    }
	rep(i, 0, N) d[i].assign(T + 1, 0);
	d[0][0] = 1;
	online_convolution(0, T + 1);
	cout << d[0][T].val() << "\n";
}
