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
using tl = tuple<ll, ll, ll>;

const int MAX = 2e5 + 10, MOD = 998244353;
ll N, b, X[MAX], Y[MAX], S[MAX], cnt;
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
    bool operator < (const mi& m) const {
        return val < m.val;
    }
};
mi<ll> ans = 1, r = 1;
using pl = pair<ll, mi<ll>>;
priority_queue<pl> pq;
map<ll, mi<ll>> M;
long long powh(long long a, long long b) {
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
    cin >> N;
    int a = 3, b = 5;
    rep(i, 0, N) cin >> X[i] >> Y[i] >> S[i];
    pq.emplace(0, 1); M[0] = 1;
    b = powh(2LL, MOD - 2);
    rep2(i, 0, N){
        while(pq.top().x > X[i]){
            r -= pq.top().y;
            pq.pop();
        }
        if(S[i] == 1){
            M[X[i]] -= r;
            M[Y[i]] += r;
            pq.emplace(Y[i], r);
            r *= 2;
        } else {
            M[X[i]] -= r - 1;
            M[Y[i]] += r - 1;
            pq.emplace(Y[i], r - 1);
            r = r * 2 - 1;
        }
    }
    mi<ll> tmp = 1;
    for(auto pos = ++M.begin(); pos != M.end(); pos++){
        auto pre = pos; pre--;
        ans += tmp * (pos->x - pre->x);
        tmp += pos->y;
    }
    cout << ans.val << endl;
}
