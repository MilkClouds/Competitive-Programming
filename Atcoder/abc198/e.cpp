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

const int MAX = 1e5;
int N, C[MAX], u, v;
vector<int> adj[MAX], ans;
map<int, int> chk;
void dfs(int u, int p){
    if(chk[C[u]] == 0) ans.pb(u);
    chk[C[u]]++;
    for(auto v: adj[u]){
        if(v == p) continue;
        dfs(v, u);
    }
    chk[C[u]]--;
}
int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N;
    rep(i, 0, N) cin >> C[i];
    rep(i, 1, N){
        cin >> u >> v; u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(0, -1);
    sort(all(ans));
    for(auto u: ans) cout << u + 1 << "\n";
}
