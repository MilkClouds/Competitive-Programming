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

const ll MAX = 1010101, MOD = 1e9 + 7;
vector<int> pn;
ll sp[MAX];
ll pw(ll a, ll b){
    ll ret = 1;
    for(; b; b >>= 1, a = (a * a) % MOD) if(b & 1) ret = ret * a % MOD;
    return ret;
}
// https://ahgus89.github.io/algorithm/Linear-sieve/
// https://ahgus89.github.io/algorithm/Notation/
void sieve(){
    for(int i = 2; i < MAX; i++){
        if(!sp[i]){
            pn.push_back(i);
            sp[i] = i;
        }
        for(auto j: pn){
            if(i * j >= MAX) break; //!ll
            // j: i*j의 최소인수(because j<(i의 최소인수))
            sp[i * j] = j;
            if(i % j == 0)break; // j==(i의 최소인수)이면 break
        }
    }
}
ll f(ll k){
    ll ret = 1;
    for(ll p = 0; k > 1; p = sp[k], k /= sp[k]) if(p != sp[k]) ret *= 1 - sp[k];
    return ret;
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    ll N, ret = 0;
    sieve();
    cin >> N;
    rep(k, 1, N + 1){
        ll tmp = N / k;
        ll tmp2 = (tmp * (tmp + 1) >> 1) % MOD;
        ret += tmp2 * tmp2 % MOD * k * f(k) % MOD;
        ret %= MOD;
    }
    ret -= N * (N + 1) >> 1;
    ret %= MOD;
    if(ret < 0) ret += MOD;
    ret = (ret * pw(2, MOD - 2)) % MOD;
    cout << ret << endl;
}
