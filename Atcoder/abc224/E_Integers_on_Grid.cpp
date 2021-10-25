#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define rep2(i,a,b) for(int i = (b) - 1; i >= (a); i--)
#define cinA(A, N) rep(i, 0, N) cin >> A[i];
#define coutA(A, N) rep(i, 0, N) cout << A[i] << " ";
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
using ll = int64_t;
using ull = uint64_t;
using ti = tuple<int, int, int>;
using pl = pair<ll, ll>;
using tl = tuple<ll, ll, ll>;

const int MAX = 2e5 + 1;
int H, W, N;
ll dp[MAX], R[MAX], C[MAX];
tl A[MAX];
pl B[MAX];
vector<tl> tmp;
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> H >> W >> N;
    rep(i, 0, N){
        int r, c, a;
        cin >> r >> c >> a; r--; c--;
        A[i] = {r, c, a};
        B[i] = {a, i};
    }
    sort(B, B + N, greater<pl>());
    fill(R, R + H, -1);
    fill(C, C + W, -1);
    rep(i, 0, N){
        auto [r, c, a] = A[B[i].y];
        if(i && get<2>(A[B[i - 1].y]) != a){
            for(auto [r, c, a]: tmp) R[r] = max(R[r], a), C[c] = max(C[c], a);
            tmp.clear();
        }
        ll& ret = dp[B[i].y];
        ret = max(ret, R[r] + 1);
        ret = max(ret, C[c] + 1);
        tmp.eb(r, c, ret);
    }
    rep(i, 0, N) cout << dp[i] << "\n";
}
