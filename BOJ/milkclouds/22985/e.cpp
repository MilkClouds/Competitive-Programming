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

const int MOD = 1e9 + 7, MAXN = 305;
ll N, M, dp[MAXN][MAXN * 26][2];
string S;
int solve(int N, int M, bool flag){
    ll& ret = dp[N][M][flag];
    if(~ret) return ret;
    if(N == 0) {
        if(flag == 0) return ret = M == 0;
        return 1;
    }
    ret = 0;
    rep(i, 0, M + 1){
        if(i + S[N - 1] - 'z' > 0) break;
        ret += solve(N - 1, M - i, flag | (i + S[N - 1] - 'z' >= 0));
        ret %= MOD;
    }
    return ret;
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N >> M >> S; M = min(M, N * 26);
    fill(dp[0][0], dp[N + 2][0], -1);
    cout << solve(N, M, 0) << endl;
}
