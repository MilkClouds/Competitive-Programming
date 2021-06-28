# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
#define _CRT_SECURE_NO_WARNINGS
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

const int MOD = 998244353;
int N, W[111], tot;
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
mi<ll> f[111], dp[111][11111], ans;
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N;
    rep(i, 0, N) {
        cin >> W[i];
        tot += W[i];
    }
    if(tot & 1){cout << "0\n"; return 0;}
    tot >>= 1;
    f[0] = 1;
    rep(i, 1, N + 1) f[i] = f[i - 1] * i;
    dp[0][0] = 1;
    rep(i, 0, N) rep2(j, 0, i + 1) rep(k, W[i], 100 * N + 1) {
        dp[j + 1][k] += dp[j][k - W[i]];
    }
    rep(j, 0, N + 1) ans += f[j] * f[N - j] * dp[j][tot];
    cout << ans.val << endl;
}
