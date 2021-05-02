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

const int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
int TC, R, C, A[1001][1001];
ll ans;
inline bool valid(int i, int j){
    return 0 <= i && i < R && 0 <= j && j < C;
}
int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> TC;
    rep(tc, 0, TC){
        cin >> R >> C;
        ans = 0;
        priority_queue<pair<int, pi> > pq;
        rep(i, 0, R) rep(j, 0, C){
            cin >> A[i][j];
            pq.push({A[i][j], {i, j}});
        }
        while(!pq.empty()){
            auto [M, p] = pq.top(); pq.pop();
            int x = p.x, y = p.y;
            if(A[x][y] != M) continue;
            rep(i, 0, 4){
                int nx = x + dx[i], ny = y + dy[i];
                if(!valid(nx, ny)) continue;
                if(M - 1 > A[nx][ny]){
                    ans += M - 1 - A[nx][ny];
                    A[nx][ny] = M - 1;
                    pq.push({M - 1, {nx, ny}});
                }
            }
        }
        printf("Case #%d: %lld\n", tc + 1, ans);
    }
}
