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
using pl = pair<ll, ll>;
using tl = tuple<ll, ll, ll>;

const ll INF = numeric_limits<ll>::max();
ll R, C, K, a, b, c, d, n, m;
ll calc(pi a){
    return (a.x + K - 1) / K - (a.y + K - 1) / K;
}
ll solve(){
    cin >> R >> C >> K;
    cin >> a >> b >> c >> d; a--; b--;
    n = c - a;
    m = d - b;
    ll ans = n * m - 1 + ((n - 1) / K) * ((m - 1) / K), tmp = 0, ret = INF;
    if(a) tmp += (m + K - 1) / K;
    if(b) tmp += (n + K - 1) / K;
    if(c < R) tmp += (m + K - 1) / K;
    if(d < C) tmp += (n + K - 1) / K;
    if(a && c < R){
        ret = min(ret, min(calc({d, m}), calc({C - b, m})));
    }
    if(b && d < C){
        ret = min(ret, min(calc({c, n}), calc({R - a, n})));
    }
    if(ret == INF) ret = 0;
    return ans += ret + tmp;
}

int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    int TC;
    cin >> TC;
    rep(tc, 0, TC){
        cout << "Case #" << tc + 1 << ": " << solve() << "\n";
    }
}

