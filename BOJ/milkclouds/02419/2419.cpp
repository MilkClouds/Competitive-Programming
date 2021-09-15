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

const int MAX = 1111;
const ll INF = 6e18;
ll N, M, A[MAX], dp[MAX][MAX][2], C, ans;
ll solve(int i, int j, int dir, int rem){
    if(rem == 0) return 0;
    ll& ret = dp[i][j][dir];
    if(~ret) return ret;
    ret = INF;
    if(dir == 0){
        if(i > 0) ret = min(ret, solve(i - 1, j, 0, rem - 1) + rem * (A[i] - A[i - 1]));
        if(j < N - 1) ret = min(ret, solve(i, j + 1, 1, rem - 1) + rem * (A[j + 1] - A[i]));
    } else{
        if(i > 0) ret = min(ret, solve(i - 1, j, 0, rem - 1) + rem * (A[j] - A[i - 1]));
        if(j < N - 1) ret = min(ret, solve(i, j + 1, 1, rem - 1) + rem * (A[j + 1] - A[j]));
    }
    return ret;
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N >> M;
    rep(i, 0, N) cin >> A[i];
    A[N] = 0; N++;
    sort(A, A + N);
    rep(i, 0, N) if(A[i] == 0) C = i;
    rep(i, 0, N + 1){
        fill(dp[0][0], dp[N][N], -1);
        ans = max(ans, i * M - solve(C, C, 0, i));
    }
    cout << ans << endl;
}
