#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i = (a); i < (b); i++)
#define rep2(i,a,b) for(ll i = (b) - 1; i >= (a); i--)
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

ll N, M, a, b, c, d;
long long poww(long long a, long long b) {
	long long ret = 1;
    a %= M;
	while (b) {
	    if (b & 1) ret *= a;
		a *= a;
		a %= M;
		ret %= M;
		b >>= 1;
	}
	return ret;
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> M >> N;
    while(N--){
        cin >> a >> b >> c >> d;
        ll norm = a * a + b * b + c * c + d * d;
        ll inv = poww(norm, M - 2);
        a = (a * inv) % M;
        b = (-b * inv) % M;
        c = (-c * inv) % M;
        d = (-d * inv) % M;
        b < 0 ? b += M : 0; c < 0 ? c += M : 0; d < 0 ? d += M : 0;
        if(norm * inv % M == 1) cout << a << " " << b << " " << c << " " << d << "\n";
        else cout << "0 0 0 0\n";
    }
}
