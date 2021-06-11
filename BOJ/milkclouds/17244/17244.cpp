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
using ti = tuple<int, int, int>;

const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, -1, 1}, INF = 1e9;
int N, M, A[51][51], cnt, dist[51][51][32], x, y, mask;
pi ST, EN;
string S[51];
inline bool valid(int x, int y){
    return 0 <= x && x < M && 0 <= y && y < N;
}
int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N >> M;
    rep(i, 0, M) cin >> S[i];
    rep(i, 0, M) rep(j, 0, N){
        if(S[i][j] == 'X') A[i][j] = cnt++;
        else if(S[i][j] == 'S') ST = {i, j};
        else if(S[i][j] == 'E') EN = {i, j};
    }
    fill(dist[0][0], dist[M][N], INF);
    dist[ST.x][ST.y][0] = 0;
    queue<ti> Q; Q.push({ST.x, ST.y, 0});
    while(!Q.empty()){
        tie(x, y, mask) = Q.front(); Q.pop();
        rep(i, 0, 4){
            int nx = x + dx[i], ny = y + dy[i], nmask = mask;
            if(!valid(nx, ny) || S[nx][ny] == '#') continue;
            if(S[nx][ny] == 'X') nmask |= 1 << A[nx][ny];
            if(dist[nx][ny][nmask] > dist[x][y][mask] + 1){
                dist[nx][ny][nmask] = dist[x][y][mask] + 1;
                Q.push({nx, ny, nmask});
            }
        }
    }
    cout << dist[EN.x][EN.y][(1 << cnt) - 1] << endl;
}