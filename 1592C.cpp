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
int TC, N, K, A[MAX], ans, S, a;
vector<int> adj[MAX];
int dfs(int u, int par){
    if(u == a) return 0;
    int ret = A[u];
    for(auto v: adj[u]){
        if(v == par) continue;
        ret ^= dfs(v, u);
    }
    if(ret == S) if(ans == -1) ans = u;
    return ret;
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> TC;
    while(TC--){
        S = 0;
        cin >> N >> K;
        rep(i, 0, N) adj[i].clear();
        rep(i, 0, N) cin >> A[i], S ^= A[i];
        rep(i, 1, N){
            int u, v;
            cin >> u >> v; u--; v--;
            adj[u].eb(v);
            adj[v].eb(u);
        }
        if(S == 0){
            cout << "YES\n";
            continue;
        }
        if(K == 2){
            cout << "NO\n";
            continue;
        }
        ans = a = -1;
        dfs(0, -1);
        a = ans;
        ans = -1;
        dfs(0, -1);
        if(~a && ~ans) cout << "YES\n";
        else cout << "NO\n";
    }
}
