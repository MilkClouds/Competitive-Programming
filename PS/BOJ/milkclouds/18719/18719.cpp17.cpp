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

const int MAX = 1e6;
ll TC, N, A[MAX], F[MAX + 1], ans;

void solve() {
	cin >> N;
	ans = 0;
	fill(F, F + MAX + 1, 0);
	rep(i, 0, N) {
		cin >> A[i];
		F[A[i]]++;
	}
	rep(i, 0, 20) rep(j, 1, MAX + 1) {
		if (j & (1 << i)) F[j] += F[j ^ (1 << i)];
	}
	rep(i, 0, N) ans += F[A[i]];
	cout << ans << "\n";
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> TC;
	while (TC--)solve();
}