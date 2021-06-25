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

const int MAXV = 1e5 + 10;
int N, M, A[MAXV], B[MAXV], MM, u, v, k, par[MAXV][20], depth[MAXV] = {1};
vector<int> adj[MAXV], S;
ll l, r, m;
void dfs(int u){
    for(auto v: adj[u]){
        if(par[u][0] == v) continue;
        par[v][0] = u;
        depth[v] = depth[u] + 1;
        dfs(v);
    }
}
int lca(int u, int v){
    if(depth[u] > depth[v]) swap(u, v);
    rep(i, 0, 20){
        if((1 << i) & (depth[v] - depth[u])) v = par[v][i];
    }
    rep2(i, 0, 20){
        if(par[u][i] != par[v][i]){
            u = par[u][i];
            v = par[v][i];
        }
    }
    return par[u][0];
}


struct PSTNode{
    PSTNode *l, *r; int v;
    PSTNode(){ l = r = nullptr; v = 0; }
};
struct PST{
    PSTNode *root[101010];
    PST(){ memset(root, 0, sizeof root); }
    void init(PSTNode *node, int s, int e){
        if(s == e) return;
        int m = s + e >> 1;
        node->l = new PSTNode; node->r = new PSTNode;
        init(node->l, s, m); init(node->r, m+1, e);
    }
    void update(PSTNode *prv, PSTNode *now, int s, int e, int x){
        if(s == e){ now->v = prv ? prv->v + 1 : 1; return; }
        int m = s + e >> 1;
        if(x <= m){
            now->l = new PSTNode; now->r = prv->r;
            update(prv->l, now->l, s, m, x);
        }
        else{
            now->r = new PSTNode; now->l = prv->l;
            update(prv->r, now->r, m+1, e, x);
        }
        int t1 = now->l ? now->l->v : 0;
        int t2 = now->r ? now->r->v : 0;
        now->v = t1 + t2;
    }
    int kth(PSTNode *prv, PSTNode *now, int s, int e, int k){
        if(s == e) return s;
        int m = s + e >> 1;
        int diff = now->l->v - prv->l->v;
        if(k <= diff) return kth(prv->l, now->l, s, m, k);
        else return kth(prv->r, now->r, m+1, e, k-diff);
    }
} pst;


int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N >> M;
    rep(i, 0, N) {
        cin >> B[i];
        S.eb(B[i]);
    }
    sort(all(S)); S.erase(unique(all(S)), S.end());
    rep(i, 0, N) A[i] = lower_bound(all(S), B[i]) - S.begin();
    rep(i, 1, N){
        cin >> u >> v; u--; v--;
        adj[u].eb(v);
        adj[v].eb(u);
    }
    dfs(0);
    rep(i, 0, N) rep(j, 1, 20) par[i][j] = par[par[i][j - 1]][j - 1];
    pst.root[0] = new PSTNode;
    pst.init(pst.root[0], 0, S.size() - 1);
    rep(i, 1, N + 1){
        pst.root[i] = new PSTNode;
        pst.update(pst.root[i], pst.root[i - 1], 0, S.size() - 1, A[i - 1]);
    }
    rep(i, 0, M){
        cin >> u >> v >> k; u--; v--;
        cout << pst.kth(pst.root[u], pst.root[v + 1], 0, S.size() - 1, k) << '\n';
    }
}
