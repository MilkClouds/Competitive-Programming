# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define rep2(i,a,b) for(int i = (b) - 1; i >= (a); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define pb push_back
#define eb emplace_back
#define em emplace
#define popcount __builtin_popcount
#define popcountll __builtin_popcountll
#define x first
#define y second
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using pl = pair<ll, ll>;
using tl = tuple<ll, ll, ll>;

const int MAX = 4005, MOD = 1e9 + 7;
int N, H[MAX];
template<class T> struct mi {
	T val;
	mi() { val = 0; }
	mi(const ll& v) {
		val = (-MOD <= v && v <= MOD) ? v : v % MOD;
		if (val < 0) val += MOD;
	}
	mi operator + (const mi& m) {
		T tmp = (val + m.val) % MOD;
		return tmp + (tmp < 0 ? MOD : 0);
	}
	mi operator - (const mi& m) {
		T tmp = (val - m.val) % MOD;
		return tmp + (tmp < 0 ? MOD : 0);
	}
	mi operator * (const mi& m) {
		T tmp = (val * m.val) % MOD;
		return tmp;
	}
	mi& operator += (const mi& m) {
		if ((val += m.val) >= MOD) val -= MOD;
		return *this;
	}
	mi& operator -= (const mi& m) {
		if ((val -= m.val) < 0) val += MOD;
		return *this;
	}
	mi& operator *= (const mi& m) {
		val = (val * m.val) % MOD;
		return *this;
	}
};
struct combinatorics {
	combinatorics() : combinatorics(0) {}
	combinatorics(long long N, int MOD = MOD1) : MOD(MOD), fac(N + 1), fac_inv(N + 1), inv(N + 1) {
		fac[0] = fac[1] = 1;
		rep(i, 2, N + 1) fac[i] = fac[i - 1] * i % MOD;
		fac_inv[N] = pow(fac[N], MOD - 2);
		rep2(i, 0, N) fac_inv[i] = fac_inv[i + 1] * (i + 1) % MOD;
		rep(i, 1, N + 1)inv[i] = fac[i] * fac_inv[i - 1] % MOD;
	}
	long long pow(long long a, long long b) {
		long long ret = 1;
		while (b) {
			if (b & 1) ret *= a;
			a *= a;
			a %= MOD;
			ret %= MOD;
			b >>= 1;
		}
		return ret;
	}
	long long C(long long n, long long r) {
		return fac[n] * fac_inv[r] % MOD * fac_inv[n - r] % MOD;
	}
	vector<long long> fac, fac_inv, inv;
	int MOD;
	const static int MOD1 = 998244353;
	const static int MOD2 = 1e9 + 9;
} C(MAX * 2);
mi<ll> dp[MAX][MAX];
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N;
    rep(i, 0, N) cin >> H[i + 1];
	dp[0][0] = 1;
    rep(i, 0, N){
		rep(j, 1, N + 1){
        	if(H[i] <= H[i + 1]){
				// dp[i + 1][j] = dp[i][j - 1] + dp[i][j - 2] + ... dp[i][0];
				dp[i + 1][j] += dp[i][j - 1];
			}
			if(H[i] >= H[i + 1]){
				// dp[i + 1][j] = dp[i][j] + dp[i][j + 1] + ... dp[i][i];
				dp[i + 1][j] += dp[i][i] - dp[i][j - 1];
			}
		}
		rep(j, 1, N + 1) dp[i + 1][j] += dp[i + 1][j - 1];
    }
	cout << dp[N][N].val << endl;
}