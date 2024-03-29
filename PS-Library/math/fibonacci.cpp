template<int M = 998244353>
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
using mint = MINT<>;

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
    Matrix<T, n, m> pow(ll N){
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

mint fibonacci(ll N){
    auto M = Matrix<mint, 2, 2>({{1, 1}, {1, 0}});
    return M.pow(N)[0][1];
}