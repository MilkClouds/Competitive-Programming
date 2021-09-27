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

const ll MOD = 998244353;
const int MAX = 2e6 + 1;

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

ll N, D;
mi<ll> p[MAX], ans;
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N >> D;
    p[0] = 1;
    rep(i, 1, MAX) p[i] = p[i - 1] * 2;
    rep(d, 0, N){
        if(D + d < N) ans += p[D] * p[d];
        ll l = min(D, max(1LL, d + D - N + 1));
        ll r = max(0LL, min(D - 1, N - 1 - d));
        ans += p[D - 2] * p[d] * max(r - l + 1, 0LL);
    }
    ans *= 2;
    cout << ans.val << endl;
}
