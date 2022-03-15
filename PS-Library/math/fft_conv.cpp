#include <bits/stdc++.h>
using namespace std;

/*
ll, without MOD.

*/

typedef complex<double> cpx;

void fft(vector<cpx>& a) {
    // https://github.com/kth-competitive-programming/kactl/blob/master/content/numerical/FastFourierTransform.h
    int n = a.size(), L = 31 - __builtin_clz(n);
    static vector<cpx> R(2, 1);
    static vector<cpx> rt(2, 1);
    for (static int k = 2; k < n; k *= 2) {
        R.resize(n); rt.resize(n);
        auto x = polar(1.0, acos(-1.0) / k);
        for (int i = k; i < 2 * k; i++) rt[i] = R[i] = i&1 ? R[i/2] * x : R[i/2];
    }
    vector<int> rev(n);
    for (int i = 0; i < n; i++) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
    for (int i = 0; i < n; i++) if (i < rev[i]) swap(a[i], a[rev[i]]);
    for (int k = 1; k < n; k *= 2) {
        for (int i = 0; i < n; i += 2 * k) {
            for (int j = 0; j < k; j++) {
                auto x = (double *)&rt[j+k], y = (double *)&a[i+j+k];
                cpx z(x[0]*y[0] - x[1]*y[1], x[0]*y[1] + x[1]*y[0]);
                a[i + j + k] = a[i + j] - z;
                a[i + j] += z;
            } 
        }
    }
}

vector<ll> conv(const vector<ll>& a, const vector<ll>& b) {
    if (a.empty() || b.empty()) return {};
    vector<ll> res(a.size() + b.size() - 1);
    int L = 32 - __builtin_clz(res.size()), n = 1 << L;
    vector<cpx> in(n), out(n);
    copy(a.begin(), a.end(), begin(in));
    for (size_t i = 0; i < b.size(); i++) in[i].imag(b[i]);
    fft(in);
    for (cpx& x : in) x *= x;
    for (int i = 0; i < n; i++) out[i] = in[-i & (n - 1)] - conj(in[i]);
    fft(out);
    // for (size_t i = 0; i < res.size(); i++) res[i] = imag(out[i]) / (4 * n);
    for (size_t i = 0; i < res.size(); i++) res[i] = round(imag(out[i]) / (4 * n));
    // for (size_t i = 0; i < res.size(); i++) res[i] = (ll) round(imag(out[i]) / (4 * n)) % MOD; // for MOD
    return res;
}



/*
double
BOJ 22289번 기준
아래 소스코드: 656ms
AtCoder Library convolution_ll: 832ms
*/

typedef double f_t;
typedef complex<f_t> C;

void fft(vector<C>& a) {
    // https://github.com/kth-competitive-programming/kactl/blob/master/content/numerical/FastFourierTransform.h
    int n = a.size(), L = 31 - __builtin_clz(n);
    static vector<C> R(2, 1);
    static vector<C> rt(2, 1);
    for (static int k = 2; k < n; k *= 2) {
        R.resize(n); rt.resize(n);
        auto x = polar((f_t) 1.0, acos((f_t) -1.0) / k);
        for (int i = k; i < 2 * k; i++) rt[i] = R[i] = i&1 ? R[i/2] * x : R[i/2];
    }
    vector<int> rev(n);
    for (int i = 0; i < n; i++) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
    for (int i = 0; i < n; i++) if (i < rev[i]) swap(a[i], a[rev[i]]);
    for (int k = 1; k < n; k *= 2) {
        for (int i = 0; i < n; i += 2 * k) {
            for (int j = 0; j < k; j++) {
                auto x = (f_t *)&rt[j+k], y = (f_t *)&a[i+j+k];
                C z(x[0]*y[0] - x[1]*y[1], x[0]*y[1] + x[1]*y[0]);
                a[i + j + k] = a[i + j] - z;
                a[i + j] += z;
            } 
        }
    }
}

vector<f_t> conv(const vector<f_t>& a, const vector<f_t>& b) {
    if (a.empty() || b.empty()) return {};
    vector<f_t> res(a.size() + b.size() - 1);
    int L = 32 - __builtin_clz(res.size()), n = 1 << L;
    vector<C> in(n), out(n);
    copy(a.begin(), a.end(), begin(in));
    for (size_t i = 0; i < b.size(); i++) in[i].imag(b[i]);
    fft(in);
    for (C& x : in) x *= x;
    for (int i = 0; i < n; i++) out[i] = in[-i & (n - 1)] - conj(in[i]);
    fft(out);
    for (size_t i = 0; i < res.size(); i++) res[i] = imag(out[i]) / (4 * n);
    return res;
}

vector<ll> multiply(vector<ll>& a, vector<ll>& b){
    auto&& A = vector<f_t>(all(a));
    auto&& B = vector<f_t>(all(b));
    auto&& tmp = conv(A, B);
    auto&& ret = vector<ll>(tmp.size());
    for(int i = 0; i < tmp.size(); i++) ret[i] = round(tmp[i]);
    return ret;
}

