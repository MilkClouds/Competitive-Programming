#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i,a,b) for(ll i = (a); i < (b); i++)
#define rep2(i,a,b) for(ll i = (b) - 1; i >= (a); i--)
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
using mint = atcoder::modint998244353;

const int MAX = 2001;
int N, A[MAX], M;
vector<mint> P = {1};
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N; cinA(A, N);
    atcoder::dsu DSU(N);
    rep(i, 0, N){
        if(~A[i]) M += DSU.same(i, A[i] - 1), DSU.merge(i, A[i] - 1);
    }
    rep(i, 0, N) if(A[i] == -1){
        // multiply N + B[i]x
        int sz = DSU.size(i);
        P.eb(0);
        rep2(i, 1, P.size()) P[i] = P[i] * N + P[i - 1] * sz; P[0] *= N;
    }
    mint k = 1, ans = M * P[0];
    cout << M << "\n";
    rep(i, 1, P.size()){
        ans += k * P[i];
        k *= i;
    }
    cout << ans.val() << "\n";
}
