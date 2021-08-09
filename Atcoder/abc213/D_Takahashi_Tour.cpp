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

const int MAX = 2e5 + 10;
int N, u, v, vis[MAX];
set<int> adj[MAX];
void dfs(int u, int pre){
    adj[u].erase(pre);
    adj[pre].erase(u);
    vis[u] = pre;
    cout << u << " ";
    for(auto v: adj[u]){
        if(vis[v]) continue;
        dfs(v, u);
        return;
    }
    if(u == 1) return;
    dfs(pre, vis[pre]);
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N;
    rep(i, 1, N){
        cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    dfs(1, 1);
}
