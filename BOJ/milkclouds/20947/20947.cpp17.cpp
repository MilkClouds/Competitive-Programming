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


const int MAX = 2001, dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
int N, dp[MAX][MAX][4];
string S[MAX];

inline bool valid(int i){return 0 <= i && i < N;}
bool solution(int i, int j, int dir){
    if(~dp[i][j][dir]) return dp[i][j][dir];
    if(S[i][j] == 'O') return dp[i][j][dir] = 0;
    if(S[i][j] == 'X') return dp[i][j][dir] = 1;
    int ni = i + dx[dir], nj = j + dy[dir];
    if(valid(ni) && valid(nj)) return dp[i][j][dir] = solution(ni, nj, dir);
    else return dp[i][j][dir] = 1;
}

int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N;
    rep(i, 0, N) cin >> S[i];
    fill(dp[0][0], dp[N][N], -1);
    rep(i, 0, N) {
        rep(j, 0, N){
            if(S[i][j] != '.') continue;
            bool tmp = 1;
            rep(dir, 0, 4){
                tmp &= solution(i, j, dir);
            }
            if(tmp) S[i][j] = 'B';
        }
    }
    rep(i, 0, N) cout << S[i] << "\n";
}
