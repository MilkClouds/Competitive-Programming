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

int N, P, G[123], Q[4];

int solve(){
    cin >> N >> P;
    Q[0] = Q[1] = Q[2] = Q[3] = 0;
    rep(i, 0, N) cin >> G[i], Q[G[i] % P]++;
    if(P == 2){
        return Q[0] + (Q[1] + 1) / 2;
    }
    if(P == 3){
        int tmp = min(Q[1], Q[2]);
        Q[1] -= tmp; Q[2] -= tmp;
        return Q[0] + tmp + (2 + Q[1]) / 3 + (2 + Q[2]) / 3;
    }
    if(P == 4){
        int ans = Q[0] + Q[2] / 2;
        Q[2] %= 2;
        int tmp = min(Q[1], Q[3]);
        Q[1] -= tmp; Q[3] -= tmp;
        int tmp2 = min(Q[1] / 2, Q[2]);
        Q[1] -= tmp2 * 2; Q[2] -= tmp2;
        int tmp3 = min(Q[3] / 2, Q[2]);
        Q[3] -= tmp3 * 2; Q[2] -= tmp3;
        ans += tmp + tmp2 + tmp3;
        ans += Q[1] / 4 + Q[3] / 4; Q[1] %= 4; Q[3] %= 4;
        ans += Q[3] || Q[1] || Q[2];
        return ans;
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    int TC;
    cin >> TC;
    rep(tc, 0, TC){
        cout << "Case #" << tc + 1 << ": " << solve() << "\n";
    }
}