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

int N, M, dp[21][1048576], chk[10];
string S[10];
int solve(int i, int mask){
    if(~dp[i][mask]) return dp[i][mask];
    vector<int> v(2 * M + 1);
    rep(k, 0, 2 * M) {
        if(mask & (1 << k)) continue;
        v[solve(i, mask | (1 << k))] = 1;
    }
    rep(j, 0, M - 1){
        bool flag = 0;
        rep(k, 0, 4) if(mask & (1 << 2 * j + k)) {flag = 1; break;}
        if(flag) continue;
        int tmask = mask;
        rep(k, 0, 4) tmask |= 1 << 2 * j + k;
        v[solve(i, tmask)] = 1;
    }
    rep(j, 0, 2 * M + 1) if(v[j] == 0) return dp[i][mask] = j;
    return -1;
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    rep(i, 0, 3){        
        cin >> N >> M;
        fill(dp[0], dp[N], -1);
        fill(chk, chk + N, 0);
        rep(i, 0, N) dp[i][(1 << 2 * M) - 1] = 0;
        rep(i, 0, N) cin >> S[i];
        int ans = 0;
        rep(i, 0, N) rep(j, 0, M) if(S[i][j] == '#'){
            chk[(i / 2) * 2] |= 1 << (i - (i / 2) * 2 + 2 * j);
        }
        rep(i, 0, N / 2) {
            ans ^= solve(i * 2, chk[i * 2]);
        }
        if(N & 1) ans ^= (M - popcount(chk[N - 1])) & 1;
        cout << (ans ? "Y" : "M") << "\n";
    }
}
