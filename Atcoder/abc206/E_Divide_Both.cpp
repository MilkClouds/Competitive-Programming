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

ll L, R;
map<pl, ll> fC, gC;
ll g(ll L, ll R);
ll f(ll L, ll R){
    if(L == R) return 0;
    if(fC.find({L, R}) != fC.end()) return fC[{L, R}];
    ll ans = 0;
    rep(p, 2, R + 1){
        ll tL = max(2LL, (L + p - 1) / p);
        ll tR = R / p;
        ans += g(tL, tR);
    }
    return fC[{L, R}] = ans;
}
ll g(ll L, ll R){
    if(L == R) return 0;
    if(gC.find({L, R}) != gC.end()) return gC[{L, R}];
    ll dm = 0, ret = (ll) (R - L + 1) * (R - L) / 2;
    rep(i, L, R + 1){
        ll tmp = R / i - 1;
        if(tmp <= 0) break;
        dm += tmp;
    }
    ret -= dm;
    ret -= f(L, R);
    return gC[{L, R}] = ret;
}

int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> L >> R;
    cout << f(L, R) * 2 << endl;
}
