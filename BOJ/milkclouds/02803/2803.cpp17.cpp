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

const int MAX = 1e6, MOD = 1e9 + 7;
int N, M, K, x, A[MAX], ans;
vector<ll> dp[21];

int pow_m(ll a, ll b) {
	ll ret = 1;
	while (b) {
		if(b & 1) ret *= a;
		a *= a;
		ret %= MOD;
		a %= MOD;
		b >>= 1;
	}
	return ret;
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> N >> M;
	rep(i, 0, N) {
		cin >> K;
		rep(_, 0, K) {
			cin >> x;
			A[i] |= 1 << x - 1;
		}
		A[i] ^= (1 << M) - 1;
	}
	dp[0].assign(1 << M, 0);
	rep(i, 0, N) dp[0][A[i]]++;
	rep(i, 1, M + 1) {
		dp[i].assign(1 << M, 0);
		rep(j, 0, 1 << M) {
			if (!(j & (1 << i - 1))) dp[i][j] = dp[i - 1][j] + dp[i - 1][j ^ (1 << i - 1)];
			else dp[i][j] = dp[i - 1][j];
		}
		dp[i - 1].clear();
		vector<ll>().swap(dp[i - 1]);
	}
	rep(i, 0, 1 << M) {
		int j = i, cnt = 0;
		while (j) { cnt += j & 1; j >>= 1; }
		ll tmp = ans;
		if (cnt & 1) ans -= pow_m(2, dp[M][i]);
		else ans += pow_m(2, dp[M][i]);
		if (ans < 0)ans += MOD;
		ans %= MOD;
	}
	cout << ans;
}
