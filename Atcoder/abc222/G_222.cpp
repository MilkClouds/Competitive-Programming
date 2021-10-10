#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define rep2(i,a,b) for(int i = (b) - 1; i >= (a); i--)
#define cinA(A, N) rep(i, 0, N) cin >> A[i];
#define coutA(A, N) rep(i, 0, N) cout << A[i] << " ";
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
using ll = int64_t;
using ull = uint64_t;
using ld = long double;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using pl = pair<ll, ll>;
using tl = tuple<ll, ll, ll>;


int TC, N;

const ll MAX = 1e5;
vector<ll> pn;
ll arr[MAX], MOD;

void eratos() {
	for (ll i = 2; i < MAX; i++) {
		if (arr[i]) continue;
		pn.push_back(i);
		for (ll j = i; j < MAX; j += i) arr[j] = i;
	}
}
ll euler_phi(ll x){
    ll ret = x;
    for(auto p: pn) if(x % p == 0){
        while(x % p == 0) x /= p;
        ret -= ret / p;
    }
    if(x != 1) ret -= ret / x;
    return ret;
}
vector<ll> divisors(ll n){
    vector<ll> div;
    rep(p, 1, (ll)sqrt(n) + 1) if(n % p == 0){
        div.eb(p);
        if(p != n / p) div.eb(n / p);
    }
    sort(all(div));
    return div;
}
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
    eratos();
    while(TC--){
        ll ans = -1;
        cin >> N;
        ll M = N % 2 ? 9 * N : 9 * N / 2;
        MOD = M;
        for(auto i: divisors(euler_phi(M))){
            if(poww(10, i) == 1){
                ans = i;
                break;
            }
        }
        cout << ans << '\n';
    }
}
