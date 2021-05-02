# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#define rep(a,b,c) for(ll a = b; a < c; a++)
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

const int MAX = 2e5 + 1;
int N, K, a[MAX], ans;

struct FenwickTree {
	ll tree[MAX];
	ll query(int i) {
		ll ret = 0;
		for (; i; i ^= i & -i)ret += tree[i];
		return ret;
	}
	void update(int i, int x) {
		for (; i <= N; i += i & -i)tree[i] += x;
	}
} tree;

int find() {
	int l = 1, r = N + 1;
	while (l < r) {
		int m = l + r >> 1;
		if (tree.query(m) < (K + 1) / 2) l = m + 1;
		else r = m;
	}
	return l;
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> N >> K;
	rep(i, 0, N) cin >> a[i];
	rep(i, 0, K) tree.update(a[i], 1);
	rep(i, 0, N - K + 1) {
		ans = max(ans, find());
		tree.update(a[i], -1);
		if(i < N - K) tree.update(a[i + K], 1);
	}
	cout << ans;
}