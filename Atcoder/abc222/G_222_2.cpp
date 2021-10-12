#include <bits/stdc++.h>
#include <atcoder/modint>
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define rep2(i,a,b) for(int i = (b) - 1; i >= (a); i--)
using namespace std;
using namespace atcoder;
using ll = long long;

ll TC, N, M, big;

const ll MAX = 3e4 + 1;
vector<ll> pn;
ll arr[MAX];

void eratos() {
	for (ll i = 2; i < MAX; i++) {
		if (arr[i]) continue;
		pn.push_back(i);
		for (ll j = i; j < MAX; j += i) arr[j] = i;
	}
}
ll euler_phi(ll x){
    ll ret = x;
    for(auto p: pn) {
        if(p * p > x) break;
        if(x % p == 0){
            while(x % p == 0) x /= p;
            ret -= ret / p;
        }
    }
    if(x != 1) ret -= ret / x;
    return ret;
}

int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> TC;
    eratos();
    while(TC--){
        ll ans = 1e9;
        unordered_map<int, int> p, q;
        cin >> N;
        M = N * 9;
        if((N & 1) == 0) M >>= 1;
        // 10 ^ n = 1 (mod M)
        if(gcd(10, M) > 1){
            cout << "-1\n";
            continue;
        }
        big = sqrt(M);
        ll phi = euler_phi(M);
        modint::set_mod(M);
        auto tmp = modint(10).pow(big * (phi - 1));
        rep2(i, 0, M / big){
            p[tmp.pow(i).val()] = i;
        }
        rep2(i, 1, big + 1){
            ll tmp = modint(10).pow(i).val();
            if(p.find(tmp) != p.end()) ans = min(ans, i + big * p[tmp]);
        }
        cout << ans << "\n";
    }
}
