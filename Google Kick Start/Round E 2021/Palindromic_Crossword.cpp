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

const int MAX = 1111;
int N, M, vis[MAX][MAX], cnt;
char S[MAX][MAX];
vector<int> R[MAX], C[MAX];
struct DSU {
    // if u is root : par[u] = -(size of tree)
    // else: par[u] = parent of u
public:
    DSU() : N(0) {}
    explicit DSU(int N) : N(N), par(N, -1), alpha(N, '.') {}
    int merge(int u, int v) {
        assert(0 <= u && u < N);
        assert(0 <= v && v < N);
        u = find(u); v = find(v);
        if (u == v) return u;
        if (-par[u] < -par[v]) swap(u, v);
        alpha[u] = max(alpha[u], alpha[v]);
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
    int N;
    vector<int> par;
    vector<char> alpha;
} dsu;

inline int conv(int i, int j){
    return (i - 1) * M + (j - 1);
}

void dfs(int i, int j){
    if(S[i][j] == '#' || S[i][j] != '.') return;
    if(vis[i][j] == 1) return;
    vis[i][j] = 1;
    auto rj = lower_bound(all(R[i]), j);
    auto lj = rj - 1;
    auto ri = lower_bound(all(C[j]), i);
    auto li = ri - 1;
    char& ans = S[i][j];
    for(auto [nx, ny]: {pi(i, *lj + *rj - j), pi(*li + *ri - i, j)}){
        if(vis[nx][ny] == 0){
            dsu.merge(conv(i, j), conv(nx, ny));
            dfs(nx, ny);
        }
    }
}
void solve(){
    cin >> N >> M;

    cnt = 0;
    fill(vis[0], vis[N + 2], 0);
    rep(i, 0, N + 1) R[i].clear();
    rep(j, 0, M + 1) C[j].clear();
    dsu = DSU(N * M);

    rep(i, 1, N + 1) cin >> (S[i] + 1), S[i][0] = S[i][M + 1] = '#';
    rep(i, 1, N + 1) rep(j, 1, M + 1) dsu.alpha[conv(i, j)] = S[i][j];
    rep(j, 0, M + 2) S[0][j] = S[N + 1][j] = '#';
    rep(i, 0, N + 2) rep(j, 0, M + 2){
        if(S[i][j] == '#') R[i].eb(j);
    }
    rep(j, 0, M + 2) rep(i, 0, N + 2){
        if(S[i][j] == '#') C[j].eb(i);
    }
    rep(i, 1, N + 1) rep(j, 1, M + 1) dfs(i, j);

    rep(i, 1, N + 1) rep(j, 1, M + 1) cnt += dsu.alpha[dsu.find(conv(i, j))] != S[i][j];

    cout << cnt << "\n";
    rep(i, 1, N + 1) {
        rep(j, 1, M + 1) cout << dsu.alpha[dsu.find(conv(i, j))];
        cout << "\n";
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    int TC;
    cin >> TC;
    rep(tc, 0, TC){
        cout << "Case #" << tc + 1 << ": "; solve();
    }
}

