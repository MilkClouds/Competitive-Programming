#include <bits/stdc++.h>
#include <atcoder/modint>
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define rep2(i,a,b) for(int i = (b) - 1; i >= (a); i--)
#define cinA(A, N) rep(i, 1, N + 1) cin >> A[i];
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
using mint = atcoder::modint998244353;
using ll = int64_t;
using ull = uint64_t;
using ld = long double;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using pl = pair<ll, ll>;
using tl = tuple<ll, ll, ll>;

const int MAX = 3002;
int N, A[MAX], B[MAX];
mint dp[MAX][MAX], S[MAX][MAX];
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N;
    cinA(A, N); cinA(B, N);
    S[0][0] = dp[0][0] = 1;
    rep(j, 1, 3001){
        S[0][j] = S[0][j - 1] + dp[0][j];
    }
    rep(i, 1, N + 1){
        rep(j, A[i], B[i] + 1){
            dp[i][j] += S[i - 1][j];
        }
        S[i][0] = dp[i][0];
        rep(j, 1, 3001){
            S[i][j] = S[i][j - 1] + dp[i][j];
        }
    }
    cout << S[N][3000].val() << endl;
}
