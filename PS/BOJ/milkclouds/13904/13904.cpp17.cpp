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

int N, d, w, comp = -1;
ll ans;
priority_queue<pi> pq;
multimap<int, int> m;

struct FenwickTree {
	ll tree[1001];
	ll query(int i) {
		ll ret = 0;
		for (; i; i ^= i & -i)ret += tree[i];
		return ret;
	}
	void update(int i, int x) {
		for (; i <= 1000; i += i & -i)tree[i] += x;
	}
} tree;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> N;
	rep(i, 0, N) {
		cin >> d >> w;
		pq.push({ w, d });
	}
	while (!pq.empty()) {
		w = pq.top().x;  d = pq.top().y; pq.pop();
		if (comp >= d) continue;
		m.insert({ d, w });
		tree.update(d, 1);
		rep(i, 1, 1001) if (tree.query(i) == i)comp = max(comp, i);
	}
	for (auto p : m)ans += p.y;
	cout << ans;
}