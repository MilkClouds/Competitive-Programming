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

const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, -1, 1};
int N, M, ans = 5000, kills;
string S[21];
inline bool valid(int i, int j){
    return 0 <= i && i < N && 0 <= j && j < M;
}
int query(int i, int j, int k, int l){
    vector<vector<bool>> vis(N, vector<bool>(M, 0));
    queue<pi> Q; Q.push({i, j}); Q.push({k, l});
    vis[i][j] = vis[k][l] = 1;
    int cnt = 0, kill = 0;
    while(1){
        int tmp = Q.size();
        rep(_, 0, tmp)
        {
            int x, y;
            tie(x, y) = Q.front(); Q.pop();
            kill += S[x][y] == '1';
            rep(i, 0, 4){
                int nx = x + dx[i], ny = y + dy[i];
                if(!valid(nx, ny) || vis[nx][ny]) continue;
                vis[nx][ny] = 1;
                Q.emplace(nx, ny);
            }
        }
        if(Q.empty() || kill == kills) break;
        cnt++;
    }
    return cnt;
}
int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N >> M;
    rep(i, 0, N) cin >> S[i];
    rep(i, 0, N) rep(j, 0, M) kills += S[i][j] == '1';
    rep(i, 0, N) rep(j, 0, M) rep(k, 0, N) rep(l, 0, M){
        if(i == k && j == l) continue;
        if(S[i][j] == '1' || S[k][l] == '1') continue;
        ans = min(ans, query(i, j, k, l));
    }
    cout << ans;
}
