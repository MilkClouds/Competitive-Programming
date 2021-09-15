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

const int MAX = 5003, MOD = 998244353;
int N, dp[MAX][MAX][2], ans;
pi A[MAX];
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N;
    rep(i, 0, N) cin >> A[i].x;
    rep(i, 0, N) cin >> A[i].y;
    sort(A, A + N);
    dp[0][0][0] = 1;
    rep(i, 0, N){
        rep(j, 0, 5001){
            if(A[i].y + j > 5000) break;
            dp[i + 1][A[i].y + j][1] += dp[i][j][1] + dp[i][j][0];
            dp[i + 1][A[i].y + j][1] %= MOD;
        }
        rep(j, 0, 5001){
            dp[i + 1][j][0] += dp[i][j][0] + dp[i][j][1];
            dp[i + 1][j][0] %= MOD;
        }
        rep(j, 0, A[i].x + 1) ans += dp[i + 1][j][1], ans %= MOD;
    }
    cout << ans << endl;
}
