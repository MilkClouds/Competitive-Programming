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

const ll MOD = 1e9 + 7, MAX = 3e6;
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
	combinatorics(long long N, int MOD) : MOD(MOD), fac(N + 1), fac_inv(N + 1), inv(N + 1) {
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
} C(MAX, MOD);


ll N, M, K, S;
mi<ll> dp[MAX], ans, L[MAX], R[MAX];
mi<ll> query(int i){
	return L[i] * R[i] * C.fac_inv[i] * C.fac_inv[S - i] * ((S - i) % 2 ? -1 : 1);
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N >> M >> K;
	S = M + K;
	rep(i, 1, S + 1) dp[i] = C.pow(i, K);
	rep(j, 1, M + 1){
		rep(i, 1, S + 1){
			dp[i] = dp[i - 1] + dp[i];
		}
	}
	if(N <= S){
		cout << dp[N].val << endl;
		return 0;
	}
	L[0] = 1;
	rep(i, 0, S){
		L[i + 1] = L[i] * (N - i);
	}
	R[S] = 1;
	rep2(i, 0, S){
		R[i] = R[i + 1] * (N - i - 1);
	}
	rep(i, 0, S + 1){
		ans += dp[i] * query(i);
	}
	cout << ans.val << endl;
	return 0;
}
