# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define rep2(i,a,b) for(int i = (b) - 1; i >= (a); i--)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define x first
#define y second
using namespace std;
using ll = long long;
using tl = tuple<ll, ll, ll, ll>;
using pl = pair<ll, ll>;
using pi = pair<int, int>;
using ld = long double;

const int MAX = 2e3 + 10, INF = 2e9 + 10;
ll n, k, p, a[MAX], b[MAX], dp[MAX][MAX], d[MAX][MAX];
ll solve(ll i, ll j){
    if(i == n) return 0;
    if(n - i > k - j) return INF;
    ll& ret = dp[i][j];
    if(~ret) return ret;
    ret = min(solve(i, j + 1), max(solve(i + 1, j + 1), d[i][j]));
    return ret;
}
int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> n >> k >> p;
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, k) cin >> b[i];
    sort(a, a + n);
    sort(b, b + k);
    rep(i, 0, n) rep(j, 0, k){
        d[i][j] = abs(a[i] - b[j]) + abs(b[j] - p);
    }
    fill(dp[0], dp[n], -1);
    cout << solve(0, 0);
}
