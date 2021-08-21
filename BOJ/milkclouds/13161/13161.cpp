# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#include <atcoder/maxflow>
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

int N, t;
vector<int> A, B;

int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N;
    rep(i, 0, N){
        cin >> t;
        if(t == 1) A.eb(i);
        else if(t == 2) B.eb(i);
    }
    atcoder::mf_graph<int> graph(N + 2);
    for(auto i: A) graph.add_edge(N, i, INF);
    for(auto i: B) graph.add_edge(i, N + 1, INF);
    rep(i, 0, N) rep(j, 0, N){
        cin >> t;
        if(i ^ j) graph.add_edge(i, j, t);
    }
    cout << graph.flow(N, N + 1) << endl;
    auto&& reachable = graph.min_cut(N);
    rep(i, 0, N) if(reachable[i]) cout << i + 1 << " "; cout << '\n';
    rep(i, 0, N) if(!reachable[i]) cout << i + 1 << " "; cout << '\n';
}
