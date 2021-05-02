#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 3;
typedef long long ll;

ll N, T, a[MAX], l, r, m, b[MAX];
bool possible(ll diff) {
	ll ret = 0;
	for (int i = 0; i < N; i++)b[i] = a[i];
	for (int i = 1; i < N; i++) {
		if (b[i - 1] + diff < b[i]) {
			ret += b[i] - b[i - 1] - diff;
			b[i] = b[i - 1] + diff;
		}
	}
	for (int i = N - 2; ~i; i--) {
		if (b[i + 1] + diff < b[i]) {
			ret += b[i] - b[i + 1] - diff;
			b[i] = b[i + 1] + diff;
		}
	}
	return ret <= T;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> T;
	for (int i = 0; i < N; i++) cin >> a[i];
	r = *max_element(a, a + N) - *min_element(a, a + N);
	while (l < r) {
		m = l + r >> 1;
		if (possible(m))r = m;
		else l = m + 1;
	}
	possible(r);
	for (int i = 0; i < N; i++)cout << b[i] << ' ';
	return 0;
}