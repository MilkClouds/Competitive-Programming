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

const int MAX = 2001, INF = 1e9;
const int dx[] = {1, 0}, dy[] = {0, 1};
int H, W, dp[MAX][MAX];
string S[MAX];
inline bool valid(int x, int y){
    return 0 <= x && x < H && 0 <= y && y < W;
}
inline int f(char x){
    return x == '+' ? 1 : -1;
}
int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> H >> W;
    rep(i, 0, H) cin >> S[i];
    rep2(i, 0, H) rep2(j, 0, W){
        if(i == H - 1 && j == W - 1) continue;
        int ans = -INF;
        rep(t, 0, 2){
            int x = i + dx[t], y = j + dy[t];
            if(!valid(x, y)) continue;
            ans = max(ans, -dp[x][y] + f(S[x][y]));
        }
        dp[i][j] = ans;
    }
    if(dp[0][0] == 0) cout << "Draw";
    else if(dp[0][0] > 0) cout << "Takahashi";
    else cout << "Aoki";
}
