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

int T, N, L, R, dp[101][101];
vector<pi> A;
int calc(int L, int R){
    if(L == R) return 0;
    if(~dp[L][R]) return dp[L][R];
    set<int> S;
    rep(i, 0, N){
        if(A[i].x >= R) break;
        if(L <= A[i].x && A[i].y <= R){
            S.insert(calc(L, A[i].x) ^ calc(A[i].y, R));
        }
    }
    rep(i, 0, 12345678) if(S.count(i) == 0) return dp[L][R] = i;
    assert(0);
    return -1;
}
void solve(){
    A.clear();
    fill(dp[0], dp[101], -1);
    cin >> N;
    rep(i, 0, N){
        cin >> L >> R;
        A.eb(L, R);
    }
    sort(all(A));
    cout << (calc(1, 100) ? "Alice" : "Bob") << "\n";
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> T;
    while(T--) solve();
}
