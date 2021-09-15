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
#define x first
#define y second
using namespace std;
using ll = long long;
using tl = tuple<ll, ll, ll, ll>;
using pl = pair<ll, ll>;
using pi = pair<int, int>;
using ld = long double;

int a, b, c;
ld dp[101][101][101];
ld solve(int i, int j, int k){
    if(i == 100 || j == 100 || k == 100) return 0;
    if(dp[i][j][k]) return dp[i][j][k];
    return dp[i][j][k] = (solve(i + 1, j, k) * i + solve(i, j + 1, k) * j + solve(i, j, k + 1) * k) / (i + j + k) + 1;
}
int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> a >> b >> c;
    cout.precision(11);
    cout << solve(a, b, c);
}
