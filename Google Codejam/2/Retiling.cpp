# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define rep2(i,a,b) for(int i = (b) - 1; i >= (a); i--)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define x first
#define y second
using namespace std;
using ll = long long;
using tl = tuple<ll, ll, ll, ll>;
using pl = pair<ll, ll>;
using pii = pair<int, int>;
using ld = long double;

const int MAX = 10, INF = 1e9;
int TC, R, C, F, S, SS, EE;
ll dp[123][4];
string A[MAX], B[MAX];

struct MCMF {

    struct Edge {
        int nxt;
        int inv; //inverse edge index
        int res; //residual
        int cost; //cost
    };

    vector<vector<Edge>> adj;
    vector<int> h, inq; //johnson's algorithm, spfa
    vector<int> dist; //dijkstra
    vector<int> check, work; //max flow
    int sz, s, e; //source, sink

    MCMF(int sz) :
        adj(sz), h(sz), inq(sz),
        dist(sz), check(sz), work(sz),
        sz(sz), s(-1), e(-1) {
    }

    void set_source(int t) { s = t; }
    void set_sink(int t) { e = t; }
    void add_edge(int a, int b, int fl, int cost) {
        Edge forward{ b, (int)adj[b].size(), fl, cost };
        Edge reverse{ a, (int)adj[a].size(), 0, -cost };
        adj[a].push_back(forward);
        adj[b].push_back(reverse);
    }
    void init() {
        fill(h.begin(), h.end(), INF);
        fill(dist.begin(), dist.end(), INF);

        //johnson's algorithm with spfa
        queue<int> Q;
        inq[s] = 1;
        Q.push(s);
        while (!Q.empty()) {
            int cur = Q.front(); Q.pop();
            inq[cur] = 0;
            for (auto i : adj[cur]) {
                if (i.res && h[i.nxt] > h[cur] + i.cost) {
                    h[i.nxt] = h[cur] + i.cost;
                    if (!inq[i.nxt]) {
                        inq[i.nxt] = 1;
                        Q.push(i.nxt);
                    }
                }
            }
        }
        for (int i = 0; i < sz; i++) {
            for (auto& j : adj[i]) {
                if (j.res) j.cost += h[i] - h[j.nxt];
            }
        }

        //get shortest path DAG with dijkstra
        priority_queue<pii, vector<pii>, greater<pii>> PQ;
        dist[s] = 0;
        PQ.push({ dist[s], s });
        while (PQ.size()) {
            auto [cdist, cur] = PQ.top(); PQ.pop();
            if (dist[cur] ^ cdist) continue;
            for (auto i : adj[cur]) {
                if (i.res && dist[i.nxt] > cdist + i.cost) {
                    dist[i.nxt] = cdist + i.cost;
                    PQ.push({ dist[i.nxt], i.nxt });
                }
            }
        }
        for (int i = 0; i < sz; i++) dist[i] += h[e] - h[s];
    }
    bool update() { //update shortest path DAG in O(V+E)
        int mn = INF;
        for (int i = 0; i < sz; i++) {
            if (!check[i]) continue;
            for (const auto& j : adj[i]) {
                if (j.res && !check[j.nxt]) {
                    mn = min(mn, dist[i] + j.cost - dist[j.nxt]);
                }
            }
        }
        if (mn >= INF) return 0;
        for (int i = 0; i < sz; i++) {
            if (!check[i]) dist[i] += mn;
        }
        return 1;
    }
    int dfs(int cur, int fl) {
        check[cur] = 1;
        if (cur == e) return fl;
        for (; work[cur] < adj[cur].size(); work[cur]++) {
            auto& i = adj[cur][work[cur]];
            if (!check[i.nxt] && dist[i.nxt] == dist[cur] + i.cost && i.res) {
                int ret = dfs(i.nxt, min(fl, i.res));
                if (ret) {
                    i.res -= ret;
                    adj[i.nxt][i.inv].res += ret;
                    return ret;
                }
            }
        }
        return 0;
    }
    pii mcmf() { //cost, flow
        if (s == -1 || e == -1) return { -1, -1 };
        init();
        int cost = 0, fl = 0;
        do {
            fill(check.begin(), check.end(), 0);
            fill(work.begin(), work.end(), 0);
            int cur = 0;
            while (cur = dfs(s, INF)) {
                cost += dist[e] * cur;
                fl += cur;
                fill(check.begin(), check.end(), 0);
            }
        } while (update());
        return { cost, fl };
    }
};
int dist(int a, int b, int c, int d){
    return abs(a - c) + abs(b - d);
}
int solve(){
    int cnt = 0;
    rep(i, 0, R) rep(j, 0, C) cnt += (A[i][j] ^ B[i][j]) != 0;
    MCMF mcmf(R * C + 2);
    SS = R * C; EE = SS + 1;
    mcmf.set_source(SS);
    mcmf.set_sink(EE);
    set<pii> MtoG, GtoM;
    rep(i, 0, R) rep(j, 0, C){
        if(A[i][j] ^ B[i][j]){
            if(A[i][j] == 'M') MtoG.insert({i, j});
            else GtoM.insert({i, j});
        }
    }
    for(auto [c, d]: GtoM) mcmf.add_edge(c * C + d, EE, 1, 0);
    for(auto [a, b]: MtoG){
        mcmf.add_edge(SS, a * C + b, 1, 0);
        for(auto [c, d]: GtoM){
            mcmf.add_edge(a * C + b, c * C + d, 1, min(2 * F, S * dist(a, b, c, d)));
        }
    }
    auto p = mcmf.mcmf();
    return (cnt - p.y * 2) * F + p.x;
}

int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> TC;
    rep(tc, 1, TC + 1){
        cin >> R >> C >> F >> S;
        rep(i, 0, R) cin >> A[i];
        rep(i, 0, R) cin >> B[i];
        printf("Case #%d: %d\n", tc, solve());
    }
}
