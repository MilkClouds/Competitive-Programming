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

const int MAXV = 1e5 + 1;
int N, Q, e[MAXV];

struct FenwickTree {
public:
    FenwickTree() : FenwickTree(0) {}
    explicit FenwickTree(int N) : N(N), tree(N + 1, 0) {}
    ll query(int i) {
        ll ret = 0; i++;
        for(; i; i ^= i & -i) ret ^= tree[i];
        return ret;
    }
    ll query(int i, int j){
        return query(j) ^ query(i - 1);
    }
    void update(int i, ll x) {
        i++;
        for(; i <= N; i += i & -i) tree[i] ^= x;
    }
private:
    int N;
    vector<ll> tree;
} seg(MAXV);

int chk[MAXV], sz[MAXV], dep[MAXV], par[MAXV], top[MAXV], in[MAXV], out[MAXV], pv;
vector<int> g[MAXV], adj[MAXV];
/*
sz[i] = i를 루트로 하는 서브트리의 크기
dep[i] = i의 깊이
par[i] = i의 부모 정점
top[i] = i가 속한 체인의 가장 위에 있는 정점
in[i], out[i] = dfs ordering
g[i] = i의 자식 정점
*/

void dfs(int v = 1){
	chk[v] = 1;
	for(auto i : adj[v]){
		if(chk[i]) continue;
		chk[i] = 1;
		g[v].push_back(i);
		dfs(i);
	}
}

void dfs1(int v = 1){
	sz[v] = 1;
	for(auto &i : g[v]){
		dep[i] = dep[v] + 1; par[i] = v;
		dfs1(i); sz[v] += sz[i];
		if(sz[i] > sz[g[v][0]]) swap(i, g[v][0]);
	}
}

void dfs2(int v = 1){
	in[v] = ++pv;
	for(auto i : g[v]){
		top[i] = i == g[v][0] ? top[v] : i;
		dfs2(i);
	}
	out[v] = pv;
}

int query(int a, int b){
    int ret = 0;
    while(top[a] != top[b]){
        if(dep[top[a]] < dep[top[b]]) swap(a, b);
        int st = top[a];
        ret ^= seg.query(in[st], in[a]);
        a = par[st];
    }
    if(dep[a] > dep[b]) swap(a, b);
    ret ^= seg.query(in[a], in[b]);
    return ret;
}

int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N >> Q;
    rep(i, 1, N + 1) cin >> e[i];
    rep(i, 1, N){
        int u, v;
        cin >> u >> v;
        adj[u].eb(v);
        adj[v].eb(u);
    }
    dfs(); dfs1(); dfs2();
    rep(i, 1, N + 1) seg.update(in[i], e[i]);
    while(Q--){
        int c, i, j, v;
        cin >> c;
        if(c & 1){
            cin >> i >> v;
            seg.update(in[i], v ^ e[i]);
            e[i] = v;
        } else {
            cin >> i >> j;
            cout << query(i, j) << "\n";
        }
    }
}
