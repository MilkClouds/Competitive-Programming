#include <bits/stdc++.h>
#include <atcoder/segtree>
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
matrix& operator *= (matrix &a, matrix &b){
    return a = a * b;
}
matrix I{{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}};
matrix op(matrix a, matrix b){return b * a;}
matrix e(){return I;}
using segtree = atcoder::segtree<matrix, op, e>;
unordered_map<ll, matrix> save, sv;
matrix poww (matrix& a, ll N){
    if(save.count(N)) return save[N];
    matrix ret = e();
    if(N == 0) return e();
    matrix&& tmp = poww(a, N / 2);
    return save[N] = (tmp * tmp) * (N % 2 ? a : I) ;
}
matrix base{{{1, 1, 0}, {1, 0, 0}, {0, 0, 1}}};

const int MAX = 1e5;
ll N, Q, A[MAX], sz;
vector<ll> V;
mi<ll> ans, B[MAX];
map<ll, ll> M;
vector<matrix> X;
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N >> Q;
    rep(i, 0, Q){
        cin >> A[i] >> B[i];
        V.pb(A[i]);
    }
    sort(all(V));
    V.erase(unique(all(V)), V.end());
    M[1] = sz++;
    for(auto i: V) M[i] = sz++;
    M[N] = sz++;
    ll t = 1;
    for(auto [i, j]: M){
        if(i == t){
            X.pb(e());
            continue;
        }
        sv[i] = poww(base, i - t - 1);
        X.eb(base * sv[i]);
        t = i;
    }
    segtree tree(X);
    rep(i, 0, Q){
        tree.set(M[A[i]], matrix{{{0, 0, B[i]}, {1, 0, 0}, {0, 0, 1}}} * sv[A[i]]);
        auto&& ret = tree.prod(0, sz);
        cout << ret[0][0] + ret[0][2] << "\n";
    }
}