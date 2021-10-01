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
using mi = atcoder::modint998244353;

const int MAX = 1e5 + 1;
int N, A[MAX];
mi dp[MAX][10];
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N;
    rep(i, 0, N) cin >> A[i];
    dp[0][A[0]] = 1;
    rep(i, 1, N){
        rep(j, 0, 10){
            dp[i][(j + A[i]) % 10] += dp[i - 1][j];
            dp[i][(j * A[i]) % 10] += dp[i - 1][j];
        }
    }
    rep(i, 0, 10) cout << dp[N - 1][i].val() << "\n";
}
