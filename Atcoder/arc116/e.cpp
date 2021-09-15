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

const int MAX = 2e5, INF = 1e9;
int N, K, u, v, a[MAX], b[MAX], cnt, d;
vector<int> adj[MAX];
void dfs(int u, int prev){
    a[u] = INF; b[u] = 0;
    for(auto v: adj[u]){
        if(v ^ prev){
            dfs(v, u);
            a[u] = min(a[u], a[v] + 1);
            b[u] = max(b[u], b[v] + 1);
        }
    }
    if(a[u] + b[u] <= d) b[u] = -INF;
    else if(b[u] == d) b[u] = -INF, a[u] = 0, ++cnt;
}
bool valid(){
    cnt = 0;
    dfs(0, -1);
    if(b[0] >= 0) ++cnt;
    return cnt <= K;
}
int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N >> K;
    rep(i, 1, N){
        cin >> u >> v; u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int l = 0, r = N;
    while(l + 1 < r){
        d = l + r + 1 >> 1;
        (valid() ? r : l) = d;
    }
    cout << r << endl;
}
