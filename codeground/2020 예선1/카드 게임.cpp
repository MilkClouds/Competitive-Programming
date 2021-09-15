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

const int MAX = 3005;
int TC, N, K, A[MAX], B[MAX], i, j, S1[MAX][MAX], S2[MAX][MAX], C[MAX], D[MAX];
ll E[MAX], F[MAX];
bool dp[MAX][MAX];
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> TC;
    rep(tc, 1, TC + 1){
        int a = 0;
        cin >> N >> K;
        rep(i, 1, N + 1) cin >> A[i];
        rep(i, 1, N + 1) cin >> B[i];
        rep(i, 1, N + 1) E[i] = E[i - 1] + A[i];
        rep(i, 1, N + 1) F[i] = F[i - 1] + B[i];
        rep(i, 0, N + 1) C[i] = lower_bound(E, E + N + 1, E[i] - K) - E;
        rep(i, 0, N + 1) D[i] = lower_bound(F, F + N + 1, F[i] - K) - F;
        dp[0][0] = 1;
        rep(i, 0, N + 1) {
            if(i) rep(j, 0, N + 1) S1[j][i] = S1[j][i - 1];
            else rep(j, 0, N + 1) S1[j][i] = 0;
            S2[i][0] = 0;
            rep(j, 0, N + 1){
                if(i == 0 && j == 0) {
                    if(j < N) S2[i][j + 1] = S2[i][j];
                    continue;
                }
                int p1 = C[i], p2 = D[j];
                dp[i][j] = (S1[j][i] - (p1 ? S1[j][p1 - 1] : 0)) || (S2[i][j] - (p2 ? S2[i][p2 - 1] : 0));
                if(dp[i][j] == 0) S1[j][i]++, S2[i][j]++;
                if(j < N) S2[i][j + 1] = S2[i][j];
            }
        }
        rep(i, 0, N + 1) rep(j, 0, N + 1) a += dp[i][j];
        cout << "Case #" << tc << "\n";
        cout << a << " " << (N + 1) * (N + 1) - a << "\n";
    }
}
