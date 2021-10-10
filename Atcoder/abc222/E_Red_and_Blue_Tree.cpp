#include <bits/stdc++.h>
#include <atcoder/modint>
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define rep2(i,a,b) for(int i = (b) - 1; i >= (a); i--)
#define cinA(A, N) rep(i, 0, N) cin >> A[i];
#define coutA(A, N) rep(i, 0, N) cout << A[i] << " ";
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
using mint = atcoder::modint998244353;
using ll = int64_t;
using ull = uint64_t;
using ld = long double;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using pl = pair<ll, ll>;
using tl = tuple<ll, ll, ll>;

int N, M, A[1111], Mx, K;
vector<int> adj[1111];
map<pi, int> MM;
mint poly[222222];
void BFS(int S, int E){
    vector<int> vis(N + 1, 0);
    queue<int> Q; Q.push(S); vis[S] = -1;
    while(!Q.empty()){
        int u = Q.front(); Q.pop();
        if(u == E) break;
        for(auto v: adj[u]){
            if(vis[v]) continue;
            vis[v] = u;
            Q.push(v);
        }
    }
    int u = E;
    while(u != S){
        MM[pi(min(vis[u], u), max(vis[u], u))]++;
        u = vis[u];
    }
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N >> M >> K;
    cinA(A, M);
    rep(i, 1, N){
        int u, v;
        cin >> u >> v;
        adj[u].eb(v);
        adj[v].eb(u);
    }
    rep(i, 1, M){
        BFS(A[i - 1], A[i]);
    }
    poly[0] = 1;
    for(auto [i, j]: MM){
        rep2(k, 0, Mx + 1) poly[k + j] += poly[k];
        Mx += j;
        K += j;
    }
    if(K % 2 || K < 0 || K / 2 > Mx) cout << 0 << endl;
    else{
        poly[K / 2] *= mint(2).pow(N - 1 - MM.size());
        cout << poly[K / 2].val() << endl;
    }
}
