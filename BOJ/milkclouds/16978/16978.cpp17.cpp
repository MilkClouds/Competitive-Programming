#include <bits/stdc++.h>
#define rep(a,b,c) for(ll a = b; a < c; a++)
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

const int MAX = 1e5 + 1;
int N, M, A[MAX], c, i, j, k, cnt1, cnt2;
ll ans[MAX];
pl Q1[MAX];
tl Q2[MAX];

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

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> N;
	rep(i, 0, N) cin >> A[i];
	rep(i, 0, N) tree.update(i + 1, A[i]);
	cin >> M;
	while (M--) {
		cin >> c;
		if (c & 1) {
			cin >> i >> k;
			Q1[cnt1++] = { i, k };
		}
		else {
			cin >> k >> i >> j;
			Q2[cnt2++] = { k, i, j, cnt2 };
		}
	}
	sort(Q2, Q2 + cnt2);
	cnt1 = 0;
	rep(t, 0, cnt2) {
		tie(k, i, j, c) = Q2[t];
		while (cnt1 < k) {
			//cout << Q1[cnt1].x << endl;
			tree.update(Q1[cnt1].x, Q1[cnt1].y - A[Q1[cnt1].x - 1]);
			A[Q1[cnt1].x - 1] = Q1[cnt1].y;
			cnt1++;
		}
		ans[c] = tree.query(j) - tree.query(i - 1);
	}
	rep(i, 0, cnt2) {
		cout << ans[i] << "\n";
	}
}