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

const int MAX = 1e5 + 11;
ll N, u, v, dfsn[MAX], ans;
vector<int> adj[MAX], vv;
string S;
void dfs(int u){
    if(S[u] == 'B' || dfsn[u]) return;
    vv.pb(u);
    dfsn[u] = 1;
    for(auto v: adj[u]) dfs(v);
}

int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N;
    rep(i, 1, N){
        cin >> u >> v; u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    cin >> S;
    rep(i, 0, N) {dfs(i);for(auto u: vv) dfsn[u] = vv.size(); vv.clear();}
    rep(i, 0, N){
        if(S[i] != 'B') continue;
        for(auto v: adj[i]) ans += dfsn[v];
    }
    cout << ans << endl;
}
