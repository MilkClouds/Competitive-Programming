#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define rep2(i,a,b) for(int i = (b) - 1; i >= (a); i--)
#define cinA(A, N) rep(i, 0, N) cin >> A[i];
#define coutA(A, N) rep(i, 0, N) cout << A[i] << " ";
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define eb emplace_back
#define popcount __builtin_popcount
#define popcountll __builtin_popcountll
#define x first
#define y second
using namespace std;
using ll = long long;
using ull = uint64_t;
using ld = long double;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using pl = pair<ll, ll>;
using tl = tuple<ll, ll, ll>;


typedef complex<double> cpx;

void fft(vector<cpx>& a) {
    // https://github.com/kth-competitive-programming/kactl/blob/master/content/numerical/FastFourierTransform.h
    int n = a.size(), L = 31 - __builtin_clz(n);
    static vector<cpx> R(2, 1);
    static vector<cpx> rt(2, 1);
    for (static int k = 2; k < n; k *= 2) {
        R.resize(n); rt.resize(n);
        auto x = polar(1.0, acos(-1.0) / k);
        for (int i = k; i < 2 * k; i++) rt[i] = R[i] = i&1 ? R[i/2] * x : R[i/2];
    }
    vector<int> rev(n);
    for (int i = 0; i < n; i++) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
    for (int i = 0; i < n; i++) if (i < rev[i]) swap(a[i], a[rev[i]]);
    for (int k = 1; k < n; k *= 2) {
        for (int i = 0; i < n; i += 2 * k) {
            for (int j = 0; j < k; j++) {
                auto x = (double *)&rt[j+k], y = (double *)&a[i+j+k];
                cpx z(x[0]*y[0] - x[1]*y[1], x[0]*y[1] + x[1]*y[0]);
                a[i + j + k] = a[i + j] - z;
                a[i + j] += z;
            } 
        }
    }
}

vector<ll> conv(const vector<ll>& a, const vector<ll>& b) {
    if (a.empty() || b.empty()) return {};
    vector<ll> res(a.size() + b.size() - 1);
    int L = 32 - __builtin_clz(res.size()), n = 1 << L;
    vector<cpx> in(n), out(n);
    copy(a.begin(), a.end(), begin(in));
    for (size_t i = 0; i < b.size(); i++) in[i].imag(b[i]);
    fft(in);
    for (cpx& x : in) x *= x;
    for (int i = 0; i < n; i++) out[i] = in[-i & (n - 1)] - conj(in[i]);
    fft(out);
    // for (size_t i = 0; i < res.size(); i++) res[i] = imag(out[i]) / (4 * n);
    for (size_t i = 0; i < res.size(); i++) res[i] = round(imag(out[i]) / (4 * n));
    // for (size_t i = 0; i < res.size(); i++) res[i] = (ll) round(imag(out[i]) / (4 * n)) % MOD; // for MOD
    return res;
}

const int MAXN = 1e5 + 1;
ll N, u, v, ret;
vector<ll> adj[MAXN];
ll sz[MAXN], dist[MAXN], M[MAXN], ans[MAXN];
bool vis[MAXN];

ll getSize(ll u, ll p) {				// 서브트리들의 크기를 구한다
	sz[u] = 1;
	M[u] = 0;
	for(auto v : adj[u]) if(!vis[v] && v != p) {
		sz[u] += getSize(v, u);
	}
	return sz[u];
}
int centroid(int u, int s){
	for(auto v: adj[u]) if(!vis[v] && sz[v] < sz[u] && 2 * sz[v] >= s) return centroid(v, s);
	return u;
}

void solve(ll u) {
	ll s = getSize(u, -1);
	u = centroid(u, s);
	vis[u] = true;
	dist[u] = 0;
	vector<ll> A(s / 2 + 1);
	function<ll(ll, ll)> dfs = [&](ll u, ll par){
		for(auto v: adj[u]) if(!vis[v] && v != par) {
			dist[v] = dist[u] + 1;
			A[dist[v]]++;
			M[u] = max(M[u], dfs(v, u));
		}
		return ++M[u];
	};
	dfs(u, -1);
	rep(i, 1, M[u]) ans[i] += A[i] << 1;
    auto&& ret = conv(A, A);
	rep(i, 0, ret.size()) ans[i] += ret[i];
	for(auto v: adj[u]){
		if(vis[v]) continue;
		vector<ll> B(M[v] + 1);
		function<void(ll, ll)> dfs = [&B, &dfs](ll u, ll par){
			B[dist[u]]++;
			for(auto v: adj[u]) if(!vis[v] && v != par) {
				dfs(v, u);
			}
		};
		dfs(v, u);
		auto&& ret = conv(B, B);
		rep(i, 0, ret.size()) ans[i] -= ret[i];
	}
	for(auto v : adj[u]) if(!vis[v]) solve(v);	// 나누어진 서브트리에서 문제 해결
}
vector<ll> pn;
bool arr[MAXN];

void eratos() {
	pn.push_back(2);
	for (ll i = 3; i < MAXN; i += 2) {
		if (arr[i]) continue;
		pn.push_back(i);
		for (ll j = i * i; j < MAXN; j += i) arr[j] = 1;
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
	solve(1);
	eratos();
	for(auto i: pn){
		if(i >= N) break;
		ret += ans[i];
	}
	cout.precision(18); cout << fixed;
	cout << (long double)ret / accumulate(ans, ans + N, 0LL) << "\n";
}
