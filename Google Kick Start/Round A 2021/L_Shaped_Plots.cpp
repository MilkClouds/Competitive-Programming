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

const int MAX = 1000;
int TC, R, C, A[MAX][MAX], RR[MAX][MAX], L[MAX][MAX], U[MAX][MAX], D[MAX][MAX];
ll ans;
int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> TC;
    rep(tc, 0, TC){
        cin >> R >> C;
        ans = 0;
        rep(i, 0, R) rep(j, 0, C) {
            cin >> A[i][j];
            RR[i][j] = L[i][j] = U[i][j] = D[i][j] = A[i][j];
        }
        rep(i, 1, R) rep(j, 0, C) U[i][j] = (U[i - 1][j] + 1) * A[i][j];
        rep2(i, 0, R - 1) rep(j, 0, C) D[i][j] = (D[i + 1][j] + 1) * A[i][j];
        rep(i, 0, R) rep(j, 1, C) L[i][j] = (L[i][j - 1] + 1) * A[i][j];
        rep(i, 0, R) rep2(j, 0, C - 1) RR[i][j] = (RR[i][j + 1] + 1) * A[i][j];
        rep(i, 0, R) rep(j, 0, C){
            if(A[i][j] == 0) continue;
            queue<pi> Q;
            Q.push({U[i][j], RR[i][j]});
            Q.push({U[i][j], L[i][j]});
            Q.push({L[i][j], D[i][j]});
            Q.push({D[i][j], RR[i][j]});
            Q.push({RR[i][j], U[i][j]});
            Q.push({L[i][j], U[i][j]});
            Q.push({D[i][j], L[i][j]});
            Q.push({RR[i][j], D[i][j]});
            while(!Q.empty()){
                auto [a, b] = Q.front(); Q.pop();
                if(a >= b * 2) ans += b - 1;
                else if(a >= 4) ans += a / 2 - 1;
            }
        }
        printf("Case #%d: %lld\n", tc + 1, ans);
    }
}
