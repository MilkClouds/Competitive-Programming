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

const int MAX = 1e7 + 1;
vector<int> pn;
int sp[MAX], mu[MAX];
ll pw(ll a, ll b){
    ll ret = 1;
    for(; b; b >>= 1, a *= a) if(b & 1) ret *= a;
    return ret;
}
// https://ahgus89.github.io/algorithm/Linear-sieve/
// https://ahgus89.github.io/algorithm/Notation/
// code below is not tested.
void sieve(){
    mu[1] = 1;
    for(int i = 2; i < MAX; i++){
        if(!sp[i]){
            pn.push_back(i);
            mu[i] = -1;
        }
        for(auto j: pn){
            if(i * j >= MAX) break; //!ll
            // j: i*j의 최소인수(because j<(i의 최소인수))
            sp[i * j] = j;
            if(i % j == 0){
                mu[i * j] = 0;
                break; // j==(i의 최소인수)이면 break
            }
            // gcd(i, j) == 1
            mu[i * j] = mu[i] * mu[j];
        }
    }
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    ll a, b, c, d, ret = 0;
    sieve();
    cin >> a >> b >> c >> d; a--; c--;
    rep(k, 1, min(b, d) + 1){
        ret += mu[k] * (b / k - a / k) * (d / k - c / k);
    }
    cout << ret << '\n';
}
