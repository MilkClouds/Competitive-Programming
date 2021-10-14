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
using ti = tuple<int, int, int, int>;
using pl = pair<ll, ll>;
using tl = tuple<ll, ll, ll>;

// 40min
bool dp[41][41][41][81];
ti pre[41][41][41][81];

int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    int TC;
    cin >> TC;
    while(TC--){
        int N, A, B;
        string S;
        cin >> N >> A >> B >> S;
        string T = S;
        memset(dp, 0, sizeof(dp));
        memset(pre, 0, sizeof(pre));
        dp[0][(S[0] - '0') % A][0][40 + 1] = dp[0][0][(S[0] - '0') % B][40 - 1] = 1;
        pre[0][(S[0] - '0') % A][0][40 + 1] = ti(-1, -1, -1, 'R');
        pre[0][0][(S[0] - '0') % B][40 - 1] = ti(-1, -1, -1, 'B');
        rep(i, 1, N){
            rep(a, 0, A) rep(b, 0, B) rep2(kk, 0, N) for(auto k: {40 + kk, 40 - kk}) {
                if(dp[i - 1][a][b][k] == false) continue;
                dp[i][(a * 10 + S[i] - '0') % A][b][k + 1] = true;
                pre[i][(a * 10 + S[i] - '0') % A][b][k + 1] = ti(a, b, k, 'R');
                dp[i][a][(b * 10 + S[i] - '0') % B][k - 1] = true;
                pre[i][a][(b * 10 + S[i] - '0') % B][k - 1] = ti(a, b, k, 'B');
            }
        }
        rep(kk, 0, N){
            if(dp[N - 1][0][0][40 + kk]){
                int a = 0, b = 0, k = 40 + kk;
                int t = 0;
                rep2(i, 0, N){
                    tie(a, b, k, t) = pre[i][a][b][k];
                    T[i] = t;
                }
                break;
            } else if(dp[N - 1][0][0][40 - kk]){
                int a = 0, b = 0, k = 40 - kk;
                int t = 0;
                rep2(i, 0, N){
                    tie(a, b, k, t) = pre[i][a][b][k];
                    T[i] = t;
                }
                break;
            }
        }
        if(T[N - 1] <= '9') cout << "-1\n";
        else cout << T << "\n";
    }
}
