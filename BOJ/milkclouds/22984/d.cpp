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

const int MAX = 1e5+ 10;
int N;
double p[MAX], dp[MAX][2];
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N;
    rep(i, 1, N + 1) cin >> p[i];
    dp[1][1] = 1;
    rep(i, 2, N + 1){
        dp[i][0] = dp[i - 1][0] * (1 - p[i - 1]) + (1 + dp[i - 1][1]) * p[i - 1];
        dp[i][1] = (2 + dp[i - 1][0]) * (1 - p[i - 1]) + (1 + dp[i - 1][1]) * p[i - 1];
    }
    cout << fixed;
    cout.precision(18);
    cout << (1 - p[N]) * dp[N][0] + dp[N][1] * p[N] << endl;
}
