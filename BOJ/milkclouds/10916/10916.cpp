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

const int MAX = 1000002, INF = 2e9;
vector<int> pn;
int sp[MAX], phi[MAX];
ll phiS[MAX];
ll pw(ll a, ll b){
    ll ret = 1;
    for(; b; b >>= 1, a *= a) if(b & 1) ret *= a;
    return ret;
}
template<int M = 1000000007>
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
// https://ahgus89.github.io/algorithm/Linear-sieve/
// https://ahgus89.github.io/algorithm/Notation/
void sieve(){
    phi[1] = 1;
    for(int i = 2; i < MAX; i++){
        if(!sp[i]){
            pn.push_back(i);
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
    for(int i = 1; i < MAX; i++) phiS[i] = phiS[i - 1] + phi[i];
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    sieve();
    pn.clear();
    {
        int K, LIM = INF;
        cin >> K;
        vector<int> A(K), B(K);
        rep(i, 0, K) cin >> A[i] >> B[i], LIM = min(LIM, B[i]);
        int sq = sqrt(LIM);
        MINT ret = 0;
        vector<pi> events;
        rep(j, 0, K){
            for(auto M: {--A[j], B[j]}){
                if(M == 0) continue;
                int i = 1, k;
                do{
                    k = M / (M / i);
                    i = k + 1;
                    if(i > LIM) break;
                    if(i > sq) events.eb(i, j);
                } while(i <= M);
            }
        }
        sort(all(events));
        events.erase(unique(all(events)), events.end());
        MINT tmp = 1;
        int last = sq, zeros = 0;
        for(int k = 1; k < sq; k++){
            tmp = 1;
            rep(j, 0, K) tmp *= B[j] / k - A[j] / k;
            ret += MINT(phi[k]) * tmp;
        }
        tmp = 1;
        rep(j, 0, K) B[j] / sq - A[j] / sq ? (tmp *= B[j] / sq - A[j] / sq) : MINT(zeros++);
        for(auto pos = events.begin(); pos != events.end();){
            int k = pos->x;
            ret += (zeros ? MINT(0) : tmp) * MINT(phiS[k - 1] - phiS[last - 1]);
            for(; events.end() != pos && pos->x == k; pos++){
                int j = pos->y;
                B[j] / last - A[j] / last ? (tmp /= B[j] / last - A[j] / last) : MINT(zeros--);
                B[j] / k - A[j] / k ? (tmp *= B[j] / k - A[j] / k) : MINT(zeros++);
            }
            last = k;
        }
        ret += (zeros ? MINT(0) : tmp) * MINT(phiS[LIM] - phiS[last - 1]);
        cout << ret << "\n";
    }
}
