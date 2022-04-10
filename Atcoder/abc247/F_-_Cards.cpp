#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define rep2(i,a,b) for(int i = (b) - 1; i >= (a); i--)
#define cinA(A, N) rep(i, 0, N) cin >> A[i];
#define coutA(A, N) rep(i, 0, N) cout << A[i] << " ";
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define eb emplace_back
#define popcount __builtin_popcount
#define popcountll __builtin_popcountll
#define x first
#define y second
using namespace std;
using ll = long long;
using ull = uint64_t;
using ld = long double;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using pl = pair<ll, ll>;
using tl = tuple<ll, ll, ll>;

const int MAX = 2e5, MOD = 998244353;
int N, P[MAX], f[MAX], vis[MAX], ans = 1;
vector<int> adj[MAX];
int dfs(int u){
    if(vis[u]) return 0;
    vis[u] = 1;
    int ret = 1;
    for(auto v: adj[u]) ret += dfs(v);
    return ret;
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N;
    cinA(P, N);
    rep(i, 0, N){
        int x;
        cin >> x;
        adj[x-1].eb(P[i]-1);
        adj[P[i]-1].eb(x-1);
    }
    f[0] = 2; f[1] = 1;
    rep(i, 2, N + 1) f[i] = (f[i - 1] + f[i - 2]) % MOD;
    f[0] = 1;
    rep(i, 0, N){
        ans = ((ll)ans * f[dfs(i)]) % MOD;
    }
    cout << ans << "\n";
}
