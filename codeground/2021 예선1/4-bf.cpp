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
    int S;
    vector<int> v;
};
int N, M;
void solve(){
    ll an = 12353561513;
    cin >> N >> M;
    vector<GRP> v(N);
    rep(i, 0, N){
        cin >> v[i].S;
        v[i].v.assign(v[i].S, 0);
        rep(j, 0, v[i].S) cin >> v[i].v[j];
        sort(all(v[i].v));
    }
    vector<int> P(N);
    rep(i, 0, N) P[i] = i;
    do{
        ll ans = 0, S = 0;
        int i = 0;
        ans += v[P[i]].v[0] + v[P[i]].v[1];
        if(v[P[i]].S & 1) ans += v[P[i]].v[0];
        rep(i, 1, N) {
            S += v[P[i - 1]].S;
            if(S % 2 == 0) {
                ans += v[P[i]].v[2] + v[P[i]].v[3];
                ans += v[P[i]].v[0] + v[P[i]].v[1];
                if(v[P[i]].S & 1) ans += v[P[i]].v[0];
            } else {
                ans += v[P[i]].v[0] * 2 + v[P[i]].v[3];
                ans += v[P[i]].v[1] + v[P[i]].v[2];
                if(v[P[i]].S % 2 == 0) ans += v[P[i]].v[1];
            }
        }
        ans -= v[P[N - 1]].v[2] +v[P[N - 1]].v[3];
        an = min(an, ans);
        // if(P[0] == 3 && P[N - 1] == 0 && v[P[1]].S % 2 && v[P[N - 2]].S % 2){
        //     cout << "!" << ans << endl;
        //     rep(i, 0, N) cout << P[i] << " " << v[P[i]].S << endl;
        // }
    } while(next_permutation(all(P)));
    cout << an << "\n";
}


void solve_BF(){
    ll an = 6e18;
    vector<int> P(N);
    rep(i, 0, N) P[i] = i;
    do{
        ll ans = 0, S = 0;
        int i = 0;
        ans += v[P[i]].v[0] + v[P[i]].v[1];
        if(v[P[i]].S & 1) ans += v[P[i]].v[0];
        rep(i, 1, N) {
            S += v[P[i - 1]].S;
            if(S % 2 == 0) {
                ans += v[P[i]].v[2] + v[P[i]].v[3];
                ans += v[P[i]].v[0] + v[P[i]].v[1];
                if(v[P[i]].S & 1) ans += v[P[i]].v[0];
            } else {
                ans += v[P[i]].v[0] * 2 + v[P[i]].v[3];
                ans += v[P[i]].v[1] + v[P[i]].v[2];
                if(v[P[i]].S % 2 == 0) ans += v[P[i]].v[1];
            }
        }
        ans -= v[P[N - 1]].v[2] +v[P[N - 1]].v[3];
        an = min(an, ans);
        // if(P[0] == 3 && P[N - 1] == 0 && v[P[1]].S % 2 && v[P[N - 2]].S % 2){
        //     cout << "!" << ans << endl;
        //     rep(i, 0, N) cout << P[i] << " " << v[P[i]].S << endl;
        // }
    } while(next_permutation(all(P)));
    cout << an << "\n";
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
