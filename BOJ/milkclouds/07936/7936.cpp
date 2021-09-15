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

const ll INF = 1e18;
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
} C;
ll TC, p, a, m, og, g;

ll discrete_log(ll a, ll x){
    ll ret = p;
    ll T = ceil(sqrt(p)), tmp;
    map<ll, ll> m, m2;
    tmp = 1;
    for(ll i = 0; i < p; i += T) {
        m[tmp] = i;
        tmp = tmp * C.pow(x, T) % p;
    }
    tmp = 1;
    for(ll i = 0; i < T; i ++){
        m2[tmp] = i;
        tmp = tmp * x % p;
    }
    for(auto [i, j]: m2){
        ll tmp = a * C.pow(i, p - 2) % p;
        if(m.find(tmp) != m.end()){
            ret = min(ret, m[tmp] + j);
        }
    }
    return ret;
}
ll gcd(ll a, ll b){
    return a % b ? gcd(b, a % b) : b;
}
int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> TC;
    while(TC--){
        cin >> p >> a >> m;
        C.MOD = p;
        if(p < 800){
            bool flag = 0;
            rep(i, 1, p * (p - 1) + 1){
                if((C.pow(i, i) + C.pow(i, m)) % p == a){
                    cout << "TAK " << i << "\n";
                    flag = 1;
                    break;
                }
            }
            if(!flag) cout << "NIE\n";
            continue;
        }
        if(a == 0) {cout << "TAK " << p << "\n"; continue;}
        vector<ll> v;
        ll k = p - 1;
        for(ll i = 2; i * i <= k; i++){
            if(k % i == 0) v.pb((p - 1) / i);
            while(k % i == 0) k /= i;
        }
        sort(all(v));
        rep(i, 1, p){
            bool flag = 0;
            for(auto k: v) {
                if(C.pow(i, k) == 1) {flag = 1; break;}
            }
            if(!flag) {og = i; break;}
        }
        rep(c, 1, INF){
            g = C.pow(og, c);
            if(!(C.pow(g, m) == a || gcd(c, p - 1) != 1)) break;
        }
        ll x = g;
        ll y = discrete_log((p + a - C.pow(x, m)) % p, x);
        ll ans = ((y - x) % (p - 1)) * p + x;
        ans %= p * (p - 1);
        if(ans <= 0) ans += p * (p - 1);
        cout << "TAK " << ans << endl;
    }
}
