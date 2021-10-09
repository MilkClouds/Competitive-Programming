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

int N, l, r, M;
vector<pi> edges;
set<int> adj[1001];
void dfs(int u, int par){
    for(auto v: adj[u]){
        if(v == par) continue;
        edges.eb(u, v);
        dfs(v, u);
    }
}
int query(int l, int r){
    set<int> S;
    rep(i, l, r) S.em(edges[i].x), S.em(edges[i].y);
    cout << "? " << S.size() << " ";
    for(auto i: S) cout << i << " ";
    cout << endl;
    int i;
    cin >> i;
    return i;
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N;
    rep(i, 1, N){
        int u, v;
        cin >> u >> v;
        adj[u].em(v);
        adj[v].em(u);
    }
    dfs(1, 0);
    l = 0; r = edges.size();
    M = query(l, r);
    while(r - l > 1){
        int m = l + r >> 1;
        if(query(l, m) == M) r = m;
        else l = m;
    }
    cout << "! " << edges[l].x << " " << edges[l].y << endl;
}
