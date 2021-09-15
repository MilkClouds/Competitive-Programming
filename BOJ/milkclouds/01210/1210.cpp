# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#include <atcoder/all>
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

const int INF = 1e9;
int N, M, S, T, c, u, v;
inline int in(int i){return i * 2;}
inline int out(int i){return i * 2 + 1;}
vector<int> ans;
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N >> M >> S >> T; S--; T--;
    atcoder::mf_graph<int> graph(N * 2);
    rep(i, 0, N) {
        cin >> c;
        graph.add_edge(in(i), out(i), c);
    }
    rep(i, 0, M){
        cin >> u >> v; u--; v--;
        graph.add_edge(out(u), in(v), INF);
        graph.add_edge(out(v), in(u), INF);
    }
    graph.flow(in(S), out(T));
    auto&& v = graph.min_cut(in(S));
    auto&& edges = graph.edges();
    for(auto& edge: edges){
        if(edge.cap == edge.flow && v[edge.from] != v[edge.to]) ans.eb(edge.from >> 1);
    }
    sort(all(ans));
    for(auto i: ans) cout << i + 1 << " ";
}
