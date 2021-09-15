# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define rep2(i,a,b) for(int i = (b) - 1; i >= (a); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define pb push_back
#define x first
#define y second
using namespace std;
using ll = long long;
using tl = tuple<ll, ll, ll, ll>;
using pl = pair<ll, ll>;
using pi = pair<int, int>;
using ld = long double;

int H, W, N, A, B, C, D;
int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> H >> W >> N;
    int SOURCE = H + W + 2 * N, SINK = SOURCE + 1;
    atcoder::mf_graph<int> graph(SINK + 1);
    rep(i, 0, N) {
        cin >> A >> B >> C >> D;
        rep(a, A - 1, C) {
            graph.add_edge(a, H + W + i, 1);
        }
        rep(b, B - 1, D) {
            graph.add_edge(H + W + N + i, H + b, 1);
        }
        graph.add_edge(H + W + i, H + W + N + i, 1);
    }
    rep(i, 0, H) graph.add_edge(SOURCE, i, 1);
    rep(j, 0, W) graph.add_edge(H + j, SINK, 1);
    cout << graph.flow(SOURCE, SINK);
}
