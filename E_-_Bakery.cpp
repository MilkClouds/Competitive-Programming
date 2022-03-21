#include <bits/stdc++.h>
#include <atcoder/all>
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

const int MAX = 2022;
int N, M, D, A[MAX];
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N >> M >> D;
    atcoder::mcf_graph<ll, ll> graph(N + 1);
    cinA(A, N);
    rep(i, 0, N){
        graph.add_edge(i, i + 1, A[i], D);
        graph.add_edge(i, i + 1, M - A[i], 0);
    }
    rep(i, 0, M){
        ll l, r, c;
        cin >> l >> r >> c; l--;
        graph.add_edge(l, r, 1, c);
    }
    auto [l, f] = graph.flow(0, N, M);
    cout << accumulate(A, A + N, 0LL) * D - f;
}
