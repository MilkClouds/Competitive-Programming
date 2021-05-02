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

const int MAX = 2e5 + 1;
int N, u, v, dfsn[MAX], dist[MAX], cnt, pre[MAX], ban[MAX];
vector<int> adj[MAX];
void dfs1(int u, int prev){
    pre[u] = prev;
    dist[u] = dist[prev] + 1;
    for(auto v: adj[u]){
        if(v == prev) continue;
        dfs1(v, u);
    }
}
void dfs2(int u, int prev){
    dfsn[u] = ++cnt;
    for(auto v: adj[u]){
        if(v == prev) continue;
        if(ban[v]) continue;
        dfs2(v, u);
    }
    for(auto v: adj[u]){
        if(v == prev) continue;
        if(ban[v]) dfs2(v, u);
    }
    cnt++;
}
int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N;
    rep(i, 1, N){
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs1(1, 0);
    u = max_element(dist, dist + N) - dist;
    fill(dist, dist + N, 0);
    dfs1(u, 0);
    v = max_element(dist, dist + N) - dist;
    int tmp = v;
    while(tmp != u){
        ban[tmp] = 1;
        tmp = pre[tmp];
    }
    dfs2(u, 0);
    rep(i, 0, N) cout << dfsn[i + 1] << " ";
}
