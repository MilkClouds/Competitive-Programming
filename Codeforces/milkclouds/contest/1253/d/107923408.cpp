#include <bits/stdc++.h>
#define rep(a,b,c) for(int a = b; a < c; a++)
#define rep2(a,b,c) for(ll a = c - 1; a >=b; a--)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define x first
#define y second
using namespace std;
using ll = long long;
using tl = tuple<ll, ll, ll>;
using pl = pair<ll, ll>;
using pi = pair<int, int>;
using ld = long double;

const int INF = 1e9;

struct dsu {
	// if u is root : par[u] = -(size of tree)
	// else: par[u] = parent of u
public:
	dsu() : n(0) {}
	explicit dsu(int n) :n(n), par(n, -1), M(n, 0), m(n, 0) {
		rep(i, 0, n) M[i] = m[i] = i;
	}
	int merge(int u, int v) {
		assert(0 <= u && u < n);
		assert(0 <= v && v < n);
		u = find(u); v = find(v);
		if (u == v) return u;
		if (-par[u] < -par[v]) swap(u, v);
		par[u] += par[v];
		M[u] = max(M[u], M[v]);
		m[u] = min(m[u], m[v]);
		par[v] = u;
		return u;
	}
	int find(int u) {
		assert(0 <= u && u < n);
		if (par[u] < 0) return u;
		return par[u] = find(par[u]);
	}
	bool same(int u, int v) {
		assert(0 <= u && u < n);
		assert(0 <= v && v < n);
		return find(u) == find(v);
	}
	int size(int u) {
		assert(0 <= u && u < n);
		return -par[find(u)];
	}
	int getMax(int u) {
		assert(0 <= u && u < n);
		return M[find(u)];
	}
	int getMin(int u) {
		assert(0 <= u && u < n);
		return m[find(u)];
	}
	vector<vector<int> > groups() {
		vector<int> roots(n), groups(n);
		for (int i = 0; i < n; i++) {
			roots[i] = find(i);
			groups[roots[i]]++;
		}
		vector<vector<int> > result(n);
		for (int i = 0; i < n; i++) {
			result[i].reserve(groups[i]);
		}
		for (int i = 0; i < n; i++) {
			result[roots[i]].push_back(i);
		}
		result.erase(
			remove_if(result.begin(), result.end(), [&](const vector<int>& v) { return v.empty(); })
		);
		return result;
	}
private:
	int n;
	vector<int> par, M, m;
};

int N, M, u, v, cur = 1;
ll ans;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> N >> M;
	dsu DSU = dsu(N + 1);
	rep(i, 0, M) {
		cin >> u >> v;
		DSU.merge(u, v);
	}
	rep(i, 1, N + 1) {
		while (DSU.getMax(i) - DSU.getMin(i) + 1 > DSU.size(i)) {
			cur = max(cur + 1, i + 1);
			if (DSU.same(i, cur)) continue;
			DSU.merge(i, cur);
			ans++;
		}
	}
	cout << ans;
}