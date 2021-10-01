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

const int MAX = 2e5;
int N, des[MAX];
ll dSum[MAX], ans[MAX];
vector<int> adj[MAX];
void dfs(int u, int par){
    des[u] = 1;
    for(auto v: adj[u]){
        if(v == par) continue;
        dfs(v, u);
        des[u] += des[v];
        dSum[u] += dSum[v] + des[v];
    }
}
void calc(int u, int par){
    for(auto v: adj[u]){
        if(v == par) continue;
        ans[v] = ans[u] - (des[v] - 1) + (N - des[v] - 1);
        calc(v, u);
    }
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N;
    rep(i, 1, N){
        int u, v;
        cin >> u >> v; u--; v--;
        adj[u].eb(v);
        adj[v].eb(u);
    }
    dfs(0, -1);
    ans[0] = dSum[0];
    calc(0, -1);
    rep(i, 0, N) cout << ans[i] << "\n";
}
