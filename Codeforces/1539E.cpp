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

// https://codeforces.com/contest/1539/problem/E

const int MAX = 1e5 + 20;
int N, M, V[MAX], ans[MAX][2];
pi L[MAX], R[MAX];
inline bool in(pi a, int b){
    return a.x <= b && b <= a.y;
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N >> M;
    rep(i, 0, N) cin >> V[i] >> L[i].x >> L[i].y >> R[i].x >> R[i].y;
    L[N].x = R[N].x = 0;
    L[N].y = R[N].y = M;
    rep2(i, 0, N){
        int Lx = L[i].x, Ly = L[i].y, Rx = R[i].x, Ry = R[i].y;
        // ans[i][0] : i에서, Left 선택, i + 1 교차여부
        // ans[i][1] : i에서, Right 선택, i + 1 교차여부
        // L[i]: i에서, Right 선택, Left의 가능범위
        // R[i]: i에서, Left 선택, Right의 가능범위
        if(in({Lx, Ly}, V[i])){
            if(in(L[i + 1], V[i])) ans[i][0] = 1;
            else {
                R[i].x = max(R[i].x, R[i + 1].x);
                R[i].y = min(R[i].y, R[i + 1].y);
                ans[i][0] = 0;
            }
        } else R[i] = {M, 0};
        if(in({Rx, Ry}, V[i])){
            if(in(R[i + 1], V[i])) ans[i][1] = 1;
            else {
                L[i].x = max(L[i].x, L[i + 1].x);
                L[i].y = min(L[i].y, L[i + 1].y);
                ans[i][1] = 0;
            }
        } else L[i] = {M, 0};
    }
    if(!in(L[0], 0) && !in(R[0], 0)){
        cout << "No\n";
        return 0;
    }
    cout << "Yes\n";
    for(int i = 0, j = in(L[0], 0); i < N; j ^= ans[i][j], i++){
        cout << j << " \n"[i == N - 1];
    }
}

