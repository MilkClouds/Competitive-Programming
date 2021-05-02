#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define rep(a,b,c) for(int a = b; a < c; a++)
#define rep2(a,b,c) for(int a = c - 1; a >=b; a--)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define x first
#define y second
using namespace std;
using ll = long long;
using tl = tuple<ll, ll, ll, ll>;
using pl = pair<ll, ll>;
using pi = pair<int, int>;
using ld = long double;

const int MAX = 1e5 + 1;
int N, Q, cmd, x, c, u, v;
vector<int> adj[MAX];

int sz[MAX], in[MAX], out[MAX];
int dfs(int u, int prev) {
	static int pv;
	in[u] = ++pv;
	for (auto v : adj[u]) {
		if(v ^ prev) sz[u] += dfs(v, u);
	}
	out[u] = pv;
	return ++sz[u];
}

struct FenwickTree {
public:
	FenwickTree() : FenwickTree(0) {}
	explicit FenwickTree(int N) : N(N), tree(N + 1, 0) {}
	ll query(int i) {
		ll ret = 0;
		for (; i; i ^= i & -i)ret += tree[i];
		return ret;
	}
	void update(int i, int x) {
		for (; i <= N; i += i & -i)tree[i] += x;
	}
private:
	int N;
	vector<ll> tree;
} A, B;

void update(int i, int x) {
	A.update(in[i], x);
	A.update(out[i] + 1, -x);
	B.update(in[i], x * sz[i]);
}
ll query(int i) {
	return sz[i] * A.query(in[i]) + B.query(out[i]) - B.query(in[i]);
}

map<int, int> M[MAX];

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> N >> Q;
	A = FenwickTree(N); B = FenwickTree(N);
	rep(i, 0, N - 1) {
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(1, 0);
	while (Q--) {
		cin >> cmd >> x;
		if (cmd & 1) {
			cin >> c;
			auto it = M[c].upper_bound(in[x]);
			if (it != M[c].begin() && out[prev(it)->second] >= out[x]) continue;
			while (it != M[c].end() && out[it->second] <= out[x]) {
				update(it->second, -1);
				M[c].erase(it++);
			}
			M[c][in[x]] = x;
			update(x, 1);
		}
		else {
			cout << query(x) << "\n";
		}
	}
}
