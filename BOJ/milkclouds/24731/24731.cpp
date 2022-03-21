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

template<int M = 1000003>
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
ll K;
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> K;
    cout << MINT(2) * (pw(MINT(4), K - 1) - MINT(1)) * inv(MINT(3)) - (pw(MINT(2), K - 1) - MINT(1));
}
