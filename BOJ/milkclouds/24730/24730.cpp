#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define rep2(i,a,b) for(int i = (b) - 1; i >= (a); i--)
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define IDX(v, x) (lower_bound(all(v), x) - v.begin())
using namespace std;

using uint = unsigned;
using ll = long long;
using ull = unsigned long long;

template<int _M = 1000000007, int _W = 5>
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
using mint = MINT<>;
using poly = vector<mint>;
poly divide(poly& a, mint b){
    vector<mint> ret;
    rep2(i, 1, a.size()){
        ret.push_back(a[i]);
        if(i) a[i - 1] += a[i] * b;
    }
    reverse(all(ret));
    return ret;
}
mint eval(poly P, int i){
    mint tmp = 1, ret = 0;
    for(int idx = 0; idx < P.size(); idx++){
        ret += P[idx] * tmp;
        tmp *= i;
    }
    return ret;
}

ll N, t;
vector<mint> f;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    f.resize(N + 1);
    rep(i, 0, N + 1) {cin >> t; f[i] = t;}
    poly P(f);
    cout << "GGG<" << f[0];
    rep(i, 1, N + 1){
        P = divide(P, i - 1);
        for(auto& j: P) j *= i;
        mint ret = eval(P, i);
        cout << "," << ret;
    }
    cout << ">";
}