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

const int MAX = 2e5 + 1, MOD = 998244353;
int H, W, h[2], w[2];
ll ans = 1, inv[MAX], t;
int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> H >> W;
    cin >> h[0] >> w[0] >> h[1] >> w[1];
    if(h[0] > h[1]) swap(h[0], h[1]);
    if(w[0] > w[1]) swap(w[0], w[1]);
    t = h[1] - h[0] + w[1] - w[0];
    inv[1] = 1;
    rep(i, 2, MAX) inv[i] = inv[MOD % i] * (MOD - MOD / i) % MOD;
    for(auto k: {h[0] - 1, H - h[1], w[0] - 1, W - w[1]})
        rep(i, 1, k + 1) ans = (ans + inv[i + t]) % MOD;
    cout << ans << endl;
}
