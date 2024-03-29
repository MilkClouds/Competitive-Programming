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
const int MAX = 1e5 + 5;

ll N, K, tree[MAX * 2], u, l, r, m, remain, ans[MAX];

ll query(ll i) {
	ll ret = 0;
	for (; i; i ^= i & -i) ret += tree[i];
	return ret;
}
void update(ll i, ll x) {
	for (; i <= N * 2; i += i & -i) tree[i] += x;
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> N >> K; u = N;
	rep(i, 0, N * 2) update(i + 1, 1);
	rep(i, 0, N) {
		remain = K;
		remain %= N - i;
		if (remain == 0) {
			if (!query(u)) { u += N; }
			l = 1;
			r = u;
			while (l < r) {
				m = l + r >> 1;
				if (query(u) - query(m) == 0) r = m;
				else l = m + 1;
			}
			u = l;
		}
		l = u; r = N * 2;
		while (l < r) {
			m = l + r >> 1;
			if (query(m) - query(u) < remain) l = m + 1;
			else r = m;
		}
		l = (l - 1) % N + 1;
		u = l;
		ans[i] = u;
		update(u, -1); update(u + N, -1);
	}
	cout << "<";
	rep(i, 0, N - 1) cout << ans[i] << ", ";
	cout << ans[N - 1];
	cout << ">";
}