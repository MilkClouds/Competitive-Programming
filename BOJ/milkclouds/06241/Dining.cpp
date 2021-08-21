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

int N, F, D, Fi, Di, t, S, T;

int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N >> F >> D;
    atcoder::mf_graph<int> graph(N * 2 + F + D + 2);
    T = (S = N * 2 + F + D) + 1;
    rep(i, 0, F) graph.add_edge(S, N * 2 + i, 1);
    rep(i, 0, D) graph.add_edge(N * 2 + F + i, T, 1);
    rep(i, 0, N){
        cin >> Fi >> Di;
        rep(j, 0, Fi){
            cin >> t; t--;
            graph.add_edge(N * 2 + t, i, 1);
        }
        graph.add_edge(i, i + N, 1);
        rep(j, 0, Di){
            cin >> t; t--;
            graph.add_edge(i + N, N * 2 + F + t, 1);
        }
    }
    cout << graph.flow(S, T) << '\n';
}
