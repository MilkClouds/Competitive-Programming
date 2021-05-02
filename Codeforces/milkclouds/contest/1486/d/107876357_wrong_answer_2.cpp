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
int N, K, a[MAX], l, r, m, tmp;

bool f(int x) {
	vector<int> b(N), S(N + 1);
	rep(i, 0, N) {
		b[i] = a[i] >= x ? 1 : -1;
		S[i + 1] = S[i] + b[i];
	}
	tmp = MAX;
	rep(i, K, N) {
		tmp = min(tmp, S[i]);
		if (S[i + 1] - tmp > 0) return 1;
	}
	return 0;
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> N >> K;
	rep(i, 0, N) cin >> a[i];
	l = 1; r = N;
	while (l + 1 < r) {
		m = l + r >> 1;
		if (f(m))l = m;
		else r = m;
	}
	cout << l << endl;
}