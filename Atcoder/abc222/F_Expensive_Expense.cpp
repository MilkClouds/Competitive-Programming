#include <bits/stdc++.h>
#include <atcoder/segtree>
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
using namespace atcoder;
using ll = int64_t;
using ull = uint64_t;
using ld = long double;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using pl = pair<ll, ll>;
using tl = tuple<ll, ll, ll>;

const int MAX = 2e5;
const ll INF = 1e18;
vector<pi> adj[MAX];
int N, D[MAX];

vector<ll> dijkstra(ll S) {
    priority_queue<pl> pq;
    vector<ll> dist(N, INF);
    dist[S] = 0;
    pq.push({ 0, S });
    while (!pq.empty()) {
        ll d, u;
        tie(d, u) = pq.top(); pq.pop(); d *= -1;
        if(d != dist[u]) continue;
        for (auto [v, d] : adj[u]) {
            ll nd = dist[u] + d;
            if (dist[v] > nd) {
                dist[v] = nd;
                pq.push({ -nd, v });
            }
        }
    }
    return dist;
}

int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N;
    rep(i, 1, N){
        int u, v, c;
        cin >> u >> v >> c; u--; v--;
        adj[u].eb(v, c);
        adj[v].eb(u, c);
    }
    cinA(D, N);
    int k = 0, s = -1, t = -1;
    {
        auto&& dk = dijkstra(k);
        ll cost = -1;
        rep(i, 0, N){
            if(i == k) continue;
            if(D[i] + dk[i] > cost){
                cost = D[i] + dk[i];
                s = i;
            }
        }
    }
    {
        auto&& ds = dijkstra(s);
        ll cost = -1;
        rep(i, 0, N){
            if(i == s) continue;
            if(D[i] + ds[i] > cost){
                cost = D[i] + ds[i];
                t = i;
            }
        }
    }
    auto&& ds = dijkstra(s);
    auto&& dt = dijkstra(t);
    rep(i, 0, N){
        ll cost = -1;
        if(i != s) cost = max(cost, ds[i] + D[s]);
        if(i != t) cost = max(cost, dt[i] + D[t]);
        cout << cost << "\n";
    }
}
