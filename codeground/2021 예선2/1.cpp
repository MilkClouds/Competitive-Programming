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

map<ll, ll> M;

void solve(){
    ll N, ans = 1;
    cin >> N;
    rep(i, 1, N) ans += 4 * (--M.lower_bound(N * N - (ll)i * i)) -> y;
    ans += (N - 1) * 4;
    cout << ans << "\n";
}

int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    int TC;
    cin >> TC;
    rep(i, 0, 300000) M[(ll)i * i] = i;
    rep(tc, 0, TC){
        cout << "Case #" << tc + 1 << '\n';
        solve();
    }
}
