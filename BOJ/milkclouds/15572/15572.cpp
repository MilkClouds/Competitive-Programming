#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define IDX(v, x) (lower_bound(all(v), x) - v.begin())
using namespace std;

using uint = unsigned;
using ll = long long;
using ull = unsigned long long;

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

namespace fft{
    template<int W, int M>
    static void NTT(vector<MINT<M>> &f, bool inv_fft = false){
        using T = MINT<M>;
        int N = f.size();
        vector<T> root(N >> 1);
        for(int i=1, j=0; i<N; i++){
            int bit = N >> 1;
            while(j >= bit) j -= bit, bit >>= 1;
            j += bit;
            if(i < j) swap(f[i], f[j]);
        }
        T ang = pw(T(W), (M-1)/N); if(inv_fft) ang = inv(ang);
        root[0] = 1; for(int i=1; i<N>>1; i++) root[i] = root[i-1] * ang;
        for(int i=2; i<=N; i<<=1){
            int step = N / i;
            for(int j=0; j<N; j+=i){
                for(int k=0; k<i/2; k++){
                    T u = f[j+k], v = f[j+k+(i>>1)] * root[k*step];
                    f[j+k] = u + v;
                    f[j+k+(i>>1)] = u - v;
                }
            }
        }
        if(inv_fft){
            T rev = inv(T(N));
            for(int i=0; i<N; i++) f[i] *= rev;
        }
    }
    template<int W, int M>
    vector<MINT<M>> multiply_ntt(vector<MINT<M>> a, vector<MINT<M>> b){
        vector<MINT<M>> c(a.size() + b.size());
        rep(i, 0, a.size()) rep(j, 0, b.size()) c[i + j] += a[i] * b[j];
        return c;
    }
}

template<int W, int M>
struct PolyMod{
    using T = MINT<M>;
    vector<T> a;

    // constructor
    PolyMod(){}
    PolyMod(T a0) : a(1, a0) { normalize(); }
    PolyMod(const vector<T> a) : a(a) { normalize(); }

    // method from vector<T>
    int size() const { return a.size(); }
    int deg() const { return a.size() - 1; }
    void normalize(){ while(a.size() && a.back() == T(0)) a.pop_back(); }
    T operator [] (int idx) const { return a[idx]; }
    typename vector<T>::const_iterator begin() const { return a.begin(); }
    typename vector<T>::const_iterator end() const { return a.end(); }
    void push_back(const T val) { a.push_back(val); }
    void pop_back() { a.pop_back(); }

    // basic manipulation
    PolyMod reversed() const {
        vector<T> b = a;
        reverse(b.begin(), b.end());
        return b;
    }
    PolyMod trim(int n) const {
        return vector<T>(a.begin(), a.begin() + min(n, size()));
    }
    PolyMod inv(int n){
        PolyMod q(T(1) / a[0]);
        for(int i=1; i<n; i<<=1){
            PolyMod p = PolyMod(2) - q * trim(i * 2);
            q = (p * q).trim(i * 2);
        }
        return q.trim(n);
    }

    // operation with scala value
    PolyMod operator *= (const T x){
        for(auto &i : a) i *= x;
        normalize();
        return *this;
    }
    PolyMod operator /= (const T x){
        return *this *= (T(1) / T(x));
    }

    // operation with poly
    PolyMod operator += (const PolyMod &b){
        a.resize(max(size(), b.size()));
        for(int i=0; i<b.size(); i++) a[i] += b.a[i];
        normalize();
        return *this;
    }
    PolyMod operator -= (const PolyMod &b){
        a.resize(max(size(), b.size()));
        for(int i=0; i<b.size(); i++) a[i] -= b.a[i];
        normalize();
        return *this;
    }
    PolyMod operator *= (const PolyMod &b){
        *this = fft::multiply_ntt<W, M>(a, b.a);
        normalize();
        return *this;
    }
    PolyMod operator /= (const PolyMod &b){
        if(deg() < b.deg()) return *this = PolyMod();
        int sz = deg() - b.deg() + 1;
        PolyMod ra = reversed().trim(sz), rb = b.reversed().trim(sz).inv(sz);
        *this = (ra * rb).trim(sz);
        for(int i=sz-size(); i; i--) push_back(T(0));
        reverse(all(a));
        normalize();
        return *this;
    }
    PolyMod operator %= (const PolyMod &b){
        if(deg() < b.deg()) return *this;
        PolyMod tmp = *this; tmp /= b; tmp *= b;
        *this -= tmp;
        normalize();
        return *this;
    }

    // operator
    PolyMod operator * (const T x) const { return PolyMod(*this) *= x; }
    PolyMod operator / (const T x) const { return PolyMod(*this) /= x; }
    PolyMod operator + (const PolyMod &b) const { return PolyMod(*this) += b; }
    PolyMod operator - (const PolyMod &b) const { return PolyMod(*this) -= b; }
    PolyMod operator * (const PolyMod &b) const { return PolyMod(*this) *= b; }
    PolyMod operator / (const PolyMod &b) const { return PolyMod(*this) /= b; }
    PolyMod operator % (const PolyMod &b) const { return PolyMod(*this) %= b; }
};

constexpr int W = 2, MOD = 1999;
// constexpr int W = 13, MOD = 786433;
// constexpr int W = 2, MOD = 1030307;
// constexpr int W = 11, MOD = 9973;
// constexpr int W = 2, MOD = 99149;
using mint = MINT<MOD>;
using poly = PolyMod<W, MOD>;

mint kitamasa(poly c, poly a, ll n){
    poly d = vector<mint>{1};
    poly xn = vector<mint>{0, 1};
    poly f;
    if(a.size() > n) return a[n];
    for(int i=0; i<c.size(); i++) f.push_back(-c[i]);
    f.push_back(1);
    while(n){
        if(n & 1) d = d * xn % f;
        n >>= 1; xn = xn * xn % f;
    }
    mint ret = 0;
    for(int i=0; i<=a.deg(); i++) ret += a[i] * d[i];
    return ret;
}

int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    ll N, M;
    cin >> N >> M;
    vector<mint> v_dp(N), v_rec(N);
    rep(i, 0, N - 1) v_dp[i] = mint(2).pow(i);
    v_dp[N - 1] = mint(2).pow(N) - mint(1);
    rep(i, 0, N - 1) v_rec[i] = 1;
    v_rec[N - 1] = mint(2).pow(N - 1);
    reverse(all(v_rec));
    poly dp(v_dp), rec(v_rec);
    cout << kitamasa(v_rec, v_dp, M - 1) << endl;
}
