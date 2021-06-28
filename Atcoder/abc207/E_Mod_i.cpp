# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
#define _CRT_SECURE_NO_WARNINGS
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

const int MAX = 3e3 + 10, MOD = 1e9 + 7;
int N;
ll A[MAX], S[MAX], dp[MAX][MAX], ans, memo[MAX][MAX];
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N;
    rep(i, 0, N) cin >> A[i + 1];
    rep(i, 1, N + 1) S[i] = S[i - 1] + A[i];
    memo[1][0] = dp[0][0] = 1;
    rep(i, 1, N + 1) {
        rep(j, 1, i + 1){
            dp[i][j] = memo[j][S[i] % j];
        }
        rep(j, 1, i + 2){
            memo[j][S[i] % j] += dp[i][j - 1];
            memo[j][S[i] % j] %= MOD;
        }
    }
    rep(i, 0, N) ans += dp[N][i + 1];
    cout << ans % MOD << endl;
}
