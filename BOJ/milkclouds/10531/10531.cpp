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


// 7:22~8:00

const double PI = acos(-1);
typedef complex<double> cpx;

void fft(vector<cpx> &f, cpx w) {
	int n = f.size();
	if (n == 1) return;
	vector<cpx> even(n >> 1), odd(n >> 1);
	for (int i = 0; i < n; i++) { (i & 1 ? odd : even)[i / 2] = f[i]; }
	fft(even, w * w); fft(odd, w * w);
	cpx wp(1, 0);
	for (int i = 0; i < n / 2; i++) {
		f[i] = even[i] + wp * odd[i];
		f[i + n / 2] = even[i] - wp * odd[i];
		wp *= w;
	}
}
vector<cpx> mul_fft(vector<cpx> a, vector<cpx> b) {
	int n = 1;
	while (n <= a.size() || n <= b.size()) n <<= 1;
	n <<= 1;
	a.resize(n); b.resize(n); vector<cpx> c(n);
	cpx w(cos(2 * PI / n), sin(2 * PI / n));
	fft(a, w); fft(b, w);
	for (int i = 0; i < n; i++) c[i] = a[i] * b[i];
	fft(c, cpx(w.real(), -w.imag()));
	for (int i = 0; i < n; i++) {
		c[i] /= cpx(n, 0);
		c[i] = cpx(round(c[i].real()), round(c[i].imag()));
	}
	return c;
}

int N, M, u, cnt;
vector<cpx> a(200001);

int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N;
    a[0] = 1;
    rep(i, 0, N){
        cin >> u;
        a[u] = 1;
    }
    auto&& b = mul_fft(a, a);
    cin >> M;
    while(M--){
        cin >> u;
        cnt += b[u].real() != 0;
    }
    cout << cnt << endl;
}
