template<class T> struct mi {
	T val;
	mi() { val = 0; }
	mi(const ll& v) {
		val = (-MOD <= v && v <= MOD) ? v : v % MOD;
		if (val < 0) val += MOD;
	}
	mi operator + (const mi& m) {
		T tmp = (val + m.val) % MOD;
		return tmp + (tmp < 0 ? MOD : 0);
	}
	mi operator - (const mi& m) {
		T tmp = (val - m.val) % MOD;
		return tmp + (tmp < 0 ? MOD : 0);
	}
	mi operator * (const mi& m) {
		T tmp = (val * m.val) % MOD;
		return tmp;
	}
	mi& operator += (const mi& m) {
		if ((val += m.val) >= MOD) val -= MOD;
		return *this;
	}
	mi& operator -= (const mi& m) {
		if ((val -= m.val) < 0) val += MOD;
		return *this;
	}
	mi& operator *= (const mi& m) {
		val = (val * m.val) % MOD;
		return *this;
	}
    mi pow(ll N){
		mi<T> ret(1), a(val);
		for(; N; N >>= 1){
			if(N & 1) ret *= a;
			a *= a;
		}
		return ret;
	}
};
template<class T>
istream& operator >> (istream& is, mi<T>& m){return is >> m.val;}
template<class T>
ostream& operator << (ostream& os, mi<T> m){return os << m.val;}

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

ll fibonacci(ll N){
    auto M = Matrix<mi<ll>, 2, 2>({{1, 1}, {1, 0}});
    return M.pow(N)[0][1].val;
}