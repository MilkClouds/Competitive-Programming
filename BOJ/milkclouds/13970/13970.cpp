#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define x first
#define y second
using namespace std;
using ll = long long;
using pl = pair<ll, bool>;

const int MAX = 1010101;
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

ll T, N, M, A[MAX], B[MAX], i;
pl f(ll i){
    if(i == N) return {1, 0};
    pl tmp = f(i + 1);
    ll a = pw(A[i], tmp.x + tmp.y * B[i + 1], B[i]);
    ll b = pw(A[i], tmp.x + tmp.y * B[i + 1], 1e9 + 7);
    ll c = pw(A[i], tmp.x + tmp.y * B[i + 1], 998244353);
    return {a, (a != b) || (a != c)};
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> T >> M;
    sieve();
    for(i = 0; M > 1; i++, M = get_phi(M)) B[i] = M; fill(B + i, B + MAX, 1);
    while(T--){
        cin >> N;
        rep(i, 0, N) cin >> A[i];
        cout << f(0).x << "\n";
    }
}
