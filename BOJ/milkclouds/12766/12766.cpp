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

const ll MAX = 5050, INF = 6e18;
ll N, B, S, R, u, v, d, D[MAX][MAX], K[MAX][MAX];
vector<ll> A, pSum{0};
vector<ll> dijkstra(ll S, bool rev) {
    priority_queue<pi> pq;
    vector<ll> dist(N + 1, INF);
    dist[S] = 0;
    pq.push({ 0, S });
    while (!pq.empty()) {
        ll d, u;
        tie(d, u) = pq.top(); pq.pop();
        if(-d != dist[u]) continue;
        rep(v, 1, N + 1) {
            ll nd = (rev ? D[v][u] : D[u][v]) + dist[u];
            if (dist[v] > nd) {
                dist[v] = nd;
                pq.push({ -nd, v });
            }
        }
    }
    return dist;
}
void do_dp(ll t, ll s, ll e, ll p, ll q)
{
    if (s > e) return;
    ll m = (s+e) >> 1;
    D[t][m] = INF;
    for (ll k=p;k<=q&&k<=m;k++){
        ll v = D[t-1][k] + (m - k - 1) * (pSum[m] - pSum[k]);
        if (D[t][m] > v)
            D[t][m] = v, K[t][m] = k;
    }
    do_dp(t, s, m-1, p, K[t][m]);
    do_dp(t, m+1, e, K[t][m], q);
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N >> B >> S >> R;
    fill(D[0], D[N + 1], INF);
    rep(i, 0, R){
        cin >> u >> v >> d;
        D[u][v] = d;
    }
    auto&& D1 = dijkstra(B + 1, 0), D2 = dijkstra(B + 1, 1);
    rep(i, 1, B + 1){
        A.eb(D1[i] + D2[i]);
    }
    sort(all(A));
    rep(i, 0, B) pSum.eb(pSum[i] + A[i]);
    fill(D[0], D[1], INF); D[0][0] = 0;
    rep(i, 1, S + 1) do_dp(i, 0, B, 0, B);
    cout << D[S][B] << endl;
}
