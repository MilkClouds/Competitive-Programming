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

int N, dp[1 << 7][200001];
string S, X;

int mod(int i){
    i = i % 7;
    return i < 0 ? i + 7 : i;
}
int solution(int mask, int n){
    if(dp[mask][n]) return dp[mask][n];
    if(n == N) return dp[mask][n] = (mask & 1) ? 1: - 1;
    int tmp = 0;
    rep(i, 0, 7){
        if(mask & (1 << i)){
            tmp |= 1 << mod(i * 10 + S[n] - '0');
            tmp |= 1 << mod(i * 10);
        }
    }
    rep(i, 0, 7){
        if(tmp & (1 << i)){
            if(X[n] == 'A') if(solution(1 << i, n + 1) == -1) return dp[mask][n] = -1;
            if(X[n] == 'T') if(solution(1 << i, n + 1) == 1) return dp[mask][n] = 1;
        }
    }
    if(X[n] == 'A') return dp[mask][n] = 1;
    return dp[mask][n] = -1;
}

int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N >> S >> X;
    cout << (solution(1, 0) == 1 ? "Takahashi" : "Aoki");
}
