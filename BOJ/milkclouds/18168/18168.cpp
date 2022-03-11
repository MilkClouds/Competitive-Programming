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

template<int _M = 998244353, int _W = 3>
struct MINT{
    static const int M = _M;
    static const int W = _W;
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

// T: field
namespace fft{
    template<typename T = MINT<>>
    static void NTT(vector<T> &f, bool inv_fft = false){
        int N = f.size();
        vector<T> root(N >> 1);
        for(int i=1, j=0; i<N; i++){
            int bit = N >> 1;
            while(j >= bit) j -= bit, bit >>= 1;
            j += bit;
            if(i < j) swap(f[i], f[j]);
        }
        T ang = pw(T(T::W), (T::M-1)/N); if(inv_fft) ang = inv(ang);
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
    template<typename T = MINT<>>
    vector<T> multiply_ntt(vector<T> a, vector<T> b){
        int N = 2; while(N < a.size() + b.size()) N <<= 1;
        a.resize(N); b.resize(N);
        NTT<T>(a); NTT<T>(b);
        for(int i=0; i<N; i++) a[i] *= b[i];
        NTT<T>(a, true);
        return a;
    }
}

// T: field
template<typename T = MINT<>>
struct PolyMod{
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

    T eval(const T x){
        T tmp = T(1), ans = T(0);
        for(auto &i: a){
            ans += i * tmp;
            tmp *= x;
        }
        return ans;
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
        *this = fft::multiply_ntt<T>(a, b.a);
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

// @param n `0 <= n`
// @return minimum non-negative `x` s.t. `n <= 2**x`
int ceil_pow2(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}
template <class S, S (*op)(S&, S&), S (*e)()> struct segtree {
  public:
    segtree() : segtree(0) {}
    explicit segtree(int n) : segtree(std::vector<S>(n, e())) {}
    explicit segtree(const std::vector<S>& v) : _n(int(v.size())) {
        log = ceil_pow2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) const {
        assert(0 <= p && p < _n);
        return d[p + size];
    }

    S prod(int l, int r) const {
        assert(0 <= l && l <= r && r <= _n);
        S sml = e(), smr = e();
        l += size;
        r += size;

        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }

    S all_prod() const { return d[1]; }

    template <bool (*f)(S)> int max_right(int l) const {
        return max_right(l, [](S x) { return f(x); });
    }
    template <class F> int max_right(int l, F f) const {
        assert(0 <= l && l <= _n);
        assert(f(e()));
        if (l == _n) return _n;
        l += size;
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!f(op(sm, d[l]))) {
                while (l < size) {
                    l = (2 * l);
                    if (f(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <bool (*f)(S)> int min_left(int r) const {
        return min_left(r, [](S x) { return f(x); });
    }
    template <class F> int min_left(int r, F f) const {
        assert(0 <= r && r <= _n);
        assert(f(e()));
        if (r == 0) return 0;
        r += size;
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!f(op(d[r], sm))) {
                while (r < size) {
                    r = (2 * r + 1);
                    if (f(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }
    int _n, size, log;
    std::vector<S> d;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};

using mint = MINT<>;
using poly = PolyMod<>;
poly S(poly& a, poly& b){return a * b;}
poly e(){return poly(1);}
using Seg = segtree<poly, S, e>;
Seg tree;
ll N, Q;
vector<mint> a, b;
void solve(int node, poly& P){
    if(tree.size <= node){
        if(node < tree.size + Q){
            cout << P[0] + P[1] * b[node - tree.size] << "\n";
        }
        return;
    }
    poly& Q = tree.d[node];
    poly&& R = P % Q;
    solve(node * 2, R);
    solve(node * 2 + 1, R);
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N >> Q;
    a.resize(N + 1); b.resize(Q);
    cinA(a, N + 1); cinA(b, Q);
    reverse(all(a));
    mint t = 1;
    vector<poly> v;
    rep(i, 0, Q){
        v.eb(poly({-b[i], 1}));
    }
    tree = Seg(v);
    poly aa = poly(a);
    solve(1, aa);
}
