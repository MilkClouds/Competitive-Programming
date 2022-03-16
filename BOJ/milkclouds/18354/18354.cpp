#include <bits/stdc++.h>
#include <atcoder/convolution>
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define rep2(i,a,b) for(int i = (b) - 1; i >= (a); i--)
#define cinA(A, N) rep(i, 0, N) cin >> A[i];
#define coutA(A, N) rep(i, 0, N) cout << A[i] << " ";
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define eb emplace_back
#define popcount __builtin_popcount
#define popcountll __builtin_popcountll
#define x first
#define y second
using namespace std;
using ll = long long;
using ull = uint64_t;
using ld = long double;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using pl = pair<ll, ll>;
using tl = tuple<ll, ll, ll>;

const int MOD = 1030307;
ll N, K, dp[MOD];
vector<ll> A(MOD - 1), B, ans(MOD - 1);
constexpr ll pw(ll a, ll b, ll M){
    ll ret = 1;
    for(; b; b >>= 1, a = (a * a) % M) if(b & 1) ret = (a * ret) % M;
    return ret;
}
// need to calculate w^(1/2)
// void bluestein(vector<ll>& f, ll w){
//     int N = f.size();
//     ll iw = pw(w, MOD - 2, MOD);
//     vector<ll> a(N), b(N * 2);
//     for(ll i = 0; i < N; i++){
//         a[i] = f[i] * pw(w, i * i, MOD) % MOD;
//         b[i + N] = b[N - i] = pw(iw, i * i, MOD);
//     }
//     auto&& ret = conv(a, b);
//     for(ll i = 0; i < N; i++){
//         f[i] = pw(w, i * i / 2, MOD) * ret[i + N] % MOD;
//     }
// }
ll safe_mod(ll a, ll b = MOD - 1){
    a %= b;
    if(a < 0) a += b;
    return a;
}
// reference: https://codeforces.com/blog/entry/83532, https://cp-algorithms.com/algebra/polynomial.html#chirp-z-transform
void chirp_z(vector<ll>& f, ll w){
    int N = f.size();
    vector<ll> a(N * 2), b(N);
    for(ll i = 0; i < 2 * N; i++) a[i] = dp[safe_mod(i * (i - 1) / 2)];
    for(ll i = 0; i < N; i++){
        b[N - 1 - i] = f[i] * dp[safe_mod(-i * (i - 1) / 2)] % MOD;
    }
    auto&& ret = atcoder::convolution_ll(a, b);
    for(ll i = 0; i < N; i++){
        f[i] = dp[safe_mod(-i * (i - 1) / 2)] * (ret[N - 1 + i] % MOD) % MOD;
    }
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    for(ll i = 0, t = 1; i < MOD - 1; i++, t = (t * 2) % MOD) dp[i] = t;
    cin >> N;
    cinA(A, N + 1);
    cin >> K;
    B.resize(K);
    cinA(B, K);
    ans[0] = A[0];
    chirp_z(A, 2);
    for(ll i = 0, t = 1; i < MOD - 1; i++, t = (t * 2) % MOD) ans[t] = A[i];
    for(auto i: B){
        cout << ans[i] << "\n";
    }
}
