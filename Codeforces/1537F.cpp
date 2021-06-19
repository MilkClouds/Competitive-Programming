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
using ld = long double;

const int MAX = 2e5;
int TC, N, M, V[MAX], a, u, v, vis[MAX];
vector<int> adj[MAX];
ll S;
void dfs(int u, int type){
    vis[u] = type;
    S += type ? V[u]: -V[u];
    for(auto v: adj[u]){
        if(~vis[v]) continue;
        dfs(v, type ^ 1);
    }
}
bool solve(){
    cin >> N >> M;
    rep(i, 0, N) adj[i].clear();
    fill(vis, vis + N, -1);
    S = 0;
    rep(i, 0, N) cin >> V[i];
    ll tot = 0;
    rep(i, 0, N) {
        cin >> a;
        V[i] = a - V[i];
        tot += V[i];
    }
    rep(i, 0, M){
        cin >> u >> v; u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    if(tot % 2) return 0;
    dfs(0, 0);
    rep(u, 0, N){
        for(auto v: adj[u]){
            if(vis[u] == vis[v]) return 1;
        }
    }
    return S == 0;
}

int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> TC;
    while(TC--) cout << (solve() ? "YES" : "NO") << "\n";
}
