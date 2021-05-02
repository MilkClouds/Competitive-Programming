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

const ll INF = 1e15;
ll dp[1 << 10][10], ans = INF;
int N, K, T[10][10];

ll dijkstra() {
    priority_queue<pi> pq;
    vector<ll> dist(N * (1 << N), INF);
    int S = (1 << K) * N + K;
    dist[S] = 0;
    pq.push({ 0, S });
    while (!pq.empty()) {
        ll nd, d, u, v, u1, u2, v1, v2;
        tie(d, u) = pq.top(); pq.pop(); d *= -1;
        if(d != dist[u]) continue;
        u1 = u / N;
        u2 = u % N;
        rep(v2, 0, N){
            if(u1 & (1 << v2)) {
                v = u1 * N + v2;
                nd = dist[u] + T[u2][v2];
                if(dist[v] > nd){
                    dist[v] = nd;
                    pq.push({-nd, v});
                }
            }
            else {
                v1 = u1 | (1 << v2);
                v = v1 * N + v2;
                nd = dist[u] + T[u2][v2];
                if(dist[v] > nd){
                    dist[v] = nd;
                    pq.push({-nd, v});
                }
            }
        }
    }
    rep(i, 0, N) ans = min(ans, dist[((1 << N) - 1) * N + i]);
    return ans;
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N >> K;
    rep(i, 0, N) rep(j, 0, N) cin >> T[i][j];
    cout << dijkstra();
}
