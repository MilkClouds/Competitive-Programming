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

// from 7:15~

const int MAX = 2e5 + 1, INF = 1e9;
int N, M, u, v, d[MAX], ind[MAX], cnt[MAX];
vector<int> adj[MAX];
queue<int> Q;
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N;
    rep(u, 1, N + 1){
        while((cin >> v) && v){
            adj[u].pb(v);
            ind[u]++;
        }
    }
    cin >> M;
    fill(d, d + N + 1, INF);
    rep(i, 0, M){
        cin >> u;
        Q.push(u); d[u] = 0;
    }
    while(!Q.empty()){
        int u = Q.front(); Q.pop();
        for(auto v: adj[u]){
            if(d[v] < INF) continue;
            cnt[v]++;
            if(ind[v] <= cnt[v] * 2){
                d[v] = d[u] + 1;
                Q.push(v);
            }
        }
    }
    rep(i, 1, N + 1){
        cout << (d[i] == INF ? -1 : d[i]) << " ";
    }
}
