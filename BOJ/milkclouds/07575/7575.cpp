# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define rep2(i,a,b) for(int i = (b) - 1; i >= (a); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define pb push_back
#define eb emplace_back
#define em emplace
#define popcount __builtin_popcount
#define popcountll __builtin_popcountll
#define x first
#define y second
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using pl = pair<ll, ll>;
using tl = tuple<ll, ll, ll>;

const int PN = 2;
const vector<ll> primes = {1000000009, 400009};
const vector<ll> SHIFT = {16, 32};
vector<ll> inv(PN);

int N, M;
map<array<ll, PN>, int> MM;
struct ABC{
    int N;
    vector<ll> A;
    vector<array<ll, PN>> B;
} A;
istream& operator >> (istream& is, ABC& A){
    is >> A.N;
    A.A.resize(A.N);
    rep(i, 0, A.N) is >> A.A[i];
    return is;
}
long long pow(long long a, long long b, long long MOD) {
	long long ret = 1;
	while (b) {
	if (b & 1) ret *= a;
		a *= a;
		a %= MOD;
		ret %= MOD;
		b >>= 1;
	}
	return ret;
}
array<ll, PN> myhash(int l, int r){
    array<ll, PN> ret;
    ret.fill(0);
    rep(k, 0, PN) {
        ret[k] = (A.B[r][k] - A.B[l][k]) * pow(inv[k], A.N - r, primes[k]) % primes[k];
        if(ret[k] < 0) ret[k] += primes[k];
    }
    return ret;
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N >> M;
    A.A.reserve(1111);
    A.B.reserve(1111);
    rep(k, 0, PN) inv[k] = pow(SHIFT[k], primes[k] - 2, primes[k]);
    rep(i, 0, N){
        cin >> A;
        A.B.resize(A.N + 1);
        A.B[0].fill(0);

        rep(j, 1, A.N + 1) rep(k, 0, PN) A.B[j][k] = (pow(SHIFT[k], A.N - j, primes[k]) * A.A[j - 1] + A.B[j - 1][k]) % primes[k];
        set<array<ll, PN>> tmp;
        rep(j, 0, A.N - M + 1) tmp.insert(myhash(j, j + M));

        reverse(all(A.A));

        rep(j, 1, A.N + 1) rep(k, 0, PN) A.B[j][k] = (pow(SHIFT[k], A.N - j, primes[k]) * A.A[j - 1] + A.B[j - 1][k]) % primes[k];
        rep(j, 0, A.N - M + 1) tmp.insert(myhash(j, j + M));
        for(auto& v: tmp) MM[v]++;
    }
    for(auto& [k, v] : MM) if(v == N) {
        cout << "YES\n";
        return 0;
    }
    cout << "NO\n";
}

