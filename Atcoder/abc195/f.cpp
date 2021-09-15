# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i = (a); i < (b); i++)
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

ll A, B, ans = 0, dp[74][1048576];
vector<int> pn;
ll gcd(ll a, ll b){
    if(a % b == 0) return b;
    return gcd(b, a % b);
}
bool isp_(int a){
    rep(i, 2, a) if(a % i == 0) return 0;
    return 1;
}
map<ll, int> M;
int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> A >> B;
    rep(i, 2, B - A + 1) if(isp_(i)) pn.pb(i);
    rep(i, A, B + 1){
        rep(j, 0, pn.size()){
            if(i % pn[j] == 0){
                M[i] |= 1 << j;
            }
        }
    }
    dp[0][0] = 1;
    rep(i, A, B + 1) {
        rep(j, 0, 1 << pn.size()){
            dp[i + 1 - A][j] += dp[i - A][j];
            if(M[i] & j) continue;
            dp[i + 1 - A][j | M[i]] += dp[i - A][j];
        }
    }
    rep(i, 0, 1 << pn.size()) ans += dp[B - A + 1][i];
    cout << ans;
}
