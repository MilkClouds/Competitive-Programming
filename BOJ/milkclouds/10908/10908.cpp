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

template<ll M = MOD>
struct MINT{
    ll v;
    MINT() : v(0) {}
    MINT(ll val){
        v = (-M <= val && val < M) ? val : val % M;
        if(v < 0) v += M;
    }
    friend istream& operator >> (istream &is, MINT &a) { ll t; is >> t; a = MINT(t); return is; }
    friend ostream& operator << (ostream &os, const MINT &a) { return os << a.v; }
    friend bool operator == (const MINT &a, const MINT &b) { return a.v == b.v; }
    friend bool operator != (const MINT &a, const MINT &b) { return a.v != b.v; }
    friend MINT pw(MINT a, __int128 b){
        MINT ret = 1;
        for(; b; b >>= 1, a *= a) if(b & 1) ret *= a;
        return ret;
    }
	MINT pow(ll b) { return pw(MINT(*this), b); }
    friend MINT inv(const MINT a) { return M == MOD ? pw(a, M-2) : pw(a, (__int128) M * M - M - 1); }
    MINT operator - () const { return MINT(-v); }
    MINT& operator += (const MINT m) { if((v += m.v) >= M) v -= M; return *this; }
    MINT& operator -= (const MINT m) { if((v -= m.v) < 0) v += M; return *this; }
    MINT& operator *= (const MINT m) { v = (__int128)v*m.v%M; return *this; }
    MINT& operator /= (const MINT m) { *this *= inv(m); return *this; }
    friend MINT operator + (MINT a, MINT b) { a += b; return a; }
    friend MINT operator - (MINT a, MINT b) { a -= b; return a; }
    friend MINT operator * (MINT a, MINT b) { a *= b; return a; }
    friend MINT operator / (MINT a, MINT b) { a /= b; return a; }
    operator int64_t() const { return v; }
};
using mint = MINT<MOD>;
using mintpp = MINT<MOD * MOD>;
// Matrix class
template<typename T, size_t n, size_t m>
class Matrix{
    public:
    vector<vector<T>> v;
    constexpr Matrix(bool I = 0): v(n, vector<T>(m)) {
        if(I){
            rep(i, 0, n) v[i][i] = 1;
        }
    }
    constexpr Matrix(vector<vector<T>> v): v(v) {}
    Matrix<T, n, m> operator * (Matrix<T, n, m>& oth){
        // assume (n * m) * (n * m)
        assert(n == m);
        Matrix<T, n, m> ret;
        rep(i, 0, n) rep(j, 0, m) rep(k, 0, m) ret[i][k] += v[i][j] * oth[j][k];
        return ret;
    }
    Matrix<T, n, m>& operator *= (Matrix<T, n, m>& oth){
        return *this = *this * oth;
    }
    vector<T>& operator [] (int idx) {return v[idx];}
    Matrix<T, n, m> pow(__int128 N){
        Matrix<T, n, m> ret = Matrix<T, n, m>(1);
        Matrix<T, n, m> A(v);
        for(; N; N >>= 1){
            if(N & 1) ret *= A;
            A *= A;
        }
        return ret;
    }
};
template<typename T, size_t n, size_t m>
ostream& operator << (ostream& os, Matrix<T, n, m> M){
    rep(i, 0, n) {
        rep(j, 0, m) os << M[i][j] << " ";
        cout << "\n";
    }
    return os;
}

mintpp fibonacci(__int128 N){
    if(N == -1) return 1;
    auto M = Matrix<mintpp, 2, 2>({{1, 1}, {1, 0}});
    return M.pow(N)[0][1];
}
mint divide(mintpp a, mintpp b){
    if(b.v % MOD == 0) a.v /= MOD, b.v /= MOD;
    assert(mint(b) != mint(0));
    return mint(a) / mint(b);
}

int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    ll _n, _k;
    cin >> _n >> _k;
    __int128 n = _n, k = _k;
    mint A = divide(fibonacci(n * k), fibonacci(k));
    mint B = mint(fibonacci(n * k - 1)) - A * mint(fibonacci(k - 1));
    cout << A << " " << B << endl;
}
