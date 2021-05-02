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

const int MAX = 1e5 + 3;
const ll INF = 1e10;
ll N, Q, U, V, K[MAX], C, A, B;

struct node {
	ll a, l, r, m;
};

class Seg {
public:
	int n;
	vector<ll> a, lmax, rmax, mmax, pos;
	Seg(int n) :n(n), a(4 * n), lmax(4 * n), rmax(4 * n), mmax(4 * n) {}
	void update(int node, int l, int r, int i, ll val) {
		if (r <= i || i < l) return;
		if (l + 1 == r) {
			a[node] = U * val + V;
			lmax[node] = rmax[node] = mmax[node] = a[node];
			return;
		}
		int m = l + r >> 1, left = node * 2, right = node * 2 + 1;
		update(left, l, m, i, val);
		update(right, m, r, i, val);
		a[node] = a[left] + a[right];
		lmax[node] = max(a[left] + lmax[right], lmax[left]);
		rmax[node] = max(a[right] + rmax[left], rmax[right]);
		mmax[node] = max({ mmax[left], mmax[right], rmax[left] + lmax[right] });
	}
	node query(int node, int l, int r, int s, int e) {
		if (r <= s || e <= l) return { 0, -INF, -INF, -INF };
		if (s <= l && r <= e) return { a[node], lmax[node], rmax[node], mmax[node] };
		int m = l + r >> 1;
		auto Q1 = query(node * 2, l, m, s, e);
		auto Q2 = query(node * 2 + 1, m, r, s, e);
		return { Q1.a + Q2.a, max(Q1.a + Q2.l, Q1.l), max(Q2.a + Q1.r, Q2.r), max({Q1.m, Q2.m, Q1.r + Q2.l}) };
	}
};

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> N >> Q >> U >> V;
	rep(i, 0, N) cin >> K[i];
	Seg tree = Seg(N);
	rep(i, 0, N) tree.update(1, 0, N, i, K[i]);
	while (Q--) {
		cin >> C >> A >> B; A--;
		if (C) {
			tree.update(1, 0, N, A, B);
		}
		else {
			cout << tree.query(1, 0, N, A, B).m - V << "\n";
		}
	}
}
