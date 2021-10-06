#include <bits/stdc++.h>
#include <atcoder/modint>
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
using mi = atcoder::modint998244353;

const int MAX = 2e5, INF = 1e9;
int N, d, P[MAX], cnt, num;
vector<int> adj[MAX];
vector<int> bfs(int u){
    vector<int> dist(N, INF);
    queue<int> Q; dist[u] = 0; Q.push(u);
    while(!Q.empty()){
        int u = Q.front(); Q.pop();
        for(auto v: adj[u]){
            if(dist[v] == INF){
                dist[v] = dist[u] + 1;
                Q.push(v);
            }
        }
    }
    return dist;
}
int farthest(int u){
    auto&& dist = bfs(u);
    int ret = 0;
    rep(i, 0, N) if(dist[ret] < dist[i]) ret = i;
    return ret;
}
void dfs(int u, int par){
    if(P[u] == d / 2) cnt++;
    for(auto v: adj[u]){
        if(v == par) continue;
        P[v] = P[u] + 1;
        dfs(v, u);
    }
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N;
    rep(i, 1, N){
        int u, v;
        cin >> u >> v; u--; v--;
        adj[u].eb(v);
        adj[v].eb(u);
    }
    int a = farthest(0);
    int b = farthest(a);
    auto&& dista = bfs(a);
    auto&& distb = bfs(b);
    d = dista[b];
    if(d & 1){
        int t1 = 0, t2 = 0;
        rep(i, 0, N){
            if(dista[i] == d / 2 && distb[i] == d / 2 + 1) t1 = i;
            if(distb[i] == d / 2 && dista[i] == d / 2 + 1) t2 = i;
        }
        mi ans = 1;
        cnt = 0;
        dfs(t1, t2);
        ans *= cnt;
        cnt = 0;
        dfs(t2, t1);
        ans *= cnt;
        cout << ans.val() << endl;
    } else {
        int t = 0;
        mi ans = 1, tmp = 0;
        rep(i, 0, N){
            if(dista[i] == d / 2 && distb[i] == d / 2) t = i;
        }
        for(auto v: adj[t]){
            cnt = 0;
            P[v] = 1;
            dfs(v, t);
            ans *= 1 + cnt;
            tmp += cnt;
        }
        ans -= tmp + 1;
        cout << ans.val() << endl;
    }
}
