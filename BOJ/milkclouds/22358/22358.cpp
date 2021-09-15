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

const int MAX = 1e5 + 1;
const ll INF = 6e18;
int N, M, K, S, T, u, v, t;
ll dp[MAX][11];
vector<pl> adj[MAX], adjr[MAX];
ll solve(int u, int k){
    ll& ret = dp[u][k];
    if(ret < INF) return ret;
    if(u == T) ret = 0;
    if(k){
        for(auto v: adjr[u]){
            ret = min(ret, solve(v.x, k - 1));
        }
    }
    for(auto v: adj[u]){
        ret = min(ret, solve(v.x, k) + v.y);
    }
    return ret;
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N >> M >> K >> S >> T;
    fill(dp[0], dp[N + 1], INF);
    rep(i, 0, M){
        cin >> u >> v >> t; t *= -1;
        adj[u].eb(v, t);
        adjr[v].eb(u, t);
    }
    ll tmp = solve(S, K);
    if(tmp > INF / 2) cout << -1;
    else cout << -tmp;
    cout << endl;
}
