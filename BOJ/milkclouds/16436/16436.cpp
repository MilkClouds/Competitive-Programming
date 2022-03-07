#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define rep2(i,a,b) for(int i = (b) - 1; i >= (a); i--)
#define cinA(A, N) rep(i, 0, N) cin >> A[i];
#define coutA(A, N) rep(i, 0, N) cout << A[i] << " ";
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define eb emplace_back
#define popcount __builtin_popcount
#define popcountll __builtin_popcountll
#define x first
#define y second
using namespace std;
using ll = long long;
using ull = uint64_t;
using ld = long double;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using pl = pair<ll, ll>;
using tl = tuple<ll, ll, ll>;

const int MAX = 2502;
int W, H, K, c, px, py, qx, qy, r, A[MAX][MAX], B[MAX * 2][MAX * 2];
inline bool valid(int x, int y){
    return 0 <= x && x < H && 0 <= y && y < W;
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> W >> H >> K;
    rep(i, 0, K){
        cin >> c;
        if(c == 1){
            cin >> py >> px >> qy >> qx;
            A[px][py]++;
            A[px][qy + 1]--;
            A[qx + 1][py]--;
            A[qx + 1][qy + 1]++;
        } else {
            cin >> py >> px >> r;
            // (x, y) -> (x + y, x - y + W)
            B[px + py - r][px - py + W - r]++;
            B[px + py - r][px - py + W + r + 1]--;
            B[px + py + r + 1][px - py + W - r]--;
            B[px + py + r + 1][px - py + W + r + 1]++;
        }
    }
    rep(i, 0, H) rep(j, 0, W) A[i + 1][j] += A[i][j];
    rep(i, 0, H) rep(j, 0, W) A[i][j + 1] += A[i][j];
    rep(i, 0, H + W) rep(j, 0, H + W) B[i + 1][j] += B[i][j];
    rep(i, 0, H + W) rep(j, 0, H + W) B[i][j + 1] += B[i][j];
    rep(i, 0, H){
        rep(j, 0, W) {
            A[i][j] += B[i + j][i - j + W];
            cout << (A[i][j] % 2 ? '#' : '.');
        }
        cout << "\n";
    }
}
