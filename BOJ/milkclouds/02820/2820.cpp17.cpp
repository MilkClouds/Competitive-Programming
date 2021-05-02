#include <bits/stdc++.h>
#define rep(a,b,c) for(ll a = b; a < c; a++)
#define rep2(a,b,c) for(ll a = c - 1; a >=b; a--)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define x first
#define y second
using namespace std;
using ll = long long;
using tll = tuple<ll, ll, ll>;
using pl = pair<ll, ll>;
using pi = pair<int, int>;
const int MAX = 5e5 + 5;

ll N, M, A[MAX], p[MAX], conv[MAX], rev[MAX], a, x;
pl child[MAX];
vector<ll> adj[MAX];
char c;

struct FenwickTree {
	ll tree[MAX];
	void update(ll u, ll x) {
		for (; u <= N; u += u & -u) tree[u] += x;
	}
	ll query(ll u) {
		ll ret = 0;
		for (; u; u ^= u & -u) ret += tree[u];
		return ret;
	}
} tree;

ll dfs(ll u, ll start) {
	ll ret = 1;
	conv[start] = u;
	start++;
	child[u].x = start;
	for (auto v : adj[u]) {
		ll tmp = dfs(v, start);
		start += tmp;
		ret += tmp;
	}
	child[u].y = start;
	return ret;
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> N >> M;
	rep(i, 1, N + 1) {
		if (i == 1) cin >> A[i];
		else {
			cin >> A[i] >> p[i];
			adj[p[i]].push_back(i);
		}
	}
	dfs(1, 1);
	rep(i, 1, N + 1) rev[conv[i]] = i;
	rep(i, 1, N + 1) { tree.update(rev[i], A[i]); tree.update(rev[i] + 1, -A[i]); }
	while (M--) {
		cin >> c >> a;
		if (c == 'p') {
			cin >> x;
			if(child[a].y <= N)	tree.update(child[a].y, -x);
			tree.update(child[a].x, x);
		}
		else {
			cout << tree.query(rev[a]) << "\n";
		}
	}
}