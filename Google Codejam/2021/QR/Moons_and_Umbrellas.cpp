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

const int INF = 1e9;
int TC, X, Y, dp[1001][2];
string S;
int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> TC;
    rep(tc, 0, TC){
        cin >> X >> Y >> S;
        fill(dp[0], dp[S.size()], INF);
        if(S[0] == '?') dp[0][0] = dp[0][1] = 0;
        else if(S[0] == 'C') dp[0][0] = 0;
        else dp[0][1] = 0;
        rep(i, 1, S.size()){
            if(S[i] == '?' || S[i] == 'C'){
                dp[i][0] = min(dp[i - 1][0], dp[i - 1][1] + Y);
            }
            if(S[i] == '?' || S[i] == 'J'){
                dp[i][1] = min(dp[i - 1][1], dp[i - 1][0] + X);
            }
        }
        printf("Case #%d: %d\n", tc + 1, min(dp[S.size() - 1][0], dp[S.size() - 1][1]));
    }
}
