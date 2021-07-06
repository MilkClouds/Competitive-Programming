# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
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

int dp[31], N;
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N;
    rep(i, 1, N + 1){
        rep(j, 1, 31){
            set<int> S;
            rep(k, 1, i + 1){
                if(j - k < 0) continue;
                S.insert(dp[j - k]);
            }
            rep(k, 0, 1234) if(S.count(k) == 0) {dp[j] = k; break;}
        }
        //rep(j, 1, 32) cout << dp[j] << " ";
        if(dp[30] == 0) cout << i << "\n";
    }
}
