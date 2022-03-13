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

const int MAXK = 5;
ll TC, K, A[MAXK], B[MAXK], LIM;

const int MAX = 201010, INF = 2e9;
vector<int> pn;
int sp[MAX], e[MAX], phi[MAX], mu[MAX], tau[MAX], sigma[MAX];
ll pw(ll a, ll b){
    ll ret = 1;
    for(; b; b >>= 1, a *= a) if(b & 1) ret *= a;
    return ret;
}
template<int M = 1000000007>
struct MINT{
    int v;
    MINT() : v(0) {}
    MINT(ll val){
        v = (-M <= val && val < M) ? val : val % M;
        if(v < 0) v += M;
    }
    friend istream& operator >> (istream &is, MINT &a) { ll t; is >> t; a = MINT(t); return is; }
    friend ostream& operator << (ostream &os, const MINT &a) { return os << a.v; }
    friend bool operator == (const MINT &a, const MINT &b) { return a.v == b.v; }
    friend bool operator != (const MINT &a, const MINT &b) { return a.v != b.v; }
    friend MINT pw(MINT a, ll b){
        MINT ret = 1;
        for(; b; b >>= 1, a *= a) if(b & 1) ret *= a;
        return ret;
    }
	MINT pow(ll b) { return pw(MINT(*this), b); }
    friend MINT inv(const MINT a) { return pw(a, M-2); }
    MINT operator - () const { return MINT(-v); }
    MINT& operator += (const MINT m) { if((v += m.v) >= M) v -= M; return *this; }
    MINT& operator -= (const MINT m) { if((v -= m.v) < 0) v += M; return *this; }
    MINT& operator *= (const MINT m) { v = (ll)v*m.v%M; return *this; }
    MINT& operator /= (const MINT m) { *this *= inv(m); return *this; }
    friend MINT operator + (MINT a, MINT b) { a += b; return a; }
    friend MINT operator - (MINT a, MINT b) { a -= b; return a; }
    friend MINT operator * (MINT a, MINT b) { a *= b; return a; }
    friend MINT operator / (MINT a, MINT b) { a /= b; return a; }
    operator int32_t() const { return v; }
    operator int64_t() const { return v; }
};
// https://ahgus89.github.io/algorithm/Linear-sieve/
// https://ahgus89.github.io/algorithm/Notation/
// code below is not tested.
void sieve(){
    phi[1] = 1;
    mu[1] = 1;
    tau[1] = 1;
    sigma[1] = 1;
    for(int i = 2; i < MAX; i++){
        if(!sp[i]){
            pn.push_back(i);
            e[i] = 1;
            phi[i] = i - 1;
            mu[i] = -1;
            tau[i] = 2;
            sigma[i] = i + 1;
        }
        for(auto j: pn){
            if(i * j >= MAX) break; //!ll
            // j: i*j의 최소인수(because j<(i의 최소인수))
            sp[i * j] = j;
            if(i % j == 0){
                e[i * j] = e[i] + 1;
                phi[i * j] = phi[i] * j;
                mu[i * j] = 0;
                tau[i * j] = tau[i] / e[i * j] * (e[i * j] + 1);
                sigma[i * j] = sigma[i] * (j - 1) / (pw(j, e[i * j]) - 1) * (pw(j, e[i * j] + 1) - 1) / (j - 1);
                break; // j==(i의 최소인수)이면 break
            }
            // gcd(i, j) == 1
            e[i * j] = 1;
            phi[i * j] = phi[i] * phi[j];
            mu[i * j] = mu[i] * mu[j];
            tau[i * j] = tau[i] * tau[j];
            sigma[i * j] = sigma[i] * sigma[j];
        }
    }
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> TC;
    sieve();
    while(TC--){
        cin >> K;
        LIM = INF;
        rep(i, 0, K) cin >> A[i] >> B[i], LIM = min(LIM, B[i]);
        MINT ret = 0;
        rep(k, 1, LIM + 1){
            MINT tmp = 1;
            rep(j, 0, K) tmp *= B[j] / k - (A[j] - 1) / k;
            tmp *= phi[k];
            ret += tmp;
        }
        if(ret == MINT(0)){
            cout << "-1\n";
            continue;
        }
        rep(j, 0, K) ret /= B[j] - A[j] + 1;
        cout << -ret << "\n";
    }
}
