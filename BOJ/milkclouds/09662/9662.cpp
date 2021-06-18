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

const int MAX = 1e6;
int M, K, A[22], dp[MAX * 2 + 1], B[MAX * 2 + 1], C[MAX * 2 + 1], cyc;
ll ans;
int solve(int n){
    if(~dp[n]) return dp[n];
    vector<int> v(K + 1, 0);
    rep(i, 0, K){
        if(n - A[i] < 0) continue;
        v[solve(n - A[i])]++;
    }
    rep(i, 0, K + 1) if(v[i] == 0) return dp[n] = i;
    assert(0);
    return -1;
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> M >> K;
    fill(dp, dp + 2 * MAX, -1);
    dp[0] = 0;
    rep(i, 0, K) cin >> A[i];
    rep(i, 0, 2 * MAX + 1) B[i] = solve(i);
    rep(i, 0, 2 * MAX) C[i + 1] = C[i] + (B[i + 1] == 0);
    if(M <= MAX){
        cout << C[M] << endl;
        return 0;
    }
    rep2(c, 1, 2000 + 1){
        bool flag = 0;
        rep(i, MAX, MAX + c){
            if(B[i] != B[i + c]){
                flag = 1;
                break;
            }
        }
        if(!flag){
            cyc = c;
            break;
        }
    }
    ll tmp = C[MAX + cyc] - C[MAX];
    ans = C[MAX];
    ans += ((M - MAX) / cyc) * tmp;
    ll tmp2 = M - ((M - MAX) / cyc) * cyc;
    ans += C[tmp2] - C[MAX];
    cout << ans;
}
