# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#include <atcoder/modint>
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

const int MAX = 1025;
int N;
string S;
atcoder::modint998244353 dp[MAX][MAX][11], ans = -1;
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N >> S;
    dp[0][0][0] = 1;
    rep(i, 0, N){
        int mask = 1 << S[i] - 'A';
        rep(j, 0, 1 << 10){
            rep(k, 0, 11) dp[i + 1][j][k] += dp[i][j][k];
            if(j & mask) {
                rep(k, 0, 11) dp[i + 1][j][S[i] - 'A' + 1] += dp[i][j ^ mask][k];
                dp[i + 1][j][S[i] - 'A' + 1] += dp[i][j][S[i] - 'A' + 1];
            }
        }
    }
    rep(j, 0, 1 << 10) rep(k, 0, 11) ans += dp[N][j][k];
    cout << ans.val() << endl;
}
