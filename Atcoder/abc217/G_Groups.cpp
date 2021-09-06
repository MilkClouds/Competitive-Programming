#include <bits/stdc++.h>
#include <atcoder/convolution>
#include <atcoder/modint>
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
using mint=atcoder::modint998244353;
using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using pl = pair<ll, ll>;
using tl = tuple<ll, ll, ll>;

const int MAX = 5555, MOD = 998244353;
int N, M;
mint rev[MAX], fac[MAX];
mint perm(ll a, ll b){
    if(a < b) return 0;
    return fac[a] * rev[a - b];
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N >> M;
    vector<mint> g(N + 1), B(N + 1);
    fac[0] = 1;
    rep(i, 1, MAX){
        fac[i] = fac[i - 1] * i;
    }
    rev[MAX - 1] = fac[MAX - 1].pow(MOD - 2);
    rep2(i, 1, MAX) rev[i - 1] = rev[i] * i;
    rep(k, (N + M - 1) / M, N + 1) {
        g[k] = perm(k, N / M).pow(M - N % M) * perm(k, N / M + 1).pow(N % M) * rev[k];
    }
    rep(i, 0, N + 1) B[i] = i % 2 ? MOD - rev[i] : rev[i];
    auto&& ans = atcoder::convolution(g, B);
    rep(i, 1, N + 1){
        cout << ans[i].val() << "\n";
    }
}
