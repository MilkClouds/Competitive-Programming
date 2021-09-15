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

const int INF = 2e9;
int N, K, op, i, j, d;
/*
DSU is from https://github.com/atcoder/ac-library/
*/
struct DSU {
    // if u is root : par[u] = -(size of tree)
    // else: par[u] = parent of u
public:
    DSU() : N(0) {}
    explicit DSU(int N) : N(N), par(N, -1), dist(N, 0) {}
    int merge(int u, int v, int d) {
        assert(0 <= u && u < N);
        assert(0 <= v && v < N);
        find(u); find(v);
        d += dist[u] - dist[v];
        u = find(u); v = find(v);
        if (u == v) return u;
        if (-par[u] < -par[v]) swap(u, v), d *= -1;
        par[u] += par[v];
        par[v] = u;
        dist[v] = d;
        return u;
    }
    int find(int u) {
        assert(0 <= u && u < N);
        if (par[u] < 0) return u;
        int p = find(par[u]);
        dist[u] = dist[par[u]] + dist[u];
        return par[u] = p;
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
    int getDistance(int u, int v){
        find(u); find(v);
        return dist[v] - dist[u];
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
    void makeInvalid(int u){
        u = find(u);
        dist[u] = INF;
    }
    bool isInvalid(int u){
        u = find(u);
        return dist[u] == INF;
    }
private:
    int N;
    vector<int> par, dist;
};
void solve(){
    cin >> N >> K;
    DSU dsu(N);
    rep(_, 0, K){
        cin >> op;
        if(op == 1){
            cin >> i >> j >> d; i--; j--;
            if(!dsu.same(i, j)) dsu.merge(i, j, d);
            else if(dsu.getDistance(i, j) ^ d) dsu.makeInvalid(i);
        } else {
            cin >> i >> j; i--; j--;
            if(!dsu.same(i, j)) cout << "NC\n";
            else if(dsu.isInvalid(i) || dsu.isInvalid(j)) cout << "CF\n";
            else cout << dsu.getDistance(i, j) << "\n";
        }
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    int TC;
    cin >> TC;
    rep(tc, 0, TC){
        cout << "Case #" << tc + 1 << '\n';
        solve();
    }
}
