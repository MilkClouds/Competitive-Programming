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
using tl = tuple<ll, ll, ll, ll>;
using pl = pair<ll, ll>;
using pi = pair<int, int>;
using ld = long double;

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
    long long th(ll n, ll a, ll b, ll c){
        return fac[n] * fac_inv[a] % MOD * fac_inv[b] % MOD * fac_inv[c] % MOD;
    }
	vector<long long> fac, fac_inv, inv;
	int MOD;
	const static int MOD1 = 998244353;
	const static int MOD2 = 1e9 + 9;
} C(25);

double W, L, D;
void solve(int a, int b){
    double ans = 0;
    rep(diff, a, b){
        rep(d, 0, 20 + 1){
            int w = (20 - d + diff) / 2;
            int l = w - diff;
            if(20 != w + l + d) continue;
            if(0 <= w && w <= 20 && 0 <= l && l <= 20) ans += C.th(20, w, l, d) * pow(W, w) * pow(L, l) * pow(D, d);
        }
    }
    cout << ans << endl;
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> W >> L >> D;
    cout << fixed;
    cout.precision(8);
    rep(i, 0, 5) solve(-20 + i * 10, -10 + i * 10);
    
}
