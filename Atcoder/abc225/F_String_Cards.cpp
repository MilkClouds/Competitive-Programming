#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define rep2(i,a,b) for(int i = (b) - 1; i >= (a); i--)
#define cinA(A, N) rep(i, 0, N) cin >> A[i];
#define coutA(A, N) rep(i, 0, N) cout << A[i] << " ";
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define eb emplace_back
#define popcount __builtin_popcount
#define popcountll __builtin_popcountll
#define x first
#define y second
using namespace std;
using ll = int64_t;
using ull = uint64_t;
using ld = long double;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using pl = pair<ll, ll>;
using tl = tuple<ll, ll, ll>;

int N, K;
string S[51], dp[51][51];
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N >> K;
    rep(i, 0, N) cin >> S[i];
    sort(S, S + N, [](string& a, string& b){return a + b < b + a;});
    fill(dp[0], dp[N], "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz");
    dp[N - 1][0] = "";
    dp[N - 1][1] = S[N - 1];
    rep2(i, 0, N - 1){
        dp[i][0] = "";
        rep(j, 1, N - i + 1){
            dp[i][j] = min(dp[i + 1][j], S[i] + dp[i + 1][j - 1]);
        }
    }
    cout << dp[0][K] << endl;
}