/*
------------------------------------------------------------
아래는 kks227님의 구현 참고, 위 소스보드 느림.
*/

const double PI = acos(-1);
typedef complex<double> cpx;

// non-recursive. slower than recursive function :(
void fft(vector<cpx> &f, cpx w_1){
	int n = 1, l = 0;
	while (n < f.size()) n <<= 1, l++;
	vector<cpx> ws(l); ws[0] = w_1;
	for(int i = 1; i < l; i++) ws[i] = ws[i - 1] * ws[i - 1];
	for(int i = 1; i <= l; i++){
		vector<cpx> ff(n);
		int bias = n >> i;
		for(int j = 0; j < bias; j++){
			int n = 1 << i;
			cpx wp = 1, w = ws[l - i];
			for(int k = 0; k < (n >> 1); k++){
				int l = k * bias;
				ff[j + l] = f[j + l * 2] + wp * f[j + l * 2 + bias];
				ff[j + l + bias * (n >> 1)] = f[j + l * 2] - wp * f[j + l * 2 + bias];
				wp *= w;
			}
		}
		f.swap(ff);
	}
}

vector<cpx> conv(vector<cpx> a, vector<cpx> b) {
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

vector<ll> multiply(vector<ll>& a, vector<ll>& b){
    auto&& A = vector<cpx>(all(a));
    auto&& B = vector<cpx>(all(b));
    auto&& tmp = conv(A, B);
    auto&& ret = vector<ll>(tmp.size());
    for(int i = 0; i < tmp.size(); i++) ret[i] = round(tmp[i].real());
    return ret;
}


// recursive version
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



// ==============================================================
/* FFT Library : Originally Written by Myungwoo * * https://blog.myungwoo.kr/54 * * Nonrecursive, Bit-Flipping Trick * * Several Modifications */
#define sz(v)((int)(v).size())
typedef complex<double> base;
typedef vector<int> vi;
typedef vector<base> vb;
const double PI = acos(-1);
void fft(vector<base>& a, bool inv = false) {
    int n = (int) a.size();
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j >= bit; bit >>= 1) j -= bit;
        j += bit;
        if (i < j) swap(a[i], a[j]);
    }
    vector < base > root(n / 2);
    double ang = 2 * acos(-1) / n * (inv ? -1 : 1);
    for (int i = 0; i < n / 2; i++) root[i] = base(cos(ang * i), sin(ang * i));
    for (int idx = 2; idx <= n; idx <<= 1) {
        int step = n / idx;
        for (int i = 0; i < n; i += idx) {
            for (int j = 0; j < idx / 2; j++) {
                base u = a[i + j], v = a[i + j + idx / 2] * root[step * j];
                a[i + j] = u + v;
                a[i + j + idx / 2] = u - v;
            }
        }
    }
    if (inv) {
        for (auto & i: a) i /= n;
    }
}
const int LARGE = 1e6; /* FFT polynomial Multiplication with higher precision */
void multiply(const vi& a,
    const vi & b, vi & res) {
    vector<base> fa_big, fb_big;
    vector<base> fa_small, fb_small;
    int cut_val = sqrt(LARGE);
    int n = 1;
    while (n < max(sz(a), sz(b))) n <<= 1;
    fa_big.resize(n);
    fa_small.resize(n);
    fb_big.resize(n);
    fb_small.resize(n);
    for (int i = 0; i < sz(a); i++) {
        fa_big[i] = a[i] / cut_val;
        fa_small[i] = a[i] % cut_val;
    }
    for (int i = 0; i < sz(b); i++) {
        fb_big[i] = b[i] / cut_val;
        fb_small[i] = b[i] % cut_val;
    }
    fft(fa_big, 0), fft(fb_big, 0);
    fft(fa_small, 0), fft(fb_small, 0);
    vector < base > fa_big_2(all(fa_big));
    vector < base > fa_small_2(all(fa_small));
    for (int i = 0; i < n; i++) {
        fa_big_2[i] *= fb_big[i];
        fa_big[i] *= fb_small[i];
        fa_small[i] *= fb_small[i];
        fa_small_2[i] *= fb_big[i];
    }
    fft(fa_small, 1);
    fft(fa_small_2, 1);
    fft(fa_big, 1);
    fft(fa_big_2, 1);
    res.resize(n);
    for (int i = 0; i < n; i++) {
        int ss = (int64_t) round(fa_small[i].real());
        int sb = (int64_t) round(fa_small_2[i].real());
        int bs = (int64_t) round(fa_big[i].real());
        int bb = (int64_t) round(fa_big_2[i].real());
        res[i] = ss;
        res[i] += (sb + bs) * cut_val;
        res[i] += bb * cut_val * cut_val;
    }
}