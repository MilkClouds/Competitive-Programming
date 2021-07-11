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

int TC, A[3][3];
ll count(){
    ll cnt = 0;
    rep(i, 0, 3) {
        if(A[i][0] + A[i][2] == A[i][1] * 2) cnt++;
        if(A[0][i] + A[2][i] == A[1][i] * 2) cnt++;
    }
    if(A[0][0] + A[2][2] == A[1][1] * 2) cnt++;
    if(A[2][0] + A[0][2] == A[1][1] * 2) cnt++;
    return cnt;
}
ll solve(){
    ll ans = 0;
    rep(i, 0, 3) rep(j, 0, 3) {
        if(i == 1 && j == 1) continue;
        cin >> A[i][j];
    }
    A[1][1] = (A[1][0] + A[1][2]) / 2;
    ans = max(ans, count());
    A[1][1] = (A[0][1] + A[2][1]) / 2;
    ans = max(ans, count());
    A[1][1] = (A[0][0] + A[2][2]) / 2;
    ans = max(ans, count());
    A[1][1] = (A[2][0] + A[0][2]) / 2;
    ans = max(ans, count());
    return ans;
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> TC;
    rep(tc, 0, TC){
        cout << "Case #" << tc + 1 << ": " << solve() << "\n";
    }
}
