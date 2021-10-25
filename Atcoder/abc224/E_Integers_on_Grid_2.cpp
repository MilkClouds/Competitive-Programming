#include <bits/stdc++.h>
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
using ll = int64_t;
using ull = uint64_t;
using ld = long double;
using ti = tuple<int, int, int>;

const int MAX = 2e5;
int H, W, N, R[MAX], C[MAX], ans[MAX];
vector<ti> V;
map<int, vector<int>> M;
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> H >> W >> N;
    rep(i, 0, N){
        int r, c, a;
        cin >> r >> c >> a; r--; c--;
        V.eb(r, c, a);
        M[-a].eb(i);
    }
    for(auto [_, v]: M){
        map<int, int> A, B;
        for(auto i: v){
            auto [r, c, a] = V[i];
            ans[i] = max(R[r], C[c]);
            A[r] = max(ans[i] + 1, A[r]);
            B[c] = max(ans[i] + 1, B[c]);
        }
        for(auto [r, i]: A) R[r] = i;
        for(auto [c, i]: B) C[c] = i;
    }
    rep(i, 0, N) cout << ans[i] << "\n";
}
