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

struct GRP{
    GRP(): GRP(5, 0, 0, 0, 0) {}
    GRP(int S, ll a, ll b, ll c, ll d): S(S), a(a), b(b), c(c), d(d) {}
    int S;
    ll a, b, c, d;
    bool operator < (const GRP& other) const {
        return c + d > other.c + other.d;
    }
};
vector<GRP> odd, even;
int N, M, S;
void solve(){
    ll ret = 6e18;
    ll ans = 0;
    cin >> N >> M;
    odd.clear();
    even.clear();
    rep(i, 0, N){
        cin >> S;
        auto& v = S % 2 ? odd : even;
        vector<ll> V(S);
        rep(j, 0, S) cin >> V[j];
        sort(all(V));
        v.eb(S, V[0], V[1], V[2], V[3]);
    }
    for(auto& grp: odd) ans += grp.a * 2 + grp.b + grp.c + grp.d;
    for(auto& grp: even) ans += grp.a + grp.b + grp.c + grp.d;
    sort(all(odd));
    sort(all(even));
    if(odd.size() >= 2){
        ans -= odd[0].c + odd[0].d + odd[1].c + odd[1].d;
        if(even.empty()){
            ret = min(ret, ans); 
        } else {
            if(odd.size() >= 4){
                ret = min(ret, ans);
            } else {
                ll tmp = 0;
                for(auto& grp: even) tmp += grp.a + grp.b;
                ret = min(ret, ans + tmp);
            }
        }
        ans += odd[0].c + odd[0].d + odd[1].c + odd[1].d;
    }
    if(!odd.empty() && !even.empty()){
        ret = min(ret, ans - (odd[0].c + odd[0].d + even[0].c + even[0].d));
    }
    if(even.size() >= 2){
        ret = min(ret, ans - (even[0].c + even[0].d + even[1].c + even[1].d));
    }
    cout << ret << "\n";
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    int TC;
    cin >> TC;
    rep(tc, 0, TC){
        cout << "Case #" << tc + 1 << '\n';
        solve();
    }
}
