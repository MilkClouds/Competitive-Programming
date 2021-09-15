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
using ld = long double;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using pl = pair<ll, ll>;
using tl = tuple<ll, ll, ll>;

ll N, flag[4];
pl A[100], B[100], a, b;
set<pl> S;
pl rotate(pl a, int dir){
    if(dir == 0) return a;
    if(dir == 1) return {-a.y, a.x};
    if(dir == 2) return {-a.x, -a.y};
    return {a.y, -a.x};
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N;
    rep(i, 0, N) cin >> A[i].x >> A[i].y;
    rep(i, 0, N) cin >> B[i].x >> B[i].y;
    rep(i, 0, N) {
        a.x += A[i].x;
        a.y += A[i].y;
        b.x += B[i].x;
        b.y += B[i].y;
    }
    rep(i, 0, N){
        A[i].x = N * A[i].x - a.x;
        A[i].y = N * A[i].y - a.y;
        B[i].x = N * B[i].x - b.x;
        B[i].y = N * B[i].y - b.y;
        S.insert(B[i]);
    }
    rep(i, 0, N) cout << A[i].x << " " << A[i].y << endl;
    rep(i, 0, N) cout << B[i].x << " " << B[i].y << endl;
    rep(i, 0, N){
        rep(j, 0, 4) if(S.count(rotate(A[i], j)) == 0) flag[j] = 1;
    }
    rep(j, 0, 4) if(flag[j] == 0){
        cout << "Yes\n";
        return 0;
    }
    cout << "No\n";
}
