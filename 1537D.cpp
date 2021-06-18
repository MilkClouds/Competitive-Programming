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

/*
dp[1] = dp[2] = ... dp[prime number] = 0 // lose
dp[4] = 1
dp[6] = mex(dp[4], dp[3]) = 2

*/
const ll MAX = 1e5;
ll TC, N;
map<ll, ll> dp;
ll solve(ll N){
    if(dp.find(N) != dp.end()) return dp[N];
    set<ll> S;
    for(ll i = 2; i < N; i++){
        if(N % i) continue;
        S.insert(solve(N - i));
    }
    rep(i, 0, 12345678){
        if(S.count(i) == 0) return dp[N] = i;
    }
    return -1;
}
ll mylog2(ll x){
    ll cnt = 0;
    while(x > 1){
        cnt++; x >>= 1;
    }
    return cnt;
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> TC;
    // dp[1] = dp[2] = dp[3] = 0;
    // rep(i, 1, 18) {
    //     cout << i << ": "<< solve(i) << endl;
    //     if(((i % 2) ^ (solve(i) == 0))) cout << i << endl;
    // }
    while(TC--){
        cin >> N;
        if(popcountll(N) == 1 && (mylog2(N) % 2)){
            cout << "Bob\n";
        }
        else cout << (N % 2 ? "Bob" : "Alice") << "\n";
    }
}
