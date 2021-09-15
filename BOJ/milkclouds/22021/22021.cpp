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

//21 minutes used

int M, A[8][8], R[8], C[8], S;
char B[8][8];
void dfs(int i, int j, int k){
    if(j == 8)
    dfs(i, j + 1, k);
    B[i][j] = 1;
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> M;
    rep(i, 0, 8) rep(j, 0, 8) {
        cin >> A[i][j];
        A[i][j] -= M;
        R[i] += A[i][j];
        C[j] += A[i][j];
        S += A[i][j];
    }
    rep(i, 0, 8){
        R[i] = (R[i] - S / 15) / 7;
        C[i] = (C[i] - S / 15) / 7;
    }
    fill(B[0], B[8], '.');
    rep(i, 0, 8) rep(j, 0, 8){
        if(R[i] + C[j] > A[i][j]) B[i][j] = '+';
        else if(R[i] + C[j] < A[i][j]) B[i][j] = '-';
    }
    rep(i, 0, 8) rep(j, 0, 8) cout << B[i][j] << " \n"[j == 7];
}
