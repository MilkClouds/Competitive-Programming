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

const ll INF = 6e18;
const int MAX = 1022;
int H, W;
ll A[MAX][MAX], T[MAX][MAX][2], ans = INF, C;
inline bool valid(int i, int j){
    return 1 <= i && i <= H && 1 <= j && j <= W;
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> H >> W >> C;
    rep(i, 0, H) rep(j, 0, W) cin >> A[i + 1][j + 1];
    rep(i, 0, H + 2) rep(j, 0, W + 2){
        if(valid(i, j)) continue;
        T[i][j][0] = T[i][j][1] = INF;
    }
    rep2(i, 1, H + 1) rep2(j, 1, W + 1){
        T[i][j][0] = C * (i + j) + A[i][j];
        T[i][j][0] = min({T[i][j][0], T[i + 1][j][0], T[i][j + 1][0]});
    }
    rep2(i, 1, H + 1) rep(j, 1, W + 1){
        T[i][j][1] = C * (i - j) + A[i][j];
        T[i][j][1] = min({T[i][j][1], T[i + 1][j][1], T[i][j - 1][1]});
    }
    rep(i, 1, H + 1) rep(j, 1, W + 1){
        ans = min(ans, min(T[i + 1][j][0], T[i][j + 1][0]) + A[i][j] - C * (i + j));
        ans = min(ans, min(T[i + 1][j][1], T[i][j - 1][1]) + A[i][j] - C * (i - j));
    }
    cout << ans << endl;
}
