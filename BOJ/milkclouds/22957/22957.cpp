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

ll dp[32][32][32][32], S[32][8], SS[32][8][3], T, N, K;
string solve(ll N, ll K, int mask){
    if(N == 0) return "";
    ll div, mod;
    if(K < SS[N][mask][0]){
        div = 0;
        mod = K;
    } else if(K < SS[N][mask][0] + SS[N][mask][1]){
        div = 1;
        mod = K - SS[N][mask][0];
    } else{
        div = 2;
        mod = K - SS[N][mask][0] - SS[N][mask][1];
    }
    return "357"[div] + solve(N - 1, mod, mask ^ 1 << div);
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N >> K;
    dp[0][0][0][0] = 1;
    rep(n, 1, N + 1){
        rep(i, 0, n + 1) rep(j, 0, n + 1 - i){
            int k = n - i - j;
            int mask = (k & 1) << 2 | (j & 1) << 1 | (i & 1) << 0;
            if(i) dp[n][i][j][k] += dp[n - 1][i - 1][j][k];
            if(j) dp[n][i][j][k] += dp[n - 1][i][j - 1][k];
            if(k) dp[n][i][j][k] += dp[n - 1][i][j][k - 1];
            rep(Mask, 0, 8){
                if(mask == Mask) continue;
                if(i) SS[n][Mask][0] += dp[n - 1][i - 1][j][k];
                if(j) SS[n][Mask][1] += dp[n - 1][i][j - 1][k];
                if(k) SS[n][Mask][2] += dp[n - 1][i][j][k - 1];
                S[n][Mask] += dp[n][i][j][k];
            }
        }
        T += S[n][0b000];
    }
    K = T - K;
    T = 0;
    rep(n, 1, N + 1){
        if(T + S[n][0b000] > K){
            K -= T;
            cout << solve(n, K, 0b000);
            return 0;
        }
        T += S[n][0b000];
    }
}