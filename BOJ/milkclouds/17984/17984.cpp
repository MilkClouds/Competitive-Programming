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
int N, u, v;
vector<int> adj[MAX];
void dfs(int u, int par, int l = 0, int r = 0){
    int i = 0;
    for(; i < adj[u].size(); i++){
        int v = adj[u][i];
        if(v == par) continue;
        if(l < adj[u].size() / 2){
            dfs(v, u, 0, 1); l++;
        } else break;
    }
    cout << u << " ";
    for(; i < adj[u].size(); i++){
        int v = adj[u][i];
        if(v == par) continue;
        dfs(v, u, 1, 0);
    }
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N;
    rep(i, 1, N){
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(0, -1);
}
