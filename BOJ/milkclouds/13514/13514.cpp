#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define rep2(i,a,b) for(int i = (b) - 1; i >= (a); i--)
#define cinA(A, N) rep(i, 0, N) cin >> A[i];
#define coutA(A, N) rep(i, 0, N) cout << A[i] << " ";
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define eb emplace_back
#define popcount __builtin_popcount
#define popcountll __builtin_popcountll
#define x first
#define y second
using namespace std;
using ll = long long;
using ull = uint64_t;
using ld = long double;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using pl = pair<ll, ll>;
using tl = tuple<ll, ll, ll>;

const int MAXN = 100010, INF = 1e9, MLOG = 18;

vector<pi> adj[MAXN];
int sz[MAXN], N, M, C[MAXN], cdpar[MAXN];
multiset<int> pq[MAXN];
bool vis[MAXN];

int getSize(int u, int p) {				// 서브트리들의 크기를 구한다
	sz[u] = 1;
	for(auto e : adj[u]) if(!vis[e.y] && e.y != p) {;
		sz[u] += getSize(e.y, u);
	}
	return sz[u];
}

void solve(int u, int p = 0) {
	int s = getSize(u, -1);
	while(1) {
		bool b = false;
		for(auto e : adj[u]) if(!vis[e.y] && sz[e.y] < sz[u] && 2 * sz[e.y] > s) {
			u = e.y;
			b = true;
			break;
		}
		if(!b) break;
	}
	vis[u] = true;
    cdpar[u] = p;
	for(auto e : adj[u]) if(!vis[e.y]) solve(e.y, u);	// 나누어진 서브트리에서 문제 해결
}

int par[MAXN][MLOG], depth[MAXN];
void dfs(int u, int p = 0) {
    par[u][0] = p;
    depth[u] = depth[p] + 1;
	for(auto e : adj[u]) if(e.y != p) {
		dfs(e.y, u);
	}
}
int lca(int u, int v){
    if(depth[u] > depth[v]) swap(u, v);
    rep(i, 0, MLOG){
        if((1 << i) & (depth[v] - depth[u])) v = par[v][i];
    }
    if(u == v) return u;
    rep2(i, 0, MLOG)
        if(par[u][i] != par[v][i]) u = par[u][i], v = par[v][i];
    return par[u][0];
}
int dist(int u, int v){
    return depth[u] + depth[v] - 2 * depth[lca(u, v)];
}

int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N;
    rep(i, 1, N){
        int u, v;
        cin >> u >> v;
        adj[u].eb(1, v);
        adj[v].eb(1, u);
    }
    dfs(1);
    rep(j, 1, MLOG) rep(i, 1, N + 1)  par[i][j] = par[par[i][j - 1]][j - 1];
    solve(1);
    cin >> M;
    while(M--){
        int c, u;
        cin >> c >> u;
        if(c == 1){
            C[u] ^= 1;
            int v = u;
            do {
                if(C[u]) pq[v].emplace(dist(u, v));
                else pq[v].erase(pq[v].find(dist(u, v)));
            } while(v = cdpar[v]);
        } else {
            int ans = INF;
            int v = u;
            do{
                if(!pq[v].empty()) ans = min(ans, dist(u, v) + *pq[v].begin());
            } while(v = cdpar[v]);
            cout << (ans == INF ? -1 : ans) << '\n';
        }
    }
}
