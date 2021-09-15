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

const int MAX = 2e5, MOD = 998244353;
int TC, N, A[MAX], a, b;
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
long long poww(long long a, long long b) {
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
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> TC;
    while(TC--){
        mi<ll> ans = 1;
        cin >> N;
        rep(i, 0, N) cin >> A[i];
        sort(A, A + N);
        if(A[N - 1] > A[N - 2] + 1){
            cout << "0\n";
            continue;
        }
        rep(i, 1, N + 1) ans *= i;
        if(A[N - 1] == A[N - 2]){
            cout << ans.val << "\n";
        } else {
            ll cnt = 0;
            rep2(i, 0, N - 1) if(A[i] == A[N - 2]) cnt++;
            ans *= cnt;
            ans *= poww(cnt + 1, MOD - 2);
            cout << ans.val << "\n";
        }
    }
}
