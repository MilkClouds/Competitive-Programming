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

int N, dp[1001];
int solve(int i){
    if(~dp[i]) return dp[i];
    set<int> v;
    rep(j, 0, i / 2){
        v.insert(solve(j) ^ solve(i - j - 2));
    }
    rep(k, 0, 123456){
        if(v.count(k) == 0) return dp[i] = k;
    }
    return -1;
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N;
    fill(dp, dp + N + 1, -1);
    dp[0] = dp[1] = 0;
    cout << (solve(N) ? 1 : 2);
}
