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

// 3 * 2 ^ 18 + 1
const int MOD = 786433, MAX = 1 << 20;
ll N, K;
vector<ll> A(MOD - 1), B, ans(MOD - 1);
void query(vector<ll>& f, ll k){
    int n = f.size();
    if(n == 3) {
        vector<ll> v(3);
        ll nk = k * k % MOD;
        v[0] = (f[0] + f[1] + f[2]) % MOD;
        v[1] = (f[0] + f[1] * k + f[2] * nk) % MOD;
        v[2] = (f[0] + f[1] * nk + f[2] * nk * nk) % MOD;
        f[0] = v[0];
        f[1] = v[1];
        f[2] = v[2];
        return;
    }
    vector<ll> odd(n / 2), even(n / 2);
    for(int i = 0; i < n; i++)
        (i % 2 ? odd : even)[i / 2] = f[i];
    ll nk = k * k % MOD;
    query(odd, nk);
    query(even, nk);
    ll p = 1;
    for(int i = 0; i < n / 2; i++){
        f[i] = (even[i] + p * odd[i]) % MOD;
        f[i + n / 2] = (even[i] - p * odd[i]) % MOD;
        if(f[i + n / 2] < 0) f[i + n / 2] += MOD;
        p = (p * k) % MOD;
    }
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N;
    cinA(A, N + 1);
    cin >> K;
    B.resize(K);
    cinA(B, K);
    ans[0] = A[0];
    query(A, 10);
    ll t = 1;
    rep(i, 0, MOD - 1){
        ans[t] = A[i];
        t = (t * 10) % MOD;
    }
    for(auto i: B){
        cout << ans[i] << "\n";
    }
}
