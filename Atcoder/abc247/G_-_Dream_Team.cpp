#include <bits/stdc++.h>
#include <atcoder/mincostflow>
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

const ll INF = 1e14, MAX = 150, MAXN = 30000;
int N, A[MAXN], B[MAXN], C[MAXN], a, b, c, s, t;
vector<ll> ans;
ll S;
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N;
    rep(i, 0, N) cin >> A[i] >> B[i] >> C[i], A[i]--, B[i]--;
    s = MAX * 2;
        t = s + 1;
        atcoder::mcf_graph<ll, ll> graph(MAX * 2 + 2);
        //graph.add_edge(s, t, MAX, INF);
        rep(i, 0, MAX){
            graph.add_edge(s, i, 1, 0);
            graph.add_edge(i + MAX, t, 1, 0);
        }
        rep(i, 0, N){
            graph.add_edge(A[i], B[i] + MAX, 1, INF - C[i]);
        }
    rep(cap, 1, MAX + 1){
        auto [Cap, Cost] = graph.flow(s, t, cap);
        for(auto& e: graph.edges()) e.flow = 0;
        if(Cap < cap) break;
        ans.eb(Cap * INF - Cost);
    }
    cout << ans.size() << "\n";
    for(auto i: ans) cout << i << "\n";
}
