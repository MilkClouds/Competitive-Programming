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

const int MAX=101010;
vector<int> pn;
ll sp[MAX], e[MAX], phi[MAX];
ll pw(ll a, ll b, ll MOD){
    ll ret = 1;
    for(; b; b >>= 1, a = a * a % MOD) if(b & 1) ret = ret * a % MOD;
    return ret;
}
// https://ahgus89.github.io/algorithm/Linear-sieve/
// https://ahgus89.github.io/algorithm/Notation/
void sieve(){
    phi[1] = 1;
    for(int i = 2; i < MAX; i++){
        if(!sp[i]){
            pn.push_back(i);
            sp[i] = i;
            e[i] = 1;
            phi[i] = i - 1;
        }
        for(auto j: pn){
            if(i * j >= MAX) break; //!ll
            // j: i*j의 최소인수(because j<(i의 최소인수))
            sp[i * j] = j;
            if(i % j == 0){
                e[i * j] = e[i] + 1;
                phi[i * j] = phi[i] * j;
                break; // j==(i의 최소인수)이면 break
            }
            // gcd(i, j) == 1
            e[i * j] = 1;
            phi[i * j] = phi[i] * phi[j];
        }
    }
}
ll get_phi(ll N){
    if(N < MAX) return phi[N];
    ll ret = 1;
    for(auto i: pn){
        if(N % i) continue;
        ll t = 1;
        for(; N % i == 0; N /= i, t *= i);
        ret *= t - t / i;
    }
    if(N > 1) ret *= N - 1;
    return ret;
}
ll g(ll N, ll M){
    if(N == 1) return 1 % M;
    if(N == 2) return 2 % M;
    if(N == 3) return 9 % M;
    if(N == 4) return (1 << 18) % M;
    return pw(5, 1 << 18, M);
}
ll f(ll N, ll M){
    if(N <= 5) return g(N, M);
    if(M == 1) return 0;
    ll p = get_phi(M);
    return pw(N, f(N - 1, p) + p, M);
}
ll TC, N, M;
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    sieve();
    cin >> N >> M;
    cout << f(N, M) << "\n";
}