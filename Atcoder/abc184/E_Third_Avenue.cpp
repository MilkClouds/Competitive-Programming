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

const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, -1, 1};
const int MAX = 2001, INF = 1e9;
int H, W, ST, EN;
vector<int> TEL[26];
string S[MAX];
inline bool valid(int a, int b){
    return 0 <= a && a < H && 0 <= b && b < W;
}
vector<pair<int, int>> adj[MAX * MAX];
vector<int> dist;
inline int conv(int r, int c) {return r * W + c;}
int solve(){
    dist.assign(MAX * MAX, INF);
    dist[ST] = 0;
    deque<int> Q; Q.push_back(ST);
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
    return dist[EN] == INF ? -1 : dist[EN];
}
int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> H >> W;
    rep(i, 0, H) cin >> S[i];
    rep(i, 0, H) rep(j, 0, W){
        if(S[i][j] == 'S') ST = conv(i, j);
        if(S[i][j] == 'G') EN = conv(i, j);
        rep(k, 0, 4){
            int ni = i + dx[k], nj = j + dy[k];
            if(!valid(ni, nj) || S[ni][nj] == '#') continue;
            adj[conv(i, j)].pb({conv(ni, nj), 1});
        }
        if(islower(S[i][j])){
            TEL[S[i][j] - 'a'].pb(conv(i, j));
        }
    }
    rep(i, 0, 26){
        for(auto u: TEL[i]){
            adj[u].pb({conv(MAX - 1, i), 1});
            adj[conv(MAX - 1, i)].pb({u, 0});
        }
    }
    cout << solve();
}
