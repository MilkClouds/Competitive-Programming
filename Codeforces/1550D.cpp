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

const int MOD = 1e9 + 7;
void solve(){
    int N, L, R;
    cin >> N >> L >> R;
    vector<pi> ev, evp, evn, evt;
    rep(i, 1, N + 1){
        ev.eb(L - i, 1);
        ev.eb(R - i + 1, -1);
    }
    sort(all(ev));
    int tmp = 0;
    for(auto p: ev){
        tmp += p.y;
        if(p.x > 0) evp.eb(p.x, tmp);
        else if(p.x < 0) evt.eb(p.x, tmp);
    }
    rep2(i, 0, N){
        if(i)evn.eb(-evt[i].x + 1, evt[i - 1].y);
        else evn.eb(-evt[i].x + 1, 0);
    }
    rep(i, 0, N) cout << evp[i].x << " " << evp[i].y << endl;
}

int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    int TC;
    cin >> TC;
    while(TC--) solve();
}
