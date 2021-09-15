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

const int MAXN = 505, MAX = 1e5;
const vector<pi> action {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int N, M, Q, H[MAXN][MAXN];
struct Query{
    int a, b, c, d;
    int l, r;
} query[MAX];
vector<pi> vertex[MAXN * MAXN];
vector<int> height;
inline int conv(int x, int y){
    return x * M + y;
}
istream& operator >> (istream& is, Query& q){
    is >> q.a >> q.b >> q.c >> q.d; q.a--; q.b--; q.c--; q.d--;
    if(pi(q.a, q.b) == pi(q.c, q.d)) {
        q.r = lower_bound(all(height), H[q.a][q.b]) - height.begin();
        q.l = q.r - 1;
    } else {
        q.l = -1;
        q.r = height.size();
    }
    q.a = conv(q.a, q.b);
    q.b = conv(q.c, q.d);
    return is;
}
inline bool valid(int x, int y){
    return 0 <= x && x < N && 0 <= y && y < M;
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
};

int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N >> M >> Q;
    rep(i, 0, N) rep(j, 0, M) cin >> H[i][j], height.eb(H[i][j]);
    sort(all(height));
    height.erase(unique(all(height)), height.end());
    rep(i, 0, N) rep(j, 0, M) vertex[lower_bound(all(height), H[i][j]) - height.begin()].eb(i, j);
    rep(i, 0, Q) cin >> query[i];
    while(1){
        bool flag = 0;
        vector<vector<int>> events(height.size());
        rep(i, 0, Q){
            if(query[i].l + 1 >= query[i].r) continue;
            flag = 1;
            events[query[i].l + query[i].r >> 1].eb(i);
        }
        if(!flag) break;
        DSU dsu(N * M);
        rep(i, 0, height.size()){
            for(auto [x, y] : vertex[i]){
                for(auto [dx, dy]: action){
                    int nx = x + dx, ny = y + dy;
                    if(!valid(nx, ny)) continue;
                    if(H[nx][ny] <= height[i]) dsu.merge(conv(x, y), conv(nx, ny));
                }
            }
            for(auto q: events[i]){
                if(dsu.same(query[q].a, query[q].b)) query[q].r = i;
                else query[q].l = i;
            }
        }
    }
    rep(i, 0, Q) cout << height[query[i].r] << "\n";
}
