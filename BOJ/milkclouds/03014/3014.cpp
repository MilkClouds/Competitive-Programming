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
#define x first
#define y second
using namespace std;
using ll = long long;
using tl = tuple<ll, ll, ll, ll>;
using pl = pair<ll, ll>;
using pi = pair<int, int>;
using ld = long double;

const int MAX = 1e5 + 5;
int N, M, u, v, dfsn[MAX], low[MAX], cnt;
vector<int> adj[MAX];
stack<int> S;
void dfs(int u, int par){
    dfsn[u] = ++cnt;
    low[u] = dfsn[u];
    S.push(u);
    for(auto v: adj[u]){
        if(v == par) continue;
        if(low[v]) low[u] = min(low[u], low[v]);
        else {
            dfs(v, u);
            if(low[v] < dfsn[u]) low[u] = min(low[u], low[v]);
            else if(low[v] == dfsn[u]) {
                ringu[u].pb(rings);
                do {
                    ring[rings].pb(S.top()); S.pop();
                } while(ring[rings].back() != v)
            }
        }
    }
}
int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N >> M;
    rep(i, 0, M) {
        cin >> u >> v; u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

}
