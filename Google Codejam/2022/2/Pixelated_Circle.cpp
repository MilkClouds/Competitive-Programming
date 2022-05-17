# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i = (a); i < (b); i++)
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

ll _sqrt(ll x){
    ll j = 0;
    for(ll i = 20; ~i; i--) if((j + (1LL << i)) * (j + (1LL << i)) <= x) j += 1 << i;
    return j;
}
ll roundsqrt(ll x){
    if(x < 0) return -1;
    ll s = _sqrt(x);
    return s + (x > s * s + s);
}
ll count(ll R){
    if(R == 0) return 1;
    ll l = 0;
    for(ll i = 20; ~i; i--) {
        l += 1LL << i;
        if(roundsqrt(R * R - l * l) < l) l -= 1LL << i;
    }
    return 4 * (2 * l + (roundsqrt(R * R - l * l) > l));
}
void solve(){
    ll R, C = 0;
    cin >> R;
    rep(i, -R, R + 1) C += 2 * _sqrt(R * R + R - i * i) + 1;
    // rep(x, 1, R + 1){
    //     ll y = 0;
    //     for(ll i = 20; ~i; i--){
    //         y += 1LL << i;
    //         if(roundsqrt(x * x + y * y) > R) y -= 1LL << i;
    //     }
    //     C += ++y * 4;
    // }
    rep(i, 0, R + 1) C -= count(i);
    cout << C << "\n";
}

int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    int TC;
    cin >> TC;
    rep(tc, 0, TC){
        cout << "Case #" << tc + 1 << ": "; solve();
    }
}