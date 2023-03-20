#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i = (a); i < (b); i++)
#define rep2(i,a,b) for(ll i = (b) - 1; i >= (a); i--)
#define cinA(A, N) rep(i, 0, N) cin >> A[i];
using namespace std;
using ll = long long;

const int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, -1, 1};
int N, cnt, f;
string A[100];
bool B[100][100];
bool same(char a, char b){
    if(f){
        if(a == 'R') a = 'G';
        if(b == 'R') b = 'G';
    }
    return a == b;
}
void dfs(int i, int j){
    B[i][j] = 1;
    rep(k, 0, 4){
        int x = i + dx[k], y = j + dy[k];
        if((0 <= x && x < N) && (0 <= y && y < N) && !B[x][y] && same(A[i][j], A[x][y])) dfs(x, y);
    }
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N;
    cinA(A, N);
    rep(i, 0, N) rep(j, 0, N) {
        if(B[i][j]) continue;
        dfs(i, j); cnt++;
    }
    cout << cnt << " ";
    cnt = 0; f = 1;
    fill(B[0], B[100], 0);
    rep(i, 0, N) rep(j, 0, N) {
        if(B[i][j]) continue;
        dfs(i, j); cnt++;
    }
    cout << cnt;
}
