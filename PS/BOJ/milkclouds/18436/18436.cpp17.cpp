#include <bits/stdc++.h>
#define rep(a,b,c) for(int a = b; a < c; a++)
#define rep2(a,b,c) for(ll a = c - 1; a >=b; a--)
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

const int MAX = 1e5;
int N, A[MAX], M, c, l, r;

struct SegTree {
	int tree[MAX * 4], tree2[MAX * 4];
	void update(int l, int r, int node, int i, int x) {
		if (!(l <= i && i < r)) return;
		if (r - l == 1) {
			if (x & 1)tree[node] += (x > 0) - (x < 0);
			else tree2[node] += (x > 0) - (x < 0);
			return;
		}
		int m = l + r >> 1;
		update(l, m, node * 2, i, x);
		update(m, r, node * 2 + 1, i, x);
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
		tree2[node] = tree2[node * 2] + tree2[node * 2 + 1];
	}
	void update(int i, int x) {
		update(0, N, 1, i, x);
	}
	int query(int l, int r, int node, int left, int right, int flag) {
		if (left <= l && r <= right) return flag ? tree[node] : tree2[node];
		if (r <= left || right <= l)return 0;
		int m = l + r >> 1;
		return query(l, m, node * 2, left, right, flag) + query(m, r, node * 2 + 1, left, right, flag);
	}
	int query(int left, int right, int flag) {
		return query(0, N, 1, left, right, flag);
	}
} tree;


int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> N;
	rep(i, 0, N) cin >> A[i];
	rep(i, 0, N) tree.update(i, A[i]);
	cin >> M;
	while (M--) {
		cin >> c >> l >> r;
		l--;
		if (c == 1) {
			tree.update(l, -A[l]);
			tree.update(l, r);
			A[l] = r;
		}
		else cout << tree.query(l, r, c & 1) << "\n";
	}
}
