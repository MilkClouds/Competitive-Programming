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

const int MAX = 1e5 + 10, INF = 1e9;
int N, dp[27];
string S;
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N >> S;
    S += "{";
    fill(dp, dp + 27, INF);
    dp[S[0] - 'a'] = 0;
    rep(i, 0, N){
        rep(j, 0, 26){
            if(S[i] - 'a' == j) continue;
            dp[S[i + 1] - 'a'] = min(dp[S[i + 1] - 'a'], dp[j] + 1);
        }
    }
    if(INF == dp[26]) cout << -1;
    else cout << dp[26];
}
