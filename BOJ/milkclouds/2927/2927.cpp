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

const int MAXV = 3e4 + 1, MAXQ = 3e5;
int N, Q, A[MAXV];
struct ABC{
    string S;
    int i, j;
} Query[MAXQ];
istream& operator >> (istream& is, ABC& o){
    return is >> o.S >> o.i >> o.j;
}

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

struct FenwickTree {
public:
    FenwickTree() : FenwickTree(0) {}
    explicit FenwickTree(int N) : N(N), tree(N + 1, 0) {}
    ll query(int i) {
        ll ret = 0;
        for(; i; i ^= i & -i) ret += tree[i];
        return ret;
    }
    ll query(int i, int j){
        return query(j) - query(i - 1);
    }
    void update(int i, ll x) {
        for(; i <= N; i += i & -i) tree[i] += x;
    }
private:
    int N;
    vector<ll> tree;
} seg(MAXV);

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
        ret += seg.query(in[st], in[a]);
        a = par[st];
    }
    if(dep[a] > dep[b]) swap(a, b);
    ret += seg.query(in[a], in[b]);
    return ret;
}

struct DSU {
    // if u is root : par[u] = -(size of tree)
    // else: par[u] = parent of u
public:
    DSU() : N(0) {}
    explicit DSU(int N) : N(N), par(N, -1) {}
    int merge(int u, int v) {
        assert(0 <= u && u < N);
        assert(0 <= v && v < N);
        u = find(u); v = find(v);
        if (u == v) return u;
        if (-par[u] < -par[v]) swap(u, v);
        par[u] += par[v];
        par[v] = u;
        return u;
    }
    int find(int u) {
        assert(0 <= u && u < N);
        if (par[u] < 0) return u;
        return par[u] = find(par[u]);
    }
    bool same(int u, int v) {
        assert(0 <= u && u < N);
        assert(0 <= v && v < N);
        return find(u) == find(v);
    }
    int size(int u) {
        assert(0 <= u && u < N);
        return -par[find(u)];
    }
    vector<vector<int> > groups() {
        vector<int> roots(N), groups(N);
        for (int i = 0; i < N; i++) {
            roots[i] = find(i);
            groups[roots[i]]++;
        }
        vector<vector<int> > result(N);
        for (int i = 0; i < N; i++) {
            result[i].reserve(groups[i]);
        }
        for (int i = 0; i < N; i++) {
            result[roots[i]].push_back(i);
        }
        result.erase(
            remove_if(result.begin(), result.end(), [&](const vector<int>& v) { return v.empty(); }), result.end()
        );
        return result;
    }
private:
    int N;
    vector<int> par;
} dsu;


int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N;
    cinA(A, N);
    cin >> Q;
    rep(i, 0, Q) cin >> Query[i];
    dsu = DSU(N + 1);
    rep(k, 0, Q){
        auto [S, i, j] = Query[k];
        if(S == "bridge"){
            if(dsu.same(i, j)) continue;
            adj[i].eb(j);
            adj[j].eb(i);
            dsu.merge(i, j);
        }
    }
    dsu = DSU(N + 1);
    rep(i, 1, N + 1){
        if(chk[i]) continue;
        dfs(i); dfs1(i); dfs2(i);
    }
    rep(i, 0, N){
        seg.update(in[i + 1], A[i]);
    }
    rep(k, 0, Q){
        auto [S, i, j] = Query[k];
        if(S == "bridge"){
            if(dsu.same(i, j)){
                cout << "no\n";
            } else {
                cout << "yes\n";
                dsu.merge(i, j);
            }
        } else if(S == "excursion"){
            if(dsu.same(i, j)){
                cout << query(i, j) << "\n";
            } else {
                cout << "impossible\n";
            }
        } else {
            seg.update(in[i], j - A[i - 1]);
            A[i - 1] = j;
        }
    }
}
