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

const int MAX = 501;
int N, M, u, v, tc, vis[MAX];
vector<int> adj[MAX];
int dfs(int u, int par){
    if(vis[u]) return 0;
    int ret = 1;
    vis[u] = 1;
    for(auto v: adj[u]){
        if(v == par) continue;
        ret &= dfs(v, u);
    }
    return ret;
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    while(cin >> N >> M, N){
        int ans = 0;
        rep(i, 1, N + 1) adj[i].clear();
        fill(vis, vis + N + 1, 0);
        rep(i, 0, M) cin >> u >> v, adj[u].eb(v), adj[v].eb(u);
        rep(i, 1, N + 1) ans += dfs(i, 0);
        cout << "Case " << ++tc << ": ";
        if(ans == 0) cout << "No trees.\n";
        else if(ans == 1) cout << "There is one tree.\n";
        else cout << "A forest of " << ans << " trees.\n";
    }
}
