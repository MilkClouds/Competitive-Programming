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

// from 5:55
const int MAX = 20005, INF = 1e9;
int TC;
int N, k, m;
vector<int> Q[MAX];
pi A[MAX], p;
vector<pi> adj[MAX];
vector<int> dist[MAX];
void solve(int S){
    dist[S].assign(MAX, INF);
    dist[S][S] = 0;
    deque<int> Q; Q.push_back(S);
    while(!Q.empty()){
        auto u = Q.front(); Q.pop_front();
        for(auto tmp: adj[u]){
            auto v = tmp.x; auto d = tmp.y;
            if(dist[S][v] > dist[S][u] + d){
                dist[S][v] = dist[S][u] + d;
                if(d == 1) Q.push_back(v);
                else Q.push_front(v);
            }
        }
    }
}
void solve(){
    ll ans = 0;
    cin >> N >> k >> m;
    rep(i, 1, 2 * N + 4 * k + 1) adj[i].clear();
    rep(i, 1, N + 1){
        Q[i].clear();
        Q[i].pb(i);
    }
    rep(i, 1, k + 1) {
        cin >> A[i].x >> A[i].y;
        if(A[i].x > A[i].y) swap(A[i].x, A[i].y);
        Q[A[i].x].pb(2 * N + 4 * i - 3);
        Q[A[i].x].pb(2 * N + 4 * i - 2);
        Q[A[i].y].pb(2 * N + 4 * i - 1);
        Q[A[i].y].pb(2 * N + 4 * i - 0);
        adj[2 * N + 4 * i - 3].eb(2 * N + 4 * i - 2, 1);
        adj[2 * N + 4 * i - 1].eb(2 * N + 4 * i - 0, 1);
        adj[2 * N + 4 * i - 3].eb(2 * N + 4 * i - 0, 0);
        adj[2 * N + 4 * i - 1].eb(2 * N + 4 * i - 2, 0);
    }
    rep(i, 1, N + 1){
        Q[i].pb(N + i);
        rep(j, 1, Q[i].size()){
            if(Q[i][j] % 2 == 0 && Q[i][j - 1] + 1 == Q[i][j]) continue;
            adj[Q[i][j - 1]].eb(Q[i][j], 0);
        }
    }
    rep(i, 1, N + 1) solve(i);
    while(m--){
        cin >> p.x >> p.y; p.y += N;
        ans += dist[p.x][p.y] < INF ? dist[p.x][p.y] : -1;
    }
    cout << ans << "\n";
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> TC;
    rep(tc, 1, TC + 1){
        cout << "Case #" << tc << "\n";
        solve();
    }
}
