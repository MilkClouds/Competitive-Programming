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

int N;
ll dp[61][2];
string S[61];
int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N;
    rep(i, 0, N) {
        cin >> S[i];
    }
    dp[0][1] = dp[0][0] = 1;
    rep(i, 1, N + 1){
        if(S[i - 1] == "OR"){
            dp[i][1] = dp[i - 1][0] + 2 * dp[i - 1][1];
            dp[i][0] = dp[i - 1][0];
        } else {
            dp[i][1] = dp[i - 1][1];
            dp[i][0] = dp[i - 1][1] + dp[i - 1][0] * 2;
        }
    }
    cout << dp[N][1];
}
