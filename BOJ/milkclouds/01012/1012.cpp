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

const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, -1, 1};
int TC, N, M, K, i, j;
vector<int> A[500];
inline bool valid(int i, int j){
    return 0 <= i && i < N && 0 <= j && j < M;
}
int dfs(int x, int y){
    if(A[x][y] == 0) return 0;
    A[x][y] = 0;
    rep(i, 0, 4){
        int nx = x + dx[i], ny = y + dy[i];
        if(!valid(nx, ny)) continue;
        dfs(nx, ny);
    }
    return 1;
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> TC;
    while(TC--){
        cin >> N >> M >> K;
        int ans = 0;
        rep(i, 0, N) A[i].assign(M, 0);
        rep(_, 0, K){
            cin >> i >> j;
            A[i][j] = 1;
        }
        rep(i, 0, N) rep(j, 0, M) ans += dfs(i, j);
        cout << ans << "\n";
    }
}
