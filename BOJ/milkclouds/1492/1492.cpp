#include <bits/stdc++.h>
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

const ll MOD = 1e9 + 7;
ll N, K, ans;
ll mpow(ll a, ll b){
    if(b == 0) return 1;
    return (b % 2 ? a : 1) * mpow(a * a % MOD, b / 2) % MOD;
}
vector<ll> v;
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N >> K;
    v.eb(0);
    rep(n, 1, K + 2){
        v.eb((v.back() + mpow(n, K)) % MOD);
    }
    rep(i, 0, K + 2){
        ll tmp = v[i];
        rep(j, 0, K + 2){
            if(i == j) continue;
            tmp = (tmp * (N - j) % MOD) * mpow(i - j, MOD - 2) % MOD;
        }
        ans = (ans + tmp) % MOD;
    }
    if(ans < 0) ans += MOD;
    cout << ans << endl;
}
