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

const int MAX = 401, INF = 1e9;
using ABC = array<array<int, MAX>, MAX>;
int N, M, u, v, ans[MAX * MAX];
ABC d;
pi Edges[MAX * MAX];
set<int> adj[MAX];
vector<int> dijkstra(int S) {
    priority_queue<pi> pq;
    vector<int> dist(N + 1, INF);
    dist[S] = 0;
    pq.push({ 0, S });
    while (!pq.empty()) {
        int d, u;
        tie(d, u) = pq.top(); pq.pop();
        if(-d != dist[u]) continue;
        for (auto v : adj[u]) {
            int nd = dist[u] + 1;
            if (dist[v] > nd) {
                dist[v] = nd;
                pq.push({ -nd, v });
            }
        }
    }
    return dist;
}
void compile(ABC& d){
    rep(m, 1, N + 1) rep(s, 1, N + 1) rep(e, 1, N + 1){
        if(d[s][e] > d[s][m] + d[m][e]) d[s][e] = d[s][m] + d[m][e];
    }
}
void init(ABC& o){
    rep(i, 1, N + 1) copy(all(d[i]), o[i].begin());
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N >> M;
    rep(i, 1, N + 1) d[i].fill(INF);
    rep(i, 1, N + 1) d[i][i] = 0;
    rep(i, 0, M){
        cin >> u >> v;
        Edges[i] = {u, v};
        adj[u].em(v);
        d[u][v] = 1;
    }
    init(d); compile(d);
    rep(i, 0, M){
        auto [u, v] = Edges[i];
        if(d[1][u] + 1 + d[v][N] > d[1][N]){
            cout << (d[1][N] == INF ? -1 : d[1][N]) << "\n";
        } else {
            adj[Edges[i].x].erase(Edges[i].y);
            auto&& tmp = dijkstra(1);
            cout << (tmp[N] == INF ? -1 : tmp[N]) << "\n";
            adj[Edges[i].x].em(Edges[i].y);
        }
        
    }
}
