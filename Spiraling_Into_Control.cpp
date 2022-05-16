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

void solve(){
    ll N, K;
    cin >> N >> K;
    if(K % 2 || K < (N - 1)){
        cout << "IMPOSSIBLE\n";
        return;
    }
    ll lft = N * N - 1 - K;
    vector<pl> ans;
    rep(i, 0, N / 2){
        // 4 * (N - i) - 6
        rep(j, 0, 4){
            ll t = 4 * (N - i * 2) - 6 - 2 * j;
            if(t == 0) break;
            if(lft >= t){
                lft -= t;
                ll r = 1 + 4 * (i * N - i * i) + (N - 2 * i - 1) * j + 1;
                ans.eb(r, r + t + 1);
                break;
            }
        }
    }
    cout << ans.size() << "\n";
    for(auto [i, j]: ans) cout << i << " " << j << "\n";
    ll tmp = 0;
    for(auto [i, j]: ans) tmp += j - i - 1;
    assert(tmp == N * N - 1 - K);
}

int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    int TC;
    cin >> TC;
    rep(tc, 0, TC){
        cout << "Case #" << tc + 1 << ": "; solve();
    }
}

