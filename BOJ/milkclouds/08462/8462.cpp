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
using ti = tuple<int, int, int>;
using ld = long double;

const int MAX = 1e5 + 1;
int N, T, A[MAX], l, r, denom;
ll S, M[MAX * 10], ans[MAX];
struct ABC{
    ll l, r, i;
    ABC(): ABC(0, 0, 0) {}
    ABC(ll l, ll r, ll i): l(l), r(r), i(i) {}
    bool operator <(const ABC& o){
        if(l / denom != o.l / denom) return l / denom < o.l / denom;
        return r < o.r;
    }
};
vector<ABC> queries;
inline void insert(ll K){
    K = A[K];
    S += (2 * M[K] + 1) * K;
    M[K]++;
}
inline void remove(ll K){
    K = A[K];
    S -= (2 * M[K] - 1) * K;
    M[K]--;
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N >> T;
    denom = (ll) sqrt(N);
    rep(i, 0, N) cin >> A[i];
    rep(i, 0, T){
        cin >> l >> r; l--; r--;
        queries.eb(l, r, i);
    }
    sort(all(queries));
    l = queries[0].l;
    r = queries[0].r;
    rep(i, l, r + 1) insert(i);
    for(auto& tmp: queries){
        ll l2, r2, ii;
        l2 = tmp.l;
        r2 = tmp.r;
        ii = tmp.i;
        rep(i, l, l2){
            remove(i);
        }
        rep(i, l2, l){
            insert(i);
        }
        rep(i, r, r2){
            insert(i + 1);
        }
        rep(i, r2, r){
            remove(i + 1);
        }
        ans[ii] = S;
        l = l2;
        r = r2;
    }
    rep(i, 0, T) cout << ans[i] << "\n";
}
