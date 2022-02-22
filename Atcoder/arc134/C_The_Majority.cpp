#include <bits/stdc++.h>
#include <atcoder/modint>
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
using mi = atcoder::modint998244353;

const int MAX = 1e5, MAXK = 205;
ll N, K, A[MAX];
mi ans = 1;
mi fact[MAXK] = {1}, inv[MAXK];
mi aHb(ll a, ll b){
    if(b < 0) return 0;
    mi ans = 1;
    rep(i, b + 1, a + b){
        ans *= i;
    }
    ans *= inv[a - 1];
    return ans;
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N >> K;
    rep(i, 1, MAXK){
        fact[i] = fact[i - 1] * i;
    }
    inv[MAXK - 1] = fact[MAXK - 1].inv();
    rep2(i, 1, MAXK){
        inv[i - 1] = inv[i] * i;
    }
    cinA(A, N);
    rep(i, 1, N){
        ans *= aHb(K, A[i]);
    }
    ans *= aHb(K, A[0] - K - accumulate(A + 1, A + N, 0LL));
    cout << ans.val() << endl;
}
