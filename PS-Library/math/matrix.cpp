// simple matrix
using matrix = array<array<mi<ll>, 3>, 3>;
matrix operator * (matrix &a, matrix &b) {
    int n = a.size();
    matrix c;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            for (int k=0; k<n; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return c;
}
matrix& operator *= (matrix &a, matrix &b){
    return a = a * b;
}
matrix e(){return matrix{{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}};}
matrix poww (matrix& a, ll N){
    matrix ret = e();
    for(; N; N >>= 1){
        if(N & 1) ret *= a;
        a *= a;
    }
    return ret;
}
// memoized poww
matrix operator * (matrix &&a, matrix &b) {
    int n = a.size();
    matrix c;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            for (int k=0; k<n; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return c;
}
map<ll, matrix> save;
matrix poww (matrix& a, ll N){
    if(save.count(N)) return save[N];
    matrix ret = e();
    if(N == 0) return e();
    matrix&& tmp = poww(a, N / 2);
    return save[N] = (tmp * tmp) * (N % 2 ? a : I) ;
}

// ==========================================================================

// Matrix class
template<typename T, size_t n, size_t m>
class Matrix{
    public:
    using matrix = array<array<T, m>, n>;
    static constexpr Matrix<T, n, m> I(){
        auto I = Matrix<T, n, m>();
        rep(i, 0, n) I[i][i] = 1;
        return I;
    }
    matrix v;
    constexpr Matrix() {}
    constexpr Matrix(matrix v): v(v) {}
    Matrix<T, n, m> operator * (Matrix<T, n, m>& oth){
        // assume (n * m) * (n * m)
        assert(n == m);
        Matrix<T, n, m> ret;
        rep(i, 0, n) rep(j, 0, m) rep(k, 0, m) ret[i][k] += v[i][j] * oth[j][k];
        return ret;
    }
    Matrix<T, n, m> operator * (Matrix<T, n, m>&& oth){
        // assume (n * m) * (n * m)
        assert(n == m);
        Matrix<T, n, m> ret;
        rep(i, 0, n) rep(j, 0, m) rep(k, 0, m) ret[i][k] += v[i][j] * oth[j][k];
        return ret;
    }
    Matrix<T, n, m>& operator *= (Matrix<T, n, m>& oth){
        return *this = *this * oth;
    }
    array<T, m>& operator [] (int idx) {return v[idx];}
    Matrix<T, n, m> pow2(ll N){
        if(N == 0) return I();
        auto&& tmp = this->pow(N / 2);
        return tmp * tmp * (N % 2 ? *this : I());
    }
    Matrix<T, n, m> pow(ll N){
        Matrix<T, n, m> ret = I();
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
