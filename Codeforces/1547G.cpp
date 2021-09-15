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

const int MAX = 4e5 + 3;
int N, M, u, v, ans[MAX], dfsn[MAX];
vector<int> adj[MAX];

void dfs(int u, int k){
    if(k == -1) ans[u] = k;
    else if(k == 2 && ans[u] != -1) ans[u] = k;
    else if(ans[u] == 0) ans[u] = k;
    if(k == -1){
        for(auto v: adj[u]) if(ans[v] != -1) dfs(v, k);
    } else if(k == 2){
        for(auto v: adj[u]) if(ans[v] == 1) dfs(v, k);
    } else {
        if(dfsn[u] == 2) dfs(u, 2);
        else if(dfsn[u] == 1) dfs(u, -1);
        else {
            dfsn[u] = 1;
            for(auto v: adj[u]) dfs(v, k);
            dfsn[u] = 2;
        }
    }
}
void solve(){
    cin >> N >> M;
    rep(i, 1, N + 1) adj[i].clear();
    rep(i, 0, M){
        cin >> u >> v;
        adj[u].pb(v);
    }
    fill(dfsn, dfsn + N + 1, 0);
    fill(ans, ans + N + 1, 0);
    dfs(1, 1);
    rep(i, 1, N + 1) cout << ans[i] << " \n"[i == N];
}

int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    int TC;
    cin >> TC;
    while(TC--) solve();
}
