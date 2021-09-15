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

ll TC, N;
map<pair<ll, int>, bool> dp;
bool query(ll N, int C){
    if(N == 0) return 1;
    if(dp.find({N, C}) != dp.end()) return dp.find({N, C})->y;
    bool ret = 0;
    rep(a1, 0, 4) rep(a2, 0, 4) rep(a3, 0, 4) rep(a4, 0, 4) rep(a5, 0, 4) {
        int tmpi = a1 + a2 + a3 + a4 + a5;
        int tmpb = bool(a1) + bool(a2) + bool(a3) + bool(a4) + bool(a5);
        if(tmpi % 10 != N % 10) continue;
        if(N < tmpi) continue;
        if(tmpb > C) continue;
        ret |= query((N - tmpi) / 10, tmpb);
    }
    return dp[{N, C}] = ret;
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> TC;
    while(TC--){
        cin >> N;
        rep(i, 1, 20){
            if(query(N, i)){
                cout << i << "\n";
                break;
            }
            assert(i <= 5);
        }
    }
}
