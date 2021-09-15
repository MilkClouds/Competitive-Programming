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

const int MAX = 2e5 + 1, INF = 2e9;
int N, K, A[MAX], m = INF, dp[MAX][32];
void setmin(int& a, int b){
    if(a > b) a = b;
}
int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N >> K;
    rep(i, 0, N) cin >> A[i];
    sort(A, A + N);
    fill(dp[0], dp[N + 1], INF);
    dp[N][0] = 0;
    rep2(i, 1, N + 1){
        rep(j, 0, 32){
            if(dp[i][j] == INF) continue;
            auto pos = upper_bound(A, A + N, A[i - 1] / 2);
            setmin(dp[pos - A][j + 1], dp[i][j]);
            setmin(dp[i - 1][j], dp[i][j] + 1);
        }
    }
    rep(i, 0, 32) if(dp[0][i] <= K){
        cout << i << " " << dp[0][i] << endl;
        return 0;
    }
}