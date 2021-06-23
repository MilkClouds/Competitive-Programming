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

const int MAX = 1e3 + 1;
char c;
int N, M, K, f, t, R, B, par[MAX], depth[MAX], color[MAX][MAX];
vector<ti> edges;
set<int> adj[MAX];
vector<bool> chk;
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
};
void dfs(int u, int p, bool print = false){
    for(auto v: adj[u]){
        if(v == p) continue;
        if(print) cout << u + 1 << " " << v + 1 << "\n";
        par[v] = u;
        depth[v] = depth[u] + 1;
        dfs(v, u, print);
    }
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    while(cin >> N >> M >> K) {
        int blue = 0;
        edges.clear();
        chk.assign(M, 0);
        rep(i, 0, M){
            cin >> c >> f >> t; f--; t--;
            edges.eb(c, f, t);
            color[f][t] = color[t][f] = c;
            blue += c == 'B';
        }
        sort(all(edges));
        DSU dsu(N); R = B = 0;
        rep(i, 0, blue){ // B
            tie(c, f, t) = edges[i];
            if(dsu.find(f) == dsu.find(t)) continue;
            dsu.merge(f, t);
            B++;
        }
        rep(i, blue, M){ // R
            tie(c, f, t) = edges[i];
            if(dsu.find(f) == dsu.find(t)) continue;
            dsu.merge(f, t);
            R++;
        }
        if(R + B != N - 1 || B < K){
            cout << "0\n";
            continue;
        }
        dsu = DSU(N); R = B = 0;
        rep(i, blue, M){ // R
            tie(c, f, t) = edges[i];
            if(dsu.find(f) == dsu.find(t)) continue;
            dsu.merge(f, t);
            chk[i] = 1;
            adj[f].insert(t);
            adj[t].insert(f);
            R++;
        }
        rep(i, 0, blue){ // B
            tie(c, f, t) = edges[i];
            if(dsu.find(f) == dsu.find(t)) continue;
            dsu.merge(f, t);
            chk[i] = 1;
            adj[f].insert(t);
            adj[t].insert(f);
            B++;
        }
        if(R + B != N - 1 || B > K){
            cout << "0\n";
            continue;
        }
        par[0] = -1; depth[0] = 1;
        dfs(0, -1);
        rep(i, 0, blue){
            if(B == K) break;
            if(chk[i]) continue;
            tie(c, f, t) = edges[i];
            int cf = f, ct = t;
            int flag = 0;
            if(depth[f] > depth[t]) swap(f, t);
            while(depth[f] < depth[t]){
                if(color[t][par[t]] == 'R'){
                    adj[t].erase(par[t]);
                    adj[par[t]].erase(t);
                    flag = 1;
                    break;
                }
                t = par[t];
            }
            while(!flag && (f ^ t)){
                rep(_, 0, 2){
                    if(color[t][par[t]] == 'R'){
                        adj[t].erase(par[t]);
                        adj[par[t]].erase(t);
                        flag = 1;
                        break;
                    }
                    t = par[t];
                    swap(f, t);
                }
            }
            if(flag){
                adj[cf].insert(ct);
                adj[ct].insert(cf);
                dfs(0, -1);
                R--; B++;
            }
        }
        if(R + B != N - 1 || B != K){
            cout << "0\n";
            return 0;
        }
        dfs(0, -1, true);
        break;
    }
}

