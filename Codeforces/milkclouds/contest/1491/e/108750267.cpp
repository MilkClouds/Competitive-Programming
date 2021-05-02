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


const int MAX = 2e5;
int N, u, v, F[27], cnt[MAX], par[MAX], isF[MAX];
bool vis[MAX];
vector<int> adj[MAX];
using vpi = vector<pi>;

int dfs0(int u, int p){
    cnt[u] = 1;
    par[u] = p;
    for(auto v: adj[u]){
        if(v ^ p) cnt[u] += dfs0(v, u);
    }
    return cnt[u];
}
void dfs(int u, int p, vector<int>& vv){
    vv.pb(u);
    for(auto v: adj[u]){
        if(v ^ p) dfs(v, u, vv);
    }
}

bool solution(vector<int> v){
    if(v.size() == 1) return 1;
    dfs0(v[0], -1);
    for(auto i: v){
        if(isF[cnt[i]] && isF[v.size() - cnt[i]]){
            int a = i, b = par[i];
            adj[a].erase(find(all(adj[a]), b));
            adj[b].erase(find(all(adj[b]), a));
            vector<int> va, vb;
            dfs(a, -1, va); dfs(b, -1, vb);
            return solution(va) && solution(vb);
        }
    }
    return 0;
}

int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N;
    F[0] = F[1] = 1;
    rep(i, 0, 25) F[i + 2] = F[i + 1] + F[i];
    rep(i, 0, 27) isF[F[i]] = i;
    rep(i, 1, N){
        cin >> u >> v; u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<int> v(N);
    rep(i, 0, N) v[i] = i;
    cout << (isF[N] && solution(v) ? "YES" : "NO");
}
