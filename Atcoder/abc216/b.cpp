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

const int MAX = 1e5 + 10;
int N, M, u, v;
bool vis[MAX];
pi deg[MAX];
vector<int> adj[MAX], ans;
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N >> M;
    rep(i, 0, N) deg[i].y = i;
    rep(i, 0, M){
        cin >> u >> v; u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
        deg[u].x++; deg[v].x++;
    }
    sort(deg, deg + N);
    rep(i, 0, N){
        int u = deg[i].y;
        if(vis[u]) continue;
        vis[u] = 1;
        ans.eb(u);
        for(auto& v: adj[u]){
            vis[v] = 1;
        }
    }
    cout << ans.size() << "\n";
    for(auto i: ans) cout << i + 1 << " ";
}
