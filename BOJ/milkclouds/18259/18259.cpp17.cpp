#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define rep(a,b,c) for(int a = b; a < c; a++)
#define rep2(a,b,c) for(int a = c - 1; a >=b; a--)
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

const int MAX = 300;
int N, M, dp[MAX][MAX], mx[MAX][MAX][MAX], w, l, r;

void setmax(int& a, int b) {
    if (a < b) a = b;
}

int solution(int l, int r) {
    if (l > r) return 0;
    if (~dp[l][r]) return dp[l][r];
    int& ans = dp[l][r];
    rep(i, l + 1, r + 1) setmax(ans, solution(l, i - 1) + solution(i, r));
    rep(i, l, r + 1) setmax(ans, solution(l, i - 1) + solution(i + 1, r) + mx[i][l][r]);
    return ans;
}

int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N >> M;
    fill(dp[0], dp[N], -1);
    rep(_, 0, M) {
        cin >> w >> l >> r; l--; r--;
        rep(i, l, r + 1) {
            setmax(mx[i][l][r], w);
        }
    }
    rep(i, 0, N) {
        rep2(l, 0, i + 1) rep(r, i, N) {
            if (l) setmax(mx[i][l - 1][r], mx[i][l][r]);
            if (r + 1 < N) setmax(mx[i][l][r + 1], mx[i][l][r]);
        }
    }
    cout << solution(0, N - 1);
    return 0;
}
