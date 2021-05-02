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

const int dx[] = {-1, -1, 1, 1}, dy[] = {1, -1, 1, -1};
const int dx2[] = {-1, 0, 1, 0}, dy2[] = {0, -1, 0, 1};
int n, a, A[101][101], flag;
inline bool valid(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < n;
}
void query(int b, int i, int j){
    cout << b << " " << i + 1 << " " << j + 1 << endl;
    A[i][j] = b;
    flag = 1;
}
int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> n;
    rep(_, 0, n * n){
        cin >> a;
        flag = 0;
        rep(x, 0, n) rep(y, 0, n){
            if(A[x][y]) continue;
            if(flag) break;
            rep(k, 0, 4){
                int nx = x + dx[k], ny = y + dy[k];
                if(!valid(nx, ny) || !A[nx][ny] || A[nx][ny] == a) continue;
                query(A[nx][ny], x, y);
                break;
            }
        }
        if(flag) continue;
        rep(x, 0, n) rep(y, 0, n){
            if(A[x][y]) continue;
            if(flag) break;
            set<int> S; S.insert(1); S.insert(2); S.insert(3);
            rep(k, 0, 4){
                int nx = x + dx2[k], ny = y + dy2[k];
                if(!valid(nx, ny) || A[nx][ny] == 0) continue;
                S.erase(A[nx][ny]);
            }
            S.erase(a);
            query(*S.begin(), x, y);
            break;
        }
    }
}
