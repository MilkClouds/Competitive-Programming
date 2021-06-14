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
using tl = tuple<ll, ll, ll, ll>;
using pl = pair<ll, ll>;
using pi = pair<int, int>;
using ld = long double;

const int MAX = 1e6 + 1;
int A[2], m, N, dp[MAX];
int mex(int a, int b, int c){
    rep(i, 0, 4) if(i != a && i != b && i != c) return i;
    return -1;
}
int solve(int N){
    if(N < 0) return 1235;
    if(~dp[N]) return dp[N];
    return dp[N] = mex(solve(N - 1), solve(N - A[0]), solve(N - A[1]));
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> A[0] >> A[1] >> m;
    fill(dp, dp + MAX, -1);
    dp[0] = 0;
    while(m--){
        cin >> N;
        cout << (solve(N) ? 'A' : 'B');
    }
}
