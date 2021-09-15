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

const int MAX = 801;
int N, K, A[MAX][MAX], S[MAX][MAX];
int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N >> K;
    rep(i, 0, N) rep(j, 0, N) cin >> A[i][j];
    int limit = (K * K) / 2 + 1;
    int l = -1, r = 1e9;
    while(l + 1 < r){
        int m = l + r >> 1;
        rep(i, 0, N) rep(j, 0, N){
            S[i + 1][j + 1] = S[i + 1][j] + S[i][j + 1] - S[i][j] + (A[i][j] > m);
        }
        bool chk = 0;
        rep(i, 0, N - K + 1) rep(j, 0, N - K + 1){
            if(S[i + K][j + K] - S[i][j + K] - S[i + K][j] + S[i][j] < limit) chk = 1;
        }
        if(chk) r = m;
        else l = m;
    }
    cout << r;
}
