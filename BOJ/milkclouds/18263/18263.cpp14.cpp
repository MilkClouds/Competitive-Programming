/*
ID: milkclouds
LANG: C++
TASK: milkvisits
*/

# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#define rep(a,b,c) for(ll a=b;a<c;a++)
#define rep2(a,b,c) for(ll a=b;a>c;a--)
#define pb push_back
#define x first
#define y second
#define all(x) x.begin(), x.end()
using namespace std;
using ll=long long;
using ti=tuple<ll,ll,ll>;
using pi=pair<ll,ll>;
const ll MAX = 1e5 + 1;

ll N, M, T[MAX], u, v, c, ok[MAX], cnt;
vector<ll> adj[MAX], todo[MAX];
pi dfsn[MAX];
ti query[MAX];

void dfs(ll u, ll par){
    dfsn[u].x = cnt++;
    for(auto v: adj[u]) if(par ^ v) dfs(v, u);
    dfsn[u].y = cnt - 1;
}
vector<ll> ord;
vector<pi> S[MAX];
bool anc(ll a, ll b){
    return dfsn[a].x <= dfsn[b].x && dfsn[b].y <= dfsn[a].y;
}
void dfs2(ll u, ll par){
    S[T[u]].pb({u, ord.size() + 0}); ord.pb(u);
    for(auto i: todo[u]){
        ll a, b, c;
        tie(a, b, c) = query[i];
        if(!S[c].empty()){
            pi y = S[c].back();
            if(y.x == u) ok[i] = 1;
            else {
                ll Y = ord[y.y + 1];
                if(!anc(Y, a + b - u)) ok[i] = 1;
            }
        }
    }
    for(auto v: adj[u]) if(par ^ v) dfs2(v, u);
    S[T[u]].pop_back(); ord.pop_back();
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> N >> M;
    rep(i, 1, N + 1) cin >> T[i];
    rep(_, 1, N){
        cin >> u >> v;
        adj[u].pb(v); adj[v].pb(u);
    }
    dfs(1, 0);
    rep(i, 0, M){
        cin >> u >> v >> c;
        query[i] = make_tuple(u, v, c);
        todo[u].pb(i); todo[v].pb(i);
    }
    dfs2(1, 0);
    rep(i, 0, M) {
        cout << ok[i];
    }
}