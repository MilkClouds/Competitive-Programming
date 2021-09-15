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

const int MAX = 505;
int N, M, K, u, v, vis[MAX], fin[MAX], cnt;
bool cycle;
char ans[MAX * 4];
stack<int> S;
vector<int> adj[MAX];
int dfs(int u){
    vis[u] = ++cnt;
    S.push(u);
    int res = vis[u];
    for(auto v: adj[u]){
        if(vis[v] == 0) res = min(res, dfs(v));
        else if(!fin[v]) {
            cycle = 1;
            res = min(res, vis[v]);
        }
    }
    if(res == vis[u]){
        while(1){
            int t = S.top(); S.pop();
            fin[t] = 1;
            if(t == u) break;
        }
    }
    return res;
}
inline bool query(){
    fill(vis, vis + N, 0);
    fill(fin, fin + N, 0);
    cnt = cycle = 0;
    rep(i, 0, N) if(vis[i] == 0) dfs(i);
    return cycle;
}
void solve(){
    cin >> N >> M >> K;
    rep(i, 0, N) adj[i].clear();
    fill(ans, ans + K + 1, 0);
    rep(i, 0, M){
        cin >> u >> v; u--; v--;
        adj[u].eb(v);
    }
    rep(i, 0, K){
        cin >> u >> v; u--; v--;
        adj[u].eb(v);
        if(query()){
            assert(adj[u].size() > 0);
            adj[u].erase(--adj[u].end());
            adj[v].eb(u);
            ans[i] = '1';
        } else ans[i] = '0';
    }
    cout << ans << "\n";
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
