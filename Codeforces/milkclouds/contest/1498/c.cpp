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
#define x first
#define y second
using namespace std;
using ll = long long;
using tl = tuple<ll, ll, ll, ll>;
using pl = pair<ll, ll>;
using pi = pair<int, int>;
using ld = long double;

const int MOD = 1e9 + 7;
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
int N, K, TC;
mi<ll> dp[1002][1002], up[1002][1002], down[1002][1002], ans;
int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> TC;
    while(TC--){
        fill(dp[0], dp[K + 1], 0);
        fill(up[0], up[K + 1], 0);
        fill(down[0], down[K + 1], 0);
        cin >> N >> K;
        ans = 0;
        dp[0][0] = 1;
        rep(i, 1, N + 2) down[0][i] = 1;
        rep(k, 1, K){
            rep(n, 1, N + 1){
                if(k & 1){
                    dp[k][n] = down[k - 1][n];
                } else {
                    dp[k][n] = up[k - 1][n];
                }
            }
            rep(n, 1, N + 2){
                down[k][n] = down[k][n - 1] + dp[k][n - 1];
            }
            rep2(n, 0, N){
                up[k][n] = up[k][n + 1] + dp[k][n + 1];
            }
        }
        rep(k, 0, K) ans += down[k][N + 1];
        cout << ans.val << "\n";
    }
}
