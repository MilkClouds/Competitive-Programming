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

const ll INF = 1e16;
ll T, N, ans = 1, tc;
ll f(ll M, ll k){
    if(M == 0) return 0;
    ll ans = 0;
    rep(i, 2, M + 1){
        if(M < k * i) break;
        if(M % (k * i)) continue;
        ans = max(ans, f(M - k * i, k * i) + 1);
    }
    return ans;
}
int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> T;
    rep(tc, 1, T + 1) {
        cin >> N;
        ans = 0;
        rep(i, 3, N + 1){
            if(N % i) continue;
            ans = max(ans, f(N - i, i) + 1);
        }
        printf("Case #%d: %lld\n", tc, ans);
    }
}
