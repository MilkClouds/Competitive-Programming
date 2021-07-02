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

const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, -1, 1}, MAX = 5e4, INF = 1e9;
int H, W, ans = INF;
string S[101];
vector<pi> adj[MAX];
inline bool valid(int x, int y){
    return 0 <=x && x < H && 0 <= y && y < W;
}
inline int conv(int x, int y, int k){
    return x * W + y + H * W * k;
}
vector<int> dist, P;
int solve(int S, int E){
    dist.assign(MAX, INF);
    dist[S] = 0;
    deque<int> Q; Q.push_back(S);
    while(!Q.empty()){
        auto u = Q.front(); Q.pop_front();
        for(auto tmp: adj[u]){
            auto v = tmp.x; auto d = tmp.y;
            if(dist[v] > dist[u] + d){
                dist[v] = dist[u] + d;
                if(d == 1) Q.push_back(v);
                else Q.push_front(v);
            }
        }
    }
    return dist[E];
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> W >> H;
    rep(i, 0, H) cin >> S[i];
    rep(i, 0, H) rep(j, 0, W){
        if(S[i][j] == 'C') P.eb(conv(i, j, 0));
        if(S[i][j] == '*') continue;
        rep(k, 0, 4) {
            int ni = i + dx[k], nj = j + dy[k];
            if(!valid(ni, nj) || S[ni][nj] == '*') continue;
            rep(k2, 0, 4) {
                adj[conv(i, j, k2)].eb(conv(ni, nj, k), k != k2);
            }
        }
    }
    rep(i, 0, 4) rep(j, 0, 4) ans = min(ans, solve(P[0] + H * W * i, P[1] + H * W * j));
    cout << ans << endl;
}
