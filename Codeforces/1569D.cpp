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

const int MAX = 2e5 + 1;
int TC, N, M, K, x, y;
vector<int> xs, ys;
multiset<int> xss[MAX], yss[MAX];
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> TC;
    while(TC--){
        ll ans = 0;
        cin >> N >> M >> K;
        rep(i, 0, M) xss[i].clear();
        rep(i, 0, N) yss[i].clear();
        xs.resize(N);
        ys.resize(M);
        rep(i, 0, N) cin >> xs[i];
        rep(i, 0, M) cin >> ys[i];
        rep(i, 0, K){
            cin >> x >> y;
            bool a = *lower_bound(all(xs), x) == x;
            bool b = *lower_bound(all(ys), y) == y;
            int xn = lower_bound(all(xs), x) - xs.begin();
            int yn = lower_bound(all(ys), y) - ys.begin();
            if(a && b) continue;
            if(a){
                xss[yn].insert(xn);
            } else yss[xn].insert(yn);
        }
        rep(i, 0, M) ans += (ll) xss[i].size() * (xss[i].size() - 1) / 2;
        rep(i, 0, M){
            map<int, int> MM;
            for(auto j: xss[i]) MM[j]++;
            for(auto [_, j]: MM) ans -= (ll) j * (j - 1) / 2;
        }
        rep(i, 0, N) ans += (ll) yss[i].size() * (yss[i].size() - 1) / 2;
        rep(i, 0, N){
            map<int, int> MM;
            for(auto j: yss[i]) MM[j]++;
            for(auto [_, j]: MM) ans -= (ll) j * (j - 1) / 2;
        }
        cout << ans << "\n";
    }
}