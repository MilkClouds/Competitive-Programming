#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i = (a); i < (b); i++)
#define rep2(i,a,b) for(ll i = (b) - 1; i >= (a); i--)
#define cinA(A, N) rep(i, 0, N) cin >> A[i];
#define coutA(A, N) rep(i, 0, N) cout << A[i] << " ";
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define eb emplace_back
#define popcount __builtin_popcount
#define popcountll __builtin_popcountll
#define x first
#define y second
using namespace std;
using ll = long long;
using ull = uint64_t;
using ld = long double;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using pl = pair<ll, ll>;
using tl = tuple<ll, ll, ll>;

void solve(){
    int N, M, u, v;
    cin >> N >> M;
    vector<vector<int>> adj(N, vector<int>());
    vector<int> vis(N, -1), cnt(N), Q, par;
    rep(i, 0, M){
        cin >> u >> v; u--; v--;
        adj[u].eb(v);
        adj[v].eb(u);
    }
    function<void(int, int)> dfs = [&](int u, int color){
        vis[u] = color;
        Q.pb(u);
        for(auto v: adj[u]) {
            if(~vis[v]) par[v] = u, dfs(v, color ^ 1);
            else {
                if(vis[u] == vis[v]) cnt[u]++, cnt[v]--;
            }
        }
    };
    dfs(0, 0);
    for(auto u: Q){
        cnt[par[u]] += cnt[u];
    }
    rep(i, 0, N) cout << cnt[i] << " ";
    cout << "\n";
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    int TC;
    cin >> TC;
    while(TC--) solve();
}
