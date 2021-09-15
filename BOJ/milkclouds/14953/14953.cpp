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

const int MAX = 1e5;
int N, M, u, v, deg[MAX], ans, dp[MAX];
vector<int> adj[MAX];
int dfs(int u){
    int& ret = dp[u];
    if(ret) return ret;
    for(auto v: adj[u]){
        if(deg[v] <= deg[u]) continue;
        ret = max(ret, dfs(v));
    }
    return ++ret;
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N >> M;
    rep(i, 0, M){
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
        deg[u]++; deg[v]++;
    }
    rep(i, 0, N) ans = max(ans, dfs(i));
    cout << ans << "\n";
}
