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

const vector<pi> actions = {pi(1, 0), pi(-1, 0), pi(0, 1), pi(0, -1)};
const vector<pi> act = {pi(-1, 0), pi(0, -1), pi(1, -1), pi(-1, 1), pi(2, 0), pi(0, 2), pi(2, 1), pi(1, 2)};
const vector<pi> actin = {pi(0, 0), pi(0, 1), pi(1, 0), pi(1, 1)};
const int MAX = 501;
const int INF = 1e9;

int H, W;
string S[MAX];
inline bool valid(int x, int y){
    return 0 <= x && x < H && 0 <= y && y < W;
}

vector<int> dist;
vector<pi> adj[MAX * MAX * 3];
int solve(int S){
    dist.assign(H * W * 3, INF);
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
    return dist[H * W - 1];
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> H >> W;
    rep(i, 0, H) cin >> S[i];
    rep(i, 0, H) rep(j, 0, W){
        if(S[i][j] == '.') adj[i * W + j + H * W].eb(i * W + j, 0);
        for(auto [dx, dy] : actions){
            int nx = i + dx, ny = j + dy;
            if(!valid(nx, ny)) continue;
            if(S[nx][ny] == '.') adj[i * W + j].eb(nx * W + ny, 0);
        }
    }
    rep(i, 0, H) rep(j, 0, W){
        for(auto [dx1, dy1]: act){
            int nx1 = i + dx1, ny1 = j + dy1;
            if(!valid(nx1, ny1)) continue;
            adj[nx1 * W + ny1].eb(i * W + j + H * W * 2, 1);
        }
        for(auto [dx, dy]: actin){
            int nx = i + dx, ny = j + dy;
            if(!valid(nx, ny)) continue;
            adj[i * W + j + H * W * 2].eb(nx * W + ny, 0);
        }
    }
    cout << solve(0);
}
