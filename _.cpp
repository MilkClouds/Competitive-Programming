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

const int MAX = 1e5 + 1, INF = 1e9;
int N, M, u, v;
set<int> adj[MAX];
vector<int> V[MAX];

int S[MAX], cycle[MAX], cycles;
set<pi> isCut;
int dfs(int u, int pre, int nth = 0){
    S[u] = ++nth;
    int ret = S[u];
    for(auto v: adj[u]){
        if(v == pre) continue;
        if(S[v] == 0){
            int child = dfs(v, u, nth);
            if(S[u] < child) isCut.emplace(min(u, v), max(u, v));
            ret = min(ret, child);
        }
        else ret = min(ret, S[v]);
    }
    return ret;
}
// void dfs2(int u, int nth = 0){
//     if(isCut[u]) cycles++;
//     cycle[u] = cycles;
//     V[cycles].eb(u);
//     S[u] = ++nth;
//     for(auto v: adj[u]){
//         if(S[v] == 0) dfs2(v, nth);
//     }
// }
int dp[MAX][2][2];
int solve(int u, bool croot, bool here){
    int& ans = dp[u][croot][here];
    if(~ans) return ans;
    if(croot && adj[V[cycle[u]][0]].count(u)){
        if(here) return ans = -INF;
    }
    ans = 0;
    for(auto v: adj[u]){
        if(cycle[u] ^ cycle[v]){
            if(!here) ans = max(ans, solve(v, 1, 1));
            ans = max(ans, solve(v, 0, 0));
        } else {
            if(!here) ans = max(ans, solve(v, croot, 1));
            ans = max(ans, solve(v, croot, 0));
        }
    }
    return ans += here;
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N >> M;
    rep(i, 0, M){
        cin >> u >> v; u--; v--;
        adj[u].em(v);
        adj[v].em(u);
    }
    rep(i, 0, N) if(S[i] == 0) dfs(i, -1);
    for(auto [u, v]: isCut) cout << u << " " << v << endl;
    fill(S, S + N, 0);
    // rep(i, 0, N) if(S[i] == 0) dfs2(i);
    // cout << isCut[0] << endl;
    cout << solve(0, 0, 0) << endl;
    cout << solve(0, 1, 1) << endl;
}
