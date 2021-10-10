#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define rep2(i,a,b) for(int i = (b) - 1; i >= (a); i--)
#define cinA(A, N) rep(i, 0, N) cin >> A[i];
#define coutA(A, N) rep(i, 0, N) cout << A[i] << " ";
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
using ll = int64_t;
using ull = uint64_t;
using ld = long double;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using pl = pair<ll, ll>;
using tl = tuple<ll, ll, ll>;

int N, dp[1001];
string S[2];
void solve(){
    cin >> N;
    rep(i, 0, 2) cin >> S[i];
    fill(dp, dp + N, 0);
    dp[0] = 1;
    rep(i, 1, N){
        if(dp[i - 1] && (S[0][i] == '0' || S[1][i] == '0')) dp[i] = 1;
    }
    cout << (dp[N - 1] ? "YES" : "NO") << "\n";
}

int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    int TC;
    cin >> TC;
    while(TC--) solve();
}
