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
#define x first
#define y second
using namespace std;
using ll = long long;
using tl = tuple<ll, ll, ll, ll>;
using pl = pair<ll, ll>;
using pi = pair<int, int>;
using ld = long double;

int TC, N, C, ans[101];

void solve(int N, int C, int S, int bias, bool rev){
    if(C <= (N - 1) * 2){
        C -= N - 1;
        rep(i, 0, C + 1) ans[(rev ? (N - 1 - i): i) + S] = bias + C - i;
        rep(i, C + 1, N) ans[(rev ? (N - 1 - i): i) + S] = bias + i;
    } else {
        ans[(rev ? 0 : N - 1) + S] = bias;
        if(rev) S++;
        solve(N - 1, C - N, S, bias + 1, rev ^ 1);
    }
}

int main() {
    //cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> TC;
    rep(tc, 0, TC){
        cin >> N >> C;
        if(C > N * (N + 1) / 2 - 1 || C < N - 1) {printf("Case #%d: IMPOSSIBLE\n", tc + 1); continue;}
        solve(N, C, 0, 1, 0);
        printf("Case #%d: ", tc + 1);
        rep(i, 0, N) cout << ans[i] << " " ;
        cout << "\n";
    }
}
