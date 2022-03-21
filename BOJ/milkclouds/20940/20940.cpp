#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i = (a); i < (b); i++)
using namespace std;
using ll = long long;
const int MAX = 1010101;
ll N, M;
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
    MINT& operator += (const MINT m) { v += m.v; v %= M; return *this; }
    MINT& operator -= (const MINT m) { v -= m.v; v %= M; if(v < 0) v += M; return *this; }
    MINT& operator *= (const MINT m) { v = (ll)v*m.v%M; return *this; }
    MINT& operator /= (const MINT m) { *this *= inv(m); return *this; }
    friend MINT operator + (MINT a, MINT b) { a += b; return a; }
    friend MINT operator - (MINT a, MINT b) { a -= b; return a; }
    friend MINT operator * (MINT a, MINT b) { a *= b; return a; }
    friend MINT operator / (MINT a, MINT b) { a /= b; return a; }
    operator int32_t() const { return v; }
    operator int64_t() const { return v; }
};

MINT A[MAX], B[MAX], ls, rs;
vector<int> pn;
ll sp[MAX], phi[MAX];
void sieve(){
    phi[1] = 1;
    for(int i = 2; i < MAX; i++){
        if(!sp[i]){
            pn.push_back(i);
            sp[i] = i;
            phi[i] = i - 1;
        }
        for(auto j: pn){
            if(i * j >= MAX) break; //!ll
            // j: i*j의 최소인수(because j<(i의 최소인수))
            sp[i * j] = j;
            if(i % j == 0){
                phi[i * j] = phi[i] * j;
                break; // j==(i의 최소인수)이면 break
            }
            // gcd(i, j) == 1
            phi[i * j] = phi[i] * phi[j];
        }
    }
}
ll f(ll k){
    ll ret = k;
    for(ll p = 0; k > 1; p = sp[k], k /= sp[k]) if(p != sp[k]) ret *= 1 - sp[k];
    return ret;
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N >> M;
    sieve();
    MINT iv = inv(MINT(2));
    rep(i, 2, sqrt(M) + 1) assert(M % i);
    rep(k, 1, N + 1) A[k] = A[k - 1] + MINT(k * k), B[k] = B[k - 1] + pw(MINT(k * (k + 1)) * iv, 2);
    rep(e, 1, N + 1){
        ls += MINT(phi[e]) * (MINT(e) * A[N / e - 1] + MINT(1 + N % e) * (A[N / e] - A[N / e - 1]));
        rs += MINT(f(e)) * (MINT(e) * B[N / e - 1] + MINT(1 + N % e) * (B[N / e] - B[N / e - 1]));
    }
    cout << B[N] << "\n" << ls * rs << endl;
}
