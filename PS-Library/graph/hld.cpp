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